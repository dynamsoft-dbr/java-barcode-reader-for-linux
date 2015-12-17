# Java Barcode Reader for Linux with JNI

The sample demonstrates how to quickly implement a Java Barcode Reader on Linux with DBR(Dynamsoft Barcode Reader) and JNI.

## Download & Installation

* [Dynamsoft Barcode Reader for Linux][1]
* [Eclipse for Linux][2] and [CDT][3]

## Getting Started
1. Import the source code to Eclipse.
2. Change directory to the **jni** folder. Edit **makefile** to change the DBR SDK folder path. For example, **~/Dynamsoft/BarcodeReader4.0**
3. Run command line to generate **libdbr.so**:
   ```
   make
   ```
4. Add the library path to run configurations:
    ![jni library path](http://www.codepool.biz/wp-content/uploads/2015/12/jni_lib_path.png)
5. Run the Java barcode program:
    ![barcode result](http://www.codepool.biz/wp-content/uploads/2015/12/jni_barcode_result.png)

[1]:http://labs.dynamsoft.com/linux-barcode-reader-overview.htm
[2]:https://www.eclipse.org/downloads/
[3]:https://eclipse.org/cdt/downloads.php
