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
      
  void messageTransfer({String destination:null,
                        int acceptMode:1,
                        int acquireMode:0,
                        AmqpcMessage content:null,
                        bool sync:true}) native "Session::sessionMessageTransfer";   
  
  void messageSubscribe({String queue:null,
                         String destination: null,
                         int acceptMode:0,
                         int acquireMode:0,
                         bool exclusive:false,
                         String resumeId:null,
                         int resumeTtl:0,
                         AmqpcFieldTable arguments:null,
                         bool sync:true) native "Session::sessionMessageSubscribe";
  
  void messageCancel({String destination:null,
                      bool sync:true) native "Session::sessionMessageCancel";
  
  
  void messageFlush({String destination:null,
                     bool sync:true) native "Session::sessionMessageFlush";
  
  void messageStop({String destination:null,
                    bool sync:true) native "Session::sessionMessageStop";
  
  void txCommit({bool sync:true}) native "Session::sessionTxCommit";
  
  void txRollback({bool sync:true}) native "Session::sessionTxRollback";
  
  void exchangeDeclare({String exchange:null,
                        String type:null,
                        String alternateExchange:null,
                        bool passive:false,
                        bool durable:false,
                        bool autoDelete:false,
                        AmqpcFieldTable arguments:null,
                        bool sync:true}) native "Session::sessionExchangeDeclare";
  
  void exchangeDelete({String exchange:null,
                       bool ifUnused:false,
                       bool sync:true}) native "Session::sessionExchangeDelete";
  
  void exchangeBind({String queue:null,
                     String exchange:null,
                     String bindingKey:null,
                     AmqpcFieldTable arguments:null,
                     bool sync:true}) native "Session::sessionExchangeBind";
  
  void exchangeUnbind({String queue:null,
                       String exchange:null,
                       String bindingKey:null,
                       bool sync:true}) native "Session::sessionExchangeBind";
  
  
  void queueDeclare({String queue:null,
                     String alternateExchange:null,
                     bool passive:false,
                     bool durable:false,
                     bool exclusive:false,
                     bool autoDelete:false,
                     AmqpcFieldTable arguments:null,
                     bool sync:true}) native "Session::QueueDeclare";
  
  void queueDelete({String queue:null,
                    bool ifUnused:false,
                    bool ifEmpty:false,
                    bool sync:true}) native "Session:sessionQueueDelete";
  
  void queuePurge({String queue:null,
                   bool sync:true}) native "Session::queuePurge";
  
  
}