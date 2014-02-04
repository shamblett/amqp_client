library amqp_client_test;

import '../lib/amqp_client.dart';
import 'package:unittest/unittest.dart';  

main() {  
  
  test("Message Transfer Local Queue", () {

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
    
    /* Create and bind our local queue */
    AmqpcSubscriptionManager myManager = new AmqpcSubscriptionManager(session);
    expect(myManager, isNotNull);
    AmqpcLocalQueue localQueue = new AmqpcLocalQueue();
    AmqpcSubscription mySubscription = myManager.subscribeLocal(localQueue,
        "MyTransferQueue");
    expect(mySubscription, isNotNull);
    
    /* Create and send a message to the exchange using the routing
    * key we bound our local queue with.
    */ 
    String messageData = "This is the body of the transfer test message";
    AmqpcMessage msgOut = new AmqpcMessage(messageData, "MyTransferKey");
    session.messageTransfer(destination:"MyTransferExchange", content:msgOut, acceptMode:1);

    /* Get the message from the local queue. */ 
    AmqpcMessage msgIn = localQueue.get();
    expect(msgIn.data, msgOut.data);
    print(msgOut.data);
   
    
    /* Close the connection */
    myConnection.close();
    
    
  });
  
}
  