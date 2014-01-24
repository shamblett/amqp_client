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
    
    if (_exchange.length >= 256) throw new AmqpcException("Value for exchange is too large"); 
    exchange = value;
    
  }
  
  /**
   * Routing Key
   */
  String _routingKey = null;
  String get routingKey => _routingKey; 
  set routingKey(String value) {
    
    if (_routingKey.length >= 256) throw new AmqpcException("Value for routingKey is too large");
    _routingKey = value;
    
  }
  
  /**
   * Flags
   */
  ByteData _flags = new ByteData(2);
  int get flags => _flags.getUint16(0);
  set flags(int value) => _flags.setUint16(0,value);
  
  AmqpcReplyTo(this._exchange,
               this._routingKey,
               this._flags) {
    
    if (_exchange.length >= 256) throw new AmqpcException("Value for exchange is too large"); 
    if (_routingKey.length >= 256) throw new AmqpcException("Value for routingKey is too large");
    
  }
    
}