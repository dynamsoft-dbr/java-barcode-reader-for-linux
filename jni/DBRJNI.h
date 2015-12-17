#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "/home/xiao/Dynamsoft/BarcodeReader4.0/Include/If_DBR.h"

/* Header for class com_dynamsoft_DBRJNI */

#ifndef _Included_com_dynamsoft_DBRJNI
#define _Included_com_dynamsoft_DBRJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_dynamsoft_DBRJNI
 * Method:    initializeLicense
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_dynamsoft_DBRJNI_initializeLicense
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_dynamsoft_DBRJNI
 * Method:    readBarcode
 * Signature: (Ljava/lang/String;)Ljava/util/ArrayList;
 */
JNIEXPORT jobject JNICALL Java_com_dynamsoft_DBRJNI_readBarcode
  (JNIEnv *, jobject, jstring);

#ifdef __cplusplus
}
#endif
#endif
