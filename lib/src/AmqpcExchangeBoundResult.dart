/*
 * Package : amqp_client
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 27/01/2014
 * Copyright :  S.Hamblett@OSCF
 * 
 * Qpid Connection class
 */

part of amqp_client;

class AmqpcExchangeBoundResult {
  
  /**
   * Exchange Not Found 
   */
  bool _exchangeNotFound;
  bool get exchangeNotFound => _exchangeNotFound;
  
  /*
   * Queue Not Found
   */
  bool _queueNotFound;
  bool get queueNotFound => _queueNotFound;
  
  /**
   * Queue Not Matched
   */
  bool _queueNotMatched;
  bool get queueNotMatched => _queueNotMatched;
  
  /**
   * Key Not Matched
   */
  bool _keyNotMatched;
  bool get keyNotMatched => _keyNotMatched;
  
  /**
   * Arguments Not matched
   */
  bool _argsNotMatched;
  bool get argsNotMatched => _argsNotMatched;
  
}