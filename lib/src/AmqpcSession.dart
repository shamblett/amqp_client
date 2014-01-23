/*
 * Package : amqp_client
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 12/09/2013
 * Copyright :  S.Hamblett@OSCF
 * 
 * Qpid Session class, see the Qpid documentation for further details on the class methods.
 * 
 */

part of amqp_client;

class AmqpcSession {
  
  /**
   * Default constructor throws an exception, this class is only valid when
   * returned from the AmqpcConnection.newSession method
   */
  AmqpcSession() {
   
    throw new AmqpcException('You cannot construct a standalone session class, see AmqpcConnection');
  }
 
  /**
   * Constructor the native extension uses
   */
  AmqpcSession._nativeConstructor() {}
  
  void executionSync({bool sync:true}) native "Session::sessionExecutionSync";
      
      
}