/*
 * Package : amqp_client
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 22/01/2014
 * Copyright :  S.Hamblett@OSCF
 * 
 * Qpid Delivery Properties class
 */

part of amqp_client;

class AmqpcDeliveryProperties{
  
  /**
   * Discard Unroutable
   */
  bool _discardUnroutable;
  bool get discardUnroutable => _discardUnroutable;
  set discardUnroutable(bool state) => _discardUnroutable = state;
  
  /**
   * Immediate
   */
  bool _immediate;
  bool get immediate => _immediate;
  set immediate(bool state) => _immediate = state;
  
  /**
   * Redelivered
   */
  bool _redelivered;
  bool get redelivered => _redelivered;
  set redelivered(bool state)=> _redelivered = state;
  
  /**
   * Priority
   */
  int  _priority;
  int get priority => _priority;
  set priority(int value) => _priority = value;
  
  /**
   * Delivery Mode
   */
  int _deliveryMode;
  int get deliveryMode => _deliveryMode;
  set deliveryMode(int value) => _deliveryMode = value;
  
  /**
   * Time To Live
   */
  int _ttl;
  int get ttl => _ttl;
  set ttl(int value) => _ttl = value;
  
  /**
   * Timestamp
   */
  int _timestamp;
  int get timestamp => _timestamp;
  set timestamp(int value) => _timestamp = value;
  
  /**
   * Expiration Time
   */
  int _expiration;
  int get expiration => _expiration;
  set expiration(int value) => _expiration = value;
  
  /**
   * Exchange
   */
  String _exchange = null;
  String get exchange => _exchange;
  set exchange(String value) {
    
    _exchange = value;
    if ( _exchange != null ) {
      if (_exchange.length >= 256) throw new AmqpcException("Value for exchange is too large"); 
    }
      
  }
  
  /**
   * Routing Key
   */
  String _routingKey = null;
  String get routingKey => _routingKey; 
  set routingKey(String value) {
    
    _routingKey = value;
    if ( _routingKey != null ) {
      if (_routingKey.length >= 256) throw new AmqpcException("Value for routingKey is too large");
    }
  }
  
  /**
   * Resume Identifier
   */
  String _resumeId = null;
  String get resumeId => _resumeId; 
  set resumeId(String value) {
    
    _resumeId = value;
    if ( _resumeId != null ) {
      if (_resumeId.length >= 65536) throw new AmqpcException("Value for resumeId is too large");
    }
  }
  
  /**
   * Resume Time To live
   */
  int _resumeTtl;
  int get resumeTtl => _resumeTtl;
  set resumeTtl(int value) => _resumeTtl = value;
  
  
}
