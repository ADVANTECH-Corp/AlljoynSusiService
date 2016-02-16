# AlljoynSusiService
Advantech implements an Alljoyn service sample for SUSI APIs. It uses AllJoyn Thin Core Library (AJTCL), so that you can apply it on both embedded systems and general-purpose devices.

This Alljoyn application supports 
- About Announcement
- ControlPanel service
- Event & Action

##Build Sample
1. Follow [the page](https://wiki.allseenalliance.org/develop/downloading_the_source) to get Alljoyn source code, or directly download from [Alljoyn Download](https://allseenalliance.org/framework/download).

	**Note:** We use **v14.12** for SUSI Alljoyn service application.

2. Set $AJ_ROOT

	``` bash
	$ export AJ_ROOT=`pwd`
	```

3. Get [Alljoyn SUSI Service source code](https://github.com/ADVANTECH-Corp/AlljoynSusiService) and put it under *$AJ_ROOT/services/base_tcl/sample_apps*

4. Set environment variables (Cross-Compiler & SUSI4 lib path)

	``` bash
	$ export CROSS_PATH=/opt/poky/1.5.1/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi
	$ export CROSS_PREFIX=arm-poky-linux-gnueabi-
	// Set your SUSI4 lib path
	$ export SUSI4_PATH=/home/root/Projects/SUSI_4.0/Library/DllSusi4
	```

5. Build Thin Core Library

	``` bash
	$ cd $AJ_ROOT/core/ajtcl
	$ scons WS=off TARG=linux
	```

6. Build SUSI service

	``` bash
	$ cd $AJ_ROOT/services/base_tcl/sample_apps/SusiService
	$ scons WS=off TARG=linux AJ_TCL_ROOT=$AJ_ROOT/core/ajtcl
	```

##Run Sample
After building, you can get the application binary named SusiService in **build** folder. Just copy it into your device and execute it!

About verification tools, you can use these two APK on Android system.

- [ControlPanelBrowser.apk](https://allseenalliance.org/releases/alljoyn/14.12/alljoyn-controlpanel-service-framework-14.12.00-android-sdk-rel.zip) is under *alljoyn-controlpanel-14.12.00-rel\tools\*

- [Event_Action_Browser.apk](https://allseenalliance.org/releases/alljoyn/14.12/alljoyn-14.12.00b-android-sdk-rel.zip) is under *alljoyn-14.12.00b-rel\cpp\samples\eventaction\Android\bin\*

Or use AllJoynExplorer on Windows 10.

- [IoT Explorer for AllJoyn (AllJoyn Explorer)](https://ms-iot.github.io/content/en-US/win10/AllJoyn.htm)

##Customization
To customize ControlPanel properties, you need to generate source codes from XML file again.

1. Modify **susi_services.xml** as your expected.
2. Copy susi_services.xml into ControlPanel tools folder.

	``` bash
	$ cp susi_services.xml $AJ_ROOT/services/base_tcl/controlpanel/tools/CPSAppGenerator/SampleXMLs/
	```

3. Run **generateCPSApp.py** to produce the Control Panel Generated code.

	``` bash
	$ cd $AJ_ROOT/services/base_tcl/controlpanel/tools/CPSAppGenerator
	$ python generateCPSApp.py -p [output folder] ./SampleXMLs/susi_services.xml
	```

4. Copy *ControlPanelGenerated.c* and *ControlPanelGenerated.h* from [output folder] to *$AJ_ROOT/services/base_tcl/sample_apps/SusiService* folder.
