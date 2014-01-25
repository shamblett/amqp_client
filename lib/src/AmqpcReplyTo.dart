/*
 * Package : amqp_client
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 22/01/2014
 * Copyright :  S.Hamblett@OSCF
 * 
 * Qpid Reply To class
 */

part of amqp_client;

class AmqpcReplyTo{
  
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
    
}