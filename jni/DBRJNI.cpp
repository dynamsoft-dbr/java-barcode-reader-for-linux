#include "DBRJNI.h"

const char * GetFormatStr(__int64 format)
{
	if (format == CODE_39)
		return "CODE_39";
	if (format == CODE_128)
		return "CODE_128";
	if (format == CODE_93)
		return "CODE_93";
	if (format == CODABAR)
		return "CODABAR";
	if (format == ITF)
		return "ITF";
	if (format == UPC_A)
		return "UPC_A";
	if (format == UPC_E)
		return "UPC_E";
	if (format == EAN_13)
		return "EAN_13";
	if (format == EAN_8)
		return "EAN_8";
	if (format == INDUSTRIAL_25)
		return "INDUSTRIAL_25";
	if (format == QR_CODE)
		return "QR_CODE";
	if (format == PDF417)
		return "PDF417";
	if (format == DATAMATRIX)
		return "DATAMATRIX";

	return "UNKNOWN";
}

JNIEXPORT jint JNICALL Java_com_dynamsoft_DBRJNI_initializeLicense(JNIEnv *env,
		jobject obj, jstring license)
{
	const char *pszLicense = env->GetStringUTFChars(license, 0);

	int ret = DBR_InitLicense(pszLicense);

	// release license native string
	env->ReleaseStringUTFChars(license, pszLicense);

	return ret;
}

JNIEXPORT jobject JNICALL Java_com_dynamsoft_DBRJNI_readBarcode(JNIEnv *env,
		jobject obj, jstring fileName)
{
	const char *pszFileName = env->GetStringUTFChars(fileName, 0);

	__int64 llFormat = OneD | QR_CODE | PDF417 | DATAMATRIX;
	int iMaxCount = 0x7FFFFFFF;
	ReaderOptions ro = { 0 };
	ro.llBarcodeFormat = llFormat;
	ro.iMaxBarcodesNumPerPage = iMaxCount;
	pBarcodeResultArray paryResult = NULL;

	int iRet = DBR_DecodeFile(pszFileName, &ro, &paryResult);
	if (iRet != DBR_OK) {
		printf("Failed to read barcode: %s\n", DBR_GetErrorString(iRet));
		return NULL;
	}

	if (paryResult->iBarcodeCount == 0)
		{
			printf("No barcode found");
			DBR_FreeBarcodeResults(&paryResult);
			return 0;
		}

	for (int iIndex = 0; iIndex < paryResult->iBarcodeCount; iIndex++)
		{
			printf("Barcode %d:\n", iIndex + 1);
			printf("    Page: %d\n", paryResult->ppBarcodes[iIndex]->iPageNum);
			printf("    Type: %s\n", GetFormatStr(paryResult->ppBarcodes[iIndex]->llFormat));
			printf("    Value: %s\n", paryResult->ppBarcodes[iIndex]->pBarcodeData);
			printf("    Region: {Left: %d, Top: %d, Width: %d, Height: %d}\n\n",
				paryResult->ppBarcodes[iIndex]->iLeft, paryResult->ppBarcodes[iIndex]->iTop,
				paryResult->ppBarcodes[iIndex]->iWidth, paryResult->ppBarcodes[iIndex]->iHeight);
		}

		DBR_FreeBarcodeResults(&paryResult);

// release filename native string
	env->ReleaseStringUTFChars(fileName, pszFileName);

	return NULL;
}
