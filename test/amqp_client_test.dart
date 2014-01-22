

library amqp_client_test;

import '../lib/amqp_client.dart';
import 'package:unittest/unittest.dart';  

main() {  
  
  
  /* Tests */
  
  /* Edit per your platform, these are Qpid defaults */
  ConnectionSettings testSettings = new ConnectionSettings();
  testSettings.bounds = 2;
  testSettings.heartbeat = 0;
  testSettings.locale = "en_US";
  testSettings.maxChannels = 32767;
  testSettings.maxFrameSize = 65535;
  testSettings.maxSsf = 256;
  testSettings.minSsf = 0;
  testSettings.mechanism = "";
  testSettings.password = "";
  testSettings.protocol = "tcp";
  testSettings.service = "qpidd";
  testSettings.sslCertName = "";
  testSettings.tcpNoDelay = true;
  testSettings.username = "anonymous";
  
  /* Group 1 - Connection Tests */
  group("1. Connection Tests - ", () {
    
    test("Open Host", () {  
      
      Connection myConnection = new Connection();
      bool result = myConnection.openHost("localhost");
      expect(result, isTrue);
      expect(myConnection.isOpen(), isTrue);
      myConnection.close();
      
    });
    
    test("Close Host", () {  
      
      Connection myConnection = new Connection();
      bool result = myConnection.openHost("localhost");
      expect(result, isTrue);
      myConnection.close();
      expect(myConnection.isOpen(), isFalse);
      
      
    });
    
    test("Open Url", () {  
      
      Connection myConnection = new Connection();
      bool result = myConnection.openUrl("qpid:@tcp:localhost");
      expect(result, isTrue);
      expect(myConnection.isOpen(), isTrue);
      myConnection.close();
      
    });
    
    test("Close Url", () {  
      
      Connection myConnection = new Connection();
      bool result = myConnection.openUrl("qpid:@tcp:localhost");
      expect(result, isTrue);
      myConnection.close();
      expect(myConnection.isOpen(), isFalse);
      
      
    });
    
    
    test("Multiple Connections", () {  
      
      Connection myConnection1 = new Connection();
      Connection myConnection2 = new Connection();
      bool result = myConnection1.openUrl("qpid:@tcp:localhost");
      expect(result, isTrue);
      result = myConnection2.openUrl("qpid:@tcp:localhost");
      expect(result, isTrue);
      myConnection2.close();
      expect(myConnection1.isOpen(), isTrue);
      expect(myConnection2.isOpen(), isFalse);
      myConnection1.close();
      expect(myConnection1.isOpen(), isFalse);
      
    });
    
    solo_test("Open Url Settings", () {  
      
      Connection myConnection = new Connection();
      testSettings.virtualHost = "fred";
      bool result = myConnection.openUrlSettings("qpid:@tcp:localhost",
                                                 testSettings);
      expect(result, isTrue);
      expect(myConnection.isOpen(), isTrue);
      ConnectionSettings reSettings = myConnection.getNegotiatedSettings();
      expect(reSettings.virtualHost, "fred");
      bool equals = false;
      if ( testSettings == reSettings ) equals = true; 
      expect(equals, isTrue);
      myConnection.close();
      
    });
    
  });
  
}
