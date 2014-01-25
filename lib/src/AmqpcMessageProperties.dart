/*
 * Package : amqp_client
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 22/01/2014
 * Copyright :  S.Hamblett@OSCF
 * 
 * Qpid Message Properties class
 */

part of amqp_client;

class AmqpcMessageProperties{
  
  /**
   * Content length
   */
  int _contentLength;
  int get contentLength => _contentLength;
  set contentLength(int length) => _contentLength = length;
  
  /**
   * Message Identifier
   */
  AmqpcUuid _messageId;
  AmqpcUuid get messageId => _messageId;
  set messageId(AmqpcUuid id) => _messageId = id;
  
  /**
   * Correlation Identifier
   */
  String _correlationId;
  String get correlationId => _correlationId;
  set correlationId(String id) {
    
    _correlationId = id;
    if ( _correlationId != null) {
      if (_correlationId.length >= 65536) throw new AmqpcException("Value for correlationId is too large");
    }
  }
  
  AmqpcReplyTo _replyTo;
  AmqpcReplyTo get replyTo => _replyTo; 
  set replyTo(AmqpcReplyTo reply) => _replyTo = reply;
  
  /**
   * Content Type
   */
  String _contentType;
  get contentType => _contentType;
  set contentType(String type) {
    
    _contentType = type;
    if ( _contentType != null ) {
      if (_contentType.length >= 256) throw new AmqpcException("Value for contentType is too large");
    }
      
  }
  
  /**
   * Content Encoding
   */
  String _contentEncoding;
  String get contentEncoding => _contentEncoding;
  set contentEncoding(String encoding) {
    
    _contentEncoding = encoding;
    if ( _contentEncoding != null ) {
      if (_contentEncoding.length >= 256) throw new AmqpcException("Value for contentEncoding is too large");
    }
    
  }
  
  /**
   * User Identity
   */
  String _userId;
  String get userId => _userId;
  set userId(String id) {
    
    _userId = id;
    if ( _userId != null ) {
      if (_userId.length >= 65536) throw new AmqpcException("Value for userId is too large");
    }  
    
  }
  
  /**
   * Application Identity
   */
  String _appId;
  String get appId => _appId;
  set appId(String id) {
    
    _appId = id;
    if ( _appId != null ) {
      if (_appId.length >= 65536) throw new AmqpcException("Value for appId is too large");
    }
    
  }
  
}
