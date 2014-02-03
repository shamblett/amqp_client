library amqp_client_test;

import '../lib/amqp_client.dart';
import 'package:unittest/unittest.dart';  

main() {  
  
  test("Message Transfer", () {

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

    /* Create and send a message to the exchange using the routing
    * key we bound our queue with.
    */ 
    String messageData = "This is the body of the transfer test message";
    AmqpcMessage msgOut = new AmqpcMessage(messageData, "MyTransferKey");
    session.messageTransfer(destination:"MyTransferExchange", content:msgOut, acceptMode:1);
    String messageData1 = "This is the body of the transfer test message 1";
    AmqpcMessage msgOut1 = new AmqpcMessage(messageData1, "MyTransferKey");
    session.messageTransfer(destination:"MyTransferExchange", content:msgOut1, acceptMode:1);   
    
    /*  Using the SubscriptionManager, get the message from the queue. */
    AmqpcSubscriptionManager subs = new AmqpcSubscriptionManager(session);
    AmqpcMessage msgIn = subs.get("MyTransferQueue");
    expect(msgIn.data, msgOut.data);
    print(msgOut.data);
    msgIn = subs.get("MyTransferQueue");
    expect(msgIn.data, msgOut1.data);
    print(msgOut1.data);
    
    /* Close the connection */
    myConnection.close();
    
    
  });
  
}