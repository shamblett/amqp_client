/*
 * Package : amqp_client
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 22/01/2014
 * Copyright :  S.Hamblett@OSCF
 * 
 * Qpid UUID class
 */

part of amqp_client;

class AmqpcUuid{
  
  /**
   * Used for construction only
   */
  bool _unique = true;
  
  /**
   * Construction
   */
  AmqpcUuid([this._unique]) {
    
    _newUuid();
    
  }
  
  /**
   * Native constructor, hidden in Dart
   */
  AmqpcUuid._nativeConstructor() {}
  
  /**
   * Construction function for the native extension
   */
  void _newUuid() native "Uuid::Uuid";
  
  /** Set to a new unique identifier. */
  void generate() native "Uuid::uuidGenerate";

  /** Set to all zeros. */
  void clear() native "Uuid::uuidClear";

  /** Test for null (all zeros). */
  bool isNull() native "Uuid::uuidIsNull";
  
  /** String value in format 1b4e28ba-2fa1-11d2-883f-b9a761bde3fb. */
  String toString() native "Uuid::uuidStr";
  
  /**
   * ==
   */
  bool operator==(other) {
    
    if (other is! AmqpcUuid) return false;
    
    if ( str() == other.str() ) return true;
    
    return false;
    
  }
  
}