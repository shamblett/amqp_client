amqpc_client
===

The amqpc_client Dart package allows server side Dart implementations to act as an
AMQP messaging client. 

The package comprises of a Dart library and native extension providing the following
AMQP functions :-

  - Synchronous direct message transfer using exchange based queues
  - Synchronous local queue message transfer
  - Asynchronous message reception using a listener interface

The native client extension wraps the Apache [QPID] [1]  messaging client libraries giving a rich AMQPC client interface.

Please refer to the Install documents for building the native client and the Test document for running the unit test suite.

The package itself was developed on a Fedora 20 platform for RHEL 7 targetting, however the client has also successfully 
been built and run on a Debian 7 GCE instance. 

> Note : Linux only, Windows is not supported.

Version
----

1.0


License
----

GPLV3


**Free Software, Hell Yeah!**

[1]:http://qpid.apache.org/

    