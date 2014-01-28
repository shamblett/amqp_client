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
  Amqpcsession get session => _session;
  
  /**
   * Constructor
   */
  SubscriptionManager(this.session) {
    
    _newSubscriptionManager(_session);
    
  }
  
  /**
   *  Private constructor for the native client 
   */
  SubscriptionManager._newSubscriptionManager(AmqpcSession session) {
    
    
  }
  

  
  
  
}