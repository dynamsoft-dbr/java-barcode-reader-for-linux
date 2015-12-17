CC=gcc 
CCFLAGS=-c -Wall -Werror -fpic -lstdc++
JNI_INCLUDE=/usr/lib/jvm/java-7-openjdk-amd64/include
CLASS_PATH=../bin
#DBRLIB_PATH=~/Dynamsoft/BarcodeReader4.0/Redist
#LDFLAGS=-L$(DBRLIB_PATH) -Wl,-rpath=$(DBRLIB_PATH)

ifeq ($(shell getconf LONG_BIT), 32)
	DBRLIB=-lDynamsoftBarcodeReaderx86
	LIBNAME=libDynamsoftBarcodeReaderx86.so
else
	DBRLIB=-lDynamsoftBarcodeReaderx64
	LIBNAME=libDynamsoftBarcodeReaderx64.so
endif

TARGET=libdbr.so
OBJECT=DBRJNI.o
SOURCE=DBRJNI.cpp

$(TARGET): $(OBJECT)
	$(CC) -shared -o $(TARGET) $(OBJECT) $(LDFLAGS) $(DBRLIB)
	$(shell sudo ln -s ~/Dynamsoft/BarcodeReader4.0/Redist/$(LIBNAME) /usr/lib/$(LIBNAME))

$(OBJECT): $(SOURCE)
	$(CC) $(CCFLAGS) -I$(JNI_INCLUDE) $(SOURCE) 
#DBRJNI.h : 
#	javah -o DBRJNI.h -classpath $(CLASS_PATH) com.dynamsoft.DBRJNI

# the clean target
.PHONY : clean
clean: 
	sudo rm -f $(OBJECT) $(TARGET) /usr/lib/$(LIBNAME)
	

