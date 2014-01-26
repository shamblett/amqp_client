

library amqp_client_test;

import '../lib/amqp_client.dart';
import 'package:unittest/unittest.dart';  

main() {  
  
  
  /* Tests */
  
  /* Edit per your platform, these are Qpid defaults */
  AmqpcConnectionSettings testSettings = new AmqpcConnectionSettings();
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
      
      AmqpcConnection myConnection = new AmqpcConnection();
      bool result = myConnection.openHost("localhost");
      expect(result, isTrue);
      expect(myConnection.isOpen(), isTrue);
      myConnection.close();
      
    });
    
    test("Close Host", () {  
      
      AmqpcConnection myConnection = new AmqpcConnection();
      bool result = myConnection.openHost("localhost");
      expect(result, isTrue);
      myConnection.close();
      expect(myConnection.isOpen(), isFalse);
      
      
    });
    
    test("Open Url", () {  
      
      AmqpcConnection myConnection = new AmqpcConnection();
      bool result = myConnection.openUrl("qpid:@tcp:localhost");
      expect(result, isTrue);
      expect(myConnection.isOpen(), isTrue);
      myConnection.close();
      
    });
    
    test("Close Url", () {  
      
      AmqpcConnection myConnection = new AmqpcConnection();
      bool result = myConnection.openUrl("qpid:@tcp:localhost");
      expect(result, isTrue);
      myConnection.close();
      expect(myConnection.isOpen(), isFalse);
      
      
    });
    
    
    test("Multiple Connections", () {  
      
      AmqpcConnection myConnection1 = new AmqpcConnection();
      AmqpcConnection myConnection2 = new AmqpcConnection();
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
    
    test("Open Url Settings", () {  
      
      AmqpcConnection myConnection = new AmqpcConnection();
      testSettings.virtualHost = "fred";
      bool result = myConnection.openUrlSettings("qpid:@tcp:localhost",
                                                 testSettings);
      expect(result, isTrue);
      expect(myConnection.isOpen(), isTrue);
      AmqpcConnectionSettings reSettings = myConnection.getNegotiatedSettings();
      expect(reSettings.virtualHost, "fred");
      bool equals = false;
      if ( testSettings == reSettings ) equals = true; 
      expect(equals, isTrue);
      myConnection.close();
      
    });
    
    test("Open Settings", () {  
      
      AmqpcConnection myConnection = new AmqpcConnection();
      testSettings.virtualHost = "fred";
      testSettings.heartbeat = 5;
      testSettings.host = "localhost";
      bool result = myConnection.openSettings(testSettings);
      expect(result, isTrue);
      expect(myConnection.isOpen(), isTrue);
      AmqpcConnectionSettings reSettings = myConnection.getNegotiatedSettings();
      bool equals = false;
      if ( testSettings == reSettings ) equals = true; 
      expect(equals, isTrue);
      myConnection.close();
      
    });
    
    test("Get Session", () {  
      
      AmqpcConnection myConnection = new AmqpcConnection();
      bool result = myConnection.openHost("localhost");
      expect(result, isTrue);
      expect(myConnection.isOpen(), isTrue);
      AmqpcSession mySession = myConnection.newSession("SJH",0);
      myConnection.resume(mySession);
      myConnection.close();
      
    });
    
    test("Resume Session", () {  
      
      AmqpcConnection myConnection = new AmqpcConnection();
      bool result = myConnection.openHost("localhost");
      expect(result, isTrue);
      expect(myConnection.isOpen(), isTrue);
      AmqpcSession mySession = myConnection.newSession("SJH",0);
      myConnection.resume(mySession);
      myConnection.close();
     
      
    });
    
  });
  
  /* Group 2 - Uuid Tests */
  group("2. Uuid Tests - ", () {
    
    test("Construction", () {  
              
        AmqpcUuid myUuid = new AmqpcUuid(true);
                                         
        expect(myUuid, isNotNull);
      
    });
    
    test("Generate", () {  
              
        AmqpcUuid myUuid = new AmqpcUuid(true);
        myUuid.generate();
        expect(myUuid.toString().length,36);
        print(myUuid);
      
    });
    
    test("Clear", () {  
              
        AmqpcUuid myUuid = new AmqpcUuid(true);
        myUuid.generate();
        expect(myUuid.toString().length,36);
        print(myUuid);
        myUuid.clear();
        expect(myUuid.toString(), "00000000-0000-0000-0000-000000000000");
        print(myUuid);
      
    });
    
    test("Is Null", () {  
              
        AmqpcUuid myUuid = new AmqpcUuid(true);
        myUuid.generate();
        expect(myUuid.toString().length,36);
        print(myUuid);
        myUuid.clear();
        expect(myUuid.toString(), "00000000-0000-0000-0000-000000000000");
        expect(myUuid.isNull(), isTrue);
      
    });
    
    
    
    
  });
  
  /* Group 3 - Message Tests */
  group("3. Message Tests - ", () {
    
    test("Construction", () {  
      
             
        AmqpcMessage myMessage = new AmqpcMessage("This is the message body",
                                                "SJH");
        expect(myMessage, isNotNull);
      
    });
    
    test("Equality", () {  
      
      AmqpcMessage myMessage = new AmqpcMessage("This is the message body",
                                                "SJH");
      bool equal = false;
      if ( myMessage == myMessage ) equal = true;
      expect(equal, isTrue);
      
      AmqpcMessage myOtherMessage = new AmqpcMessage("This is the message body again",
                                                     "SJH1");
      equal = false;
      if ( myMessage == myOtherMessage ) equal = true;
      expect(equal, isFalse);
      
    });
    
    test("Get Data", () {  
      
      AmqpcMessage myMessage = new AmqpcMessage("This is the message body",
                                                "SJH");
      String body = myMessage.data;
      expect(body, "This is the message body");
      
    });
    
    test("Set Data", () {  
      
      AmqpcMessage myMessage = new AmqpcMessage("This is the message body",
                                                "SJH");
      myMessage.data = "The New Body";
      String body = myMessage.data;
      expect(body, "The New Body");
      
    });
    
    test("Swap", () {  
      
      AmqpcMessage mySwap1 = new AmqpcMessage("This is mySwap1",
                                              "SJH");
      AmqpcMessage mySwap2 = new AmqpcMessage("This is mySwap2",
                                               "SJH");
      mySwap1.swap(mySwap2);
      String bodySwap1 = mySwap1.data;
      String bodySwap2 = mySwap2.data;
      expect(bodySwap1, "This is mySwap2");
      expect(bodySwap2, "This is mySwap1");
      
    });
    
    test("Append Data", () {  
      
      AmqpcMessage myMessage = new AmqpcMessage("This is the message body",
                                                "SJH");
      myMessage.appendData(" Appended");
      String body = myMessage.data;
      expect(body, "This is the message body Appended");
      
    });
    
    test("Message Properties", () {  
      
      AmqpcMessage myMessage = new AmqpcMessage("This is the message body",
                                                "SJH");
      bool hasProperties = myMessage.hasMessageProperties();
      expect(hasProperties, isTrue);
      bool hasDeliveryProperties = myMessage.hasDeliveryProperties();
      expect(hasDeliveryProperties, isTrue);
      AmqpcMessageProperties properties = myMessage.getMessageProperties();
      expect(properties, isNotNull);
      expect(properties.contentLength, 24);
      expect(properties.messageId.toString(), "00000000-0000-0000-0000-000000000000");
      expect(properties.replyTo.exchange, "");
      
    });
    
    test("Delivery Properties", () {  
      
      AmqpcMessage myMessage = new AmqpcMessage("This is the message body",
                                                "SJH");
      bool hasProperties = myMessage.hasMessageProperties();
      expect(hasProperties, isTrue);
      bool hasDeliveryProperties = myMessage.hasDeliveryProperties();
      expect(hasDeliveryProperties, isTrue);
      AmqpcDeliveryProperties properties = myMessage.getDeliveryProperties();
      expect(properties, isNotNull);
      expect(properties.redelivered, isFalse);
      expect(properties.immediate, isFalse);
      expect(properties.routingKey, "SJH");
      
    });
    
    test("Destination", () {  
      
      AmqpcMessage myMessage = new AmqpcMessage("This is the message body",
                                                "SJH");
      String destination = myMessage.getDestination();
      expect(destination, isNotNull);
      expect(destination, "");
      
    });
    
    test("Is Redelivered", () {  
      
      AmqpcMessage myMessage = new AmqpcMessage("This is the message body",
                                                "SJH");
      bool reDelivered = myMessage.reDelivered;
      expect(reDelivered, isFalse);
      
    });
    
    test("Set Redelivered", () {  
      
      AmqpcMessage myMessage = new AmqpcMessage("This is the message body",
                                                "SJH");
      bool reDelivered = myMessage.reDelivered;
      expect(reDelivered, isFalse);
      myMessage.reDelivered = true;
      reDelivered = myMessage.reDelivered;
      expect(reDelivered, isTrue);
      
      
    });
    
    test("Sequence Number", () {  
      
      AmqpcMessage myMessage = new AmqpcMessage("This is the message body",
                                                "SJH");
      int sequence = myMessage.sequenceNumber;
      expect(sequence, 0);
      
    });
    
  });
  
  /* Group 4 - Session Tests */
  group("4. Session Tests - ", () {
    
    test("Construction ", () {
      
    void wrapper() {
      
      AmqpcSession mySession = new AmqpcSession();
      
    }
    
    expect(wrapper, throws);
      
      
    });
    
    test("Execution Sync", () {  
      
      AmqpcConnection myConnection = new AmqpcConnection();
      bool result = myConnection.openHost("localhost");
      expect(result, isTrue);
      expect(myConnection.isOpen(), isTrue);
      AmqpcSession mySession = myConnection.newSession("SJH",0);
      mySession.executionSync(sync:true);   
      myConnection.close();
      
    });
    
  });
  
}
