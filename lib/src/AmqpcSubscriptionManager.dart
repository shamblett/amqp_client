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
   *  Private constructor for the native client 
   */
  _newSubscriptionManager(AmqpcSession session) native "SubscriptionManager::Subscriptionmanager";
    
  /**
   * Subscribe a LocalQueue to receive messages from queue.
   *
   * Incoming messages are stored in the queue for you to retrieve.
   *
   * @param queue Name of the queue to subscribe to.
   * @param name unique destination name for the subscription, defaults to queue name.
   * If not specified, the queue name is used.
     */
   AmqpcSubscription subscribe(AmqpcLocalQueue localQueue,
                               String queue,
                               [String name = ""]) native "SubscriptionManager::subscribe";
   
}
  

  
  
  