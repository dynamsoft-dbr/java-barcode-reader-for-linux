package com.dynamsoft;

import java.util.ArrayList;

public class DBRJNI {
	static {
		System.loadLibrary("dbr");
	}

	public native int initializeLicense(String license);
	public native ArrayList<BarcodeResult> readBarcode(String fileName);

	public static void main(String[] args) {
		// invoke the native method
		DBRJNI barcodeReader = new DBRJNI();
		int ret = barcodeReader.initializeLicense("8916CB507C382310B6BC78FDC104B93E");
		System.out.println("Initialize license: " + ret);
		
		barcodeReader.readBarcode("/home/xiao/Dynamsoft/BarcodeReader4.0/Images/AllSupportedBarcodeTypes.tif");
		
	}
}
