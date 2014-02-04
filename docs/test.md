Test
==

Please read the Install document before testing this package.

The test scripts are to be found in the 'test' folder which contains the following :-

>amqpc_client_test.dart - standard unit test file
>amqpc_client_transfer_test - direct synchronous message transfer test
>amqpc_client_localqueue_test - as above but using local queues
>amqpc_client_listener_test - message reception using an asynchronous listener

These tests can be run in any order, however the standard unit tests should be run to first
to prove the AMQPC environment on the target box is working.

The tests all assume a QPID(or any AMQPC) broker is running on localhost and that the broker is set up to use anonymous access with no other security measures such as SASL etc.
On Fedora platforms the out of the box qpidd broker is set to allow this, on Debian the default setting is to not allow this, please consult the QPID docs on how to set up localhost access for qpidd. Note this may also vary on other platforms.

Note that the standard unit test suite will output various error looking mesages as it runs, this is expected, look for the 'all tests passed' string at the end of the tests to ascertain if the test suite ran OK.

The tests themselves show good examples of API usage and general message transfer and reception stratagies, these can be reffered to along with the official QPID documentation and adapted as needed.