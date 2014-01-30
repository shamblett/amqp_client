/*
 * Package : amqp_client
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 27/01/2014
 * Copyright :  S.Hamblett@OSCF
 * 
 * Qpid Subscription Manager class.
 * 
 * Note that message listerners are not supported in this implementation.
 * use remote or local queue management instead.
 */

part of amqp_client;

class AmqpcSubscriptionManager {
  
  
  /**
   * Indicates get operations should wait for the meassage 
   * to become ready.
   */
  static const INFINITE_WAIT = -1;
  
  /**
   * The associated session
   */
  AmqpcSession _session;
  AmqpcSession get session => _session;
  
  /**
   * Constructor
   */
  AmqpcSubscriptionManager(this._session) {
    
    _newSubscriptionManager(_session);
    
  }
  
  /**
   * Native class constructor, hidden in Dart
   */
  AmqpcSubscriptionManager._nativeConstructor();
  
  /**
   *  Private constructor for the native client 
   */
  _newSubscriptionManager(AmqpcSession session) native "SubscriptionManager::subscriptionManager";
    
  /**
   * Subscribe a LocalQueue to receive messages from queue.
   *
   * Incoming messages are stored in the queue for you to retrieve.
   *
   * @param queue Name of the queue to subscribe to.
   * @param name unique destination name for the subscription, defaults to queue name.
   * If not specified, the queue name is used.
     */
   AmqpcSubscription subscribeLocal(AmqpcLocalQueue localQueue,
                               String queue,
                               [String name = ""]) native "SubscriptionManager::subscriptionManagerSubscribeLocal";
   /**
    * Subscribe a MessagesListener to receive messages from queue.
    *
    *
    *@param queue Name of the queue to subscribe to.
    *@param name unique destination name for the subscription, defaults to queue name.
    * If not specified, the queue name is used.
    */
   AmqpcSubscription subscribeListen(String queue,
                                    [String name = ""]) native "SubscriptionManager::subscriptionManagerSubscribeListen";
   
   /** Get a single message from a queue.
    * (Note: this currently uses a subscription per invocation and is
    * thus relatively expensive. The subscription is cancelled as
    * part of each call which can trigger auto-deletion).
    * @param timeout wait up this timeout for a message to appear.
    * @return message from the queue.
    * @throw Exception if the timeout is exceeded.
    */
   AmqpcMessage get(String queue, 
                    [int timeout = INFINITE_WAIT]) native "SubscriptionManager::subscriptionManagerGet";

   /** Get a subscription by name.
    *@throw Exception if not found.
    */
   AmqpcSubscription getSubscription(String name) native "SubscriptionManager::subscriptionManagerGetSubscription";

   /** 
    * Cancel a subscription. See also: AmqpcSubscription.cancel() 
    */
   void cancel(String name) native "SubscriptionManager::subscriptionManagerCancel";

   /** Deliver messages in the current thread until stop() is called.
    * Only one thread may be running in a SubscriptionManager at a time.
    * @see run
    */
   void run() native "SubscriptionManager::subscriptionManagerRun";

   /** Start a new thread to deliver messages.
    * Only one thread may be running in a SubscriptionManager at a time.
    * @see start
    */
   void start()  native "SubscriptionManager::subscriptionManagerStart";

   /**
    * Wait for the thread started by a call to start() to complete.
    */
   void wait()  native "SubscriptionManager::subscriptionManagerWait";

   /** If set true, run() will stop when all subscriptions
    * are cancelled. If false, run will only stop when stop()
    * is called. True by default.
    */
   void setAutoStop([bool set = true])  native "SubscriptionManager::subscriptionManagerSetAutoStop";

   /** 
    * Stop delivery. Causes run() to return, or the thread started with start() to exit. 
    */
   void stop()  native "SubscriptionManager::subscriptionManagerStop";
   
}
  

  
  
  