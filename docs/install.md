Install
===

The native client source code can be found in the 'native' directory of the packages lib directory.
This is a standard Netbeans project folder which if you have Netbeans can just be imported, however if not it can built as a standalone project using 'make -f Makefile'.

It is assumed that along with the standard g++ tool chain the build platform has the qpid client libraries and development libraries installed. The names of these vary from platform to platform however they inavariably share common nomenclature such as 'client' and 'dev' or 'devel'

The specific development libraries needed are the client, messaging, common and types libraries along with the standard non development client libraries. Also The Boost library suite needs to be installed, version 53 or 54 will suffice.

Note that to perform the testing in the test suite you will also have to install the standard qpidd broker package, no dev packages for this are needed.

Once this is done the file  Makefile-Debug.mk in the nbproject directory should be edited to suit your development environment, specifically the include directives need to be updated so as to include the dart-sdk.

Once done just run 'make -f Makefile' in the client directory. 

The client has been built and tested successfully on both Fedora 20 and Debian 7 platforms.
Note that the code compiles without warnings on these platforms, if you see warnings please check them.

When built either link or copy the generated libamqp_extension.so library in the 'dist' folder to the 'so' folder of the lib directory.

Also note that the Dart error message :-

>cannot find extension library'file:///......amqp_client/lib/amqp_client.dart': error: line >10 pos 1: library handler failed import 'dart-ext:so/amqp_extension';

actually means that Dart couldn't find the library file, OR ONE OF ITS DEPENDANTS, this is important, your platform may not have a library installed that it depends on, or if it is installed it cannot be found. You can see this by running the 'strace' command before you invoke the package, e.g. if you are running the standard unit test suite, do this :-

> strace dart amqpc_client_test.dart

