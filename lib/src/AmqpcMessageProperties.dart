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
  AmqpcUuid get messageid => _messageId;
  set messageId(AmqpcUuid id) => _messageId = id;
  
  /**
   * Correlation Identifier
   */
  String _correlationId;
  String get correlationId => _correlationId;
  set correlationId(String id) {
    
    if (_correlationId.length >= 65536) throw new AmqpcException("Value for correlationId is too large");
    _correlationId = id;
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
    
    if (_contentType.length >= 256) throw new AmqpcException("Value for contentType is too large");
    _contentType = type;
  }
  
  /**
   * Content Encoding
   */
  String _contentEncoding;
  String get contentEncoding => _contentEncoding;
  set contentEncoding(String encoding) {
    
    if (_contentEncoding.length >= 256) throw new AmqpcException("Value for contentEncoding is too large");
    _contentEncoding = encoding;
    
  }
  /**
   * User Identity
   */
  String _userId;
  String get userId => _userId;
  set userId(String id) {
    
    if (_userId.length >= 65536) throw new AmqpcException("Value for userId is too large");
    _userId = id;
  }
  
  /**
   * Application Identity
   */
  String _appId;
  String get appId => _appId;
  set appId(String id) {
    
    if (_appId.length >= 65536) throw new AmqpcException("Value for appId is too large");
    _appId = id;
  }
  
  /**
   * Application Headers
   */
  AmqpcFieldTable _applicationHeaders;
  AmqpcFieldTable get applicationHeaders => _applicationHeaders;
  set applicationHeaders(AmqpcFieldTable headers) => _applicationHeaders = headers;
  
  /**
   * Flags
   */
  ByteData _flags = new ByteData(2);
  int get flags => _flags.getUint16(0);
  set flags(int value) => _flags.setUint16(0,value);
  
  AmqpcMessageProperties(this._contentLength,
                         this._messageId,
                         this._correlationId,
                         this._replyTo,
                         this._contentType,
                         this._contentEncoding,
                         this._userId,
                         this._appId,
                         this._applicationHeaders) {
    
    if (_correlationId.length >= 65536) throw new AmqpcException("Value for correlationId is too large");
    if (_contentType.length >= 256) throw new AmqpcException("Value for contentType is too large");
    if (_contentEncoding.length >= 256) throw new AmqpcException("Value for contentEncoding is too large");
    if (_userId.length >= 65536) throw new AmqpcException("Value for userId is too large");
    if (_appId.length >= 65536) throw new AmqpcException("Value for appId is too large");
    
    
  }
  
}
