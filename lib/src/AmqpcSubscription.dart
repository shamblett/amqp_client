/*
 * Package : amqp_client
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 27/01/2014
 * Copyright :  S.Hamblett@OSCF
 * 
 * Qpid Subscription class
 */

part of amqp_client;

class AmqpcSubscription {
  
  /** 
   * The name of the subscription, used as the "destination" for messages from 
   * the broker.
   * Usually the same as the queue name but can be set differently.
   */
  String _name;
  String get name => _getName();
  
  /** 
   * Name of the queue this subscription subscribes to 
   */
  String _queue;
  String get queue => _getQueue();
  
  /**
   * Construction
   */
  AmqpcSubscription() {
    
    _newSubscription();
    
  }
  
  /**
   * Private native constructor
   */
  void _newSubscription() native "Subscription::Subscription";
  
  /** 
   * Get name
   */
  String _getName() native "Subscription::subscriptionGetName";
  

  /**
   * Get queue
   */
  String _getQueue() native "Subscription::subscriptionGetQueue";
  
  /** 
   * Get the flow control and acknowledgement settings for 
   * this subscription. 
   */
  AmqpcSubscriptionSettings getSettings() native "Subscription::subscriptionGetSettings";

  /** 
   * Automatically acknowledge (acquire and accept) batches of n messages.
   * You can disable auto-acknowledgement by setting n=0, and use acquire() 
   * and accept()to manually acquire and accept messages.
   */
  void setAutoAck(int batch) native "Subscription::subscriptionSetAutoAck";

  /** 
   * Get the session associated with this subscription 
   * */
  AmqpcSession getSession() native "Subscription::subscriptionGetSession";

  /** 
   * Acquire a single message 
   */
  void acquire(AmqpcMessage message) native "Subscription::subscriptionAcquire";

  /** 
   * Accept a single message 
   */
  void accept(AmqpcMessage message) native "Subscription::subscriptionAccept";  

  /** 
   * Release a single message 
   */
  void release(AmqpcMessage message) native "Subscription::subscriptionRelease";  
  
  /** 
   * Get the subscription manager associated with this subscription 
   */
  AmqpcSubscriptionManager getSubscriptionManager() native "Subscription::subscriptiongetSubscriptionmanager";

  /** 
   * Cancel the subscription. 
   */
  void cancel() native "Subscription::subscriptionCancel";  
  
}