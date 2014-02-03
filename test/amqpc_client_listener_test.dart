library amqp_client_test;

import '../lib/amqp_client.dart';
import 'package:unittest/unittest.dart';  

int messageCount = 0;

void listener(m,t,s) {
  
    if ( messageCount == 0 ) {
      
      /* First message, check and send another */
      expect(m.data, "This is the body of the transfer test message" );
      print("Message OK"); 
      String messageData = "This is the body of the transfer test message 2";
      AmqpcMessage msgOut1 = new AmqpcMessage(messageData, "MyTransferKey");
      s.messageTransfer(destination:"MyTransferExchange", content:msgOut1, acceptMode:1); 
      messageCount++;
      
    } else if ( messageCount == 1) {
      
      /* Second message sent from test body below */
      expect(m.data, "This is the body of the transfer test message 1" );
      print("Message1 OK"); 
      messageCount++;
      
    } else {
      
      /* Third message sent from messageCount == 0 above */
      expect(m.data, "This is the body of the transfer test message 2" );
      print("Message2 OK"); 
      
      /* We can stop delivery now in our case */
      t.stop();
      
    }
}

main() {  
  
  test("Message Transfer Listener", () {
    
    /* Connect to the broker */
    AmqpcConnection myConnection = new AmqpcConnection();
    bool result = myConnection.openHost("localhost");
    expect(result, isTrue);
    expect(myConnection.isOpen(), isTrue);

    /* Create and open a session on the connection through which
     * most functionality is exposed.
     */
    AmqpcSession session = myConnection.newSession("MyTransferTestSession");
    expect(session, isNotNull);


    /* 'declare' the exchange and the queue, which will create them
    * as they don't exist.
    */
    session.exchangeDeclare(exchange:"MyTransferExchange",type:"direct");
    session.queueDeclare(queue:"MyTransferQueue", autoDelete:true, exclusive:true);
    
    /* Now bind the queue to the exchange, */
    session.exchangeBind(exchange:"MyTransferExchange", queue:"MyTransferQueue", bindingKey:"MyTransferKey");
    
    /* Create and bind our local listener */
    AmqpcSubscriptionManager myManager = new AmqpcSubscriptionManager(session);
    expect(myManager, isNotNull);
    AmqpcSubscription mySubscription = myManager.subscribeListen("MyTransferQueue");
    expect(mySubscription, isNotNull);
    
    /* Create and send two messages to the exchange using the routing
    * key we bound our local queue with.
    */ 
    String messageData = "This is the body of the transfer test message";
    AmqpcMessage msgOut = new AmqpcMessage(messageData, "MyTransferKey");
    session.messageTransfer(destination:"MyTransferExchange", content:msgOut, acceptMode:1);
    String messageData1 = "This is the body of the transfer test message 1";
    AmqpcMessage msgOut1 = new AmqpcMessage(messageData1, "MyTransferKey");
    session.messageTransfer(destination:"MyTransferExchange", content:msgOut1, acceptMode:1);
     
    /* Set our listener call back */
    myManager.listenerCallback = listener;
    
    /* Start our recieve process on our current thread(isolate) */
    myManager.run();
    
    
       
  });
  
}
