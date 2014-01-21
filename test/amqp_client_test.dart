

library amqp_client__test;

import '../lib/amqp_client.dart';
import 'package:unittest/unittest.dart';  

main() {  
  
  
  /* Tests */
  
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
      ConnectionSettings settings = new ConnectionSettings();
      settings.virtualHost = "/";
      bool result = myConnection.openUrlSettings("qpid:@tcp:localhost",
                                                 settings);
      expect(result, isTrue);
      expect(myConnection.isOpen(), isTrue);
      myConnection.close();
      
    });
    
  });
  
}
