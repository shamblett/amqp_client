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
  
  void executionSync(bool sync) native "Session::sessionExecutionSync";
      
      
}