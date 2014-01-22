/*
 * Packge : 
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 22/01/2014
 * Copyright :  S.Hamblett@OSCF
 *
 * This exception is thrown when AMQPC has an internal error, such as an invalid
 * parameter being passed to a function.
 */

part of amqp_client;

class AmqpcException implements Exception {
  
  String _message = '';
  String get message => _message;
  set message(String value) => _message = value;
  
  AmqpcException([this._message]);
  
  String toString() => "AmqpcException: message = ${_message}";
}

