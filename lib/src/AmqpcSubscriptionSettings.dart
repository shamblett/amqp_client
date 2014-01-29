/*
 * Package : amqp_client
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 27/01/2014
 * Copyright :  S.Hamblett@OSCF
 * 
 * Qpid Subscription Settings class
 */

part of amqp_client;

class AmqpcSubscriptionSettings {
  
  /**
   * Accept Mode
   */
  static const ACCEPT_MODE_EXPLICIT = 0;
  static const ACCEPT_MODE_NONE = 1;

  /**
  * Acquire Mode
  */  
  static const ACQUIRE_MODE_PRE_ACQUIRED = 0;
  static const ACQUIRE_MODE_NOT_ACQUIRED = 1;
  
  /**
   * Completion Mode
   */
  static const  MANUAL_COMPLETION = 0;
  static const COMPLETE_ON_DELIVERY = 1;
  static const COMPLETE_ON_ACCEPT = 2;

  int _acceptMode = ACCEPT_MODE_EXPLICIT;
  int get acceptMode => _acceptMode;
  
  int _acquireMode = ACQUIRE_MODE_PRE_ACQUIRED;
  int get acquireMode => _acquireMode;
  
  /**
   * Auto Acknowledge
   */
  int _autoAck = 1;
  int get autoAck => _autoAck;
  
  int _completionMode = COMPLETE_ON_DELIVERY;
  int get completeionMode => _completionMode;
  
  /**
   * Exclusive
   */
  bool _exclusive;
  bool get exclusive => _exclusive;
  
}