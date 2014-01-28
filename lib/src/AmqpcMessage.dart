/*
 * Package : amqp_client
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 12/09/2013
 * Copyright :  S.Hamblett@OSCF
 * 
 * Qpid Method class
 * 
 */

part of amqp_client;

class AmqpcMessage {
  
  /**
   * Message body
   */
  String _data;
  String get data => _getData();
  set data(String message) => _setData(message);
  
  /**
   * Routing Key set in construction only
   */
  String _routingKey;
  String get routingKey => _routingKey;
  
  /**
   * Re-Delivered flag
   */
  bool _reDelivered = false;
  bool get reDelivered => _isRedelivered();
  set reDelivered(bool state) => _setRedelivered(state);
  
  /**
   * Sequence Number
   */
  int _sequnceNumber;
  int get sequenceNumber => _getId();
  
  /**
   * Constructor
   */
  AmqpcMessage(this._data,
               this._routingKey) {
    
    _newMessage();
    
  }
  
  /**
   * Dummy native constructor, hidden in Dart
   */
  AmqpcMessage._nativeConstructor() {}
  
  /**
   * Construction function for the native extension
   */
  void _newMessage() native "Message::Message";
  
  bool operator==(other) native "Message::messageEquals";
  
  void swap(AmqpcMessage message) native "Message::messageSwap";
  
  void _setData(String data) native "Message::messageSetData";
  
  String _getData() native "Message::messageGetData";
  
  void appendData(String data) native "Message::MessageAppendData";
  
  bool hasMessageProperties() native "Message::messageHasMessageProperties";
  
  AmqpcMessageProperties getMessageProperties() native "Message::messageGetMessageProperties";
  
  bool hasDeliveryProperties() native "Message::messageHasDeliveryProperties";
  
  AmqpcDeliveryProperties getDeliveryProperties() native "Message::messageGetDeliveryProperties";
  
  /** The destination of messages sent to the broker is the exchange
   * name.  The destination of messages received from the broker is
   * the delivery tag identifying the local subscription (often this
   * is the name of the subscribed queue.)
   */
  String getDestination() native "Message::messageGetDestination";
  
  /** Check the redelivered flag. 
  */
  bool _isRedelivered() native "Message::messageIsRedelivered";
  
  /** Set the redelivered flag. 
   */
  void _setRedelivered(bool reDelivered) native "Message::messageSetRedelivered";
  
  /**
   * Sequence number
   */
  int _getId() native "Message::messageGetId";
  
  
}