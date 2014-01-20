

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
    
  });
  
 /*bool result = myConnection.openHost("localhost");
 
 print("Open status = $result");
 
 bool open = myConnection.isOpen();
 
 print("isOpen open status = $open");
 
 myConnection.close();
 
 open = myConnection.isOpen();
 
 result = myConnection.openUrl("qpid:@tcp:localhost");
 
 open = myConnection.isOpen();
 
 print("isOpen url status = $open");
 
  myConnection.close();
 
 open = myConnection.isOpen();
 
 print("isOpen url status = $open");*/
 
}
