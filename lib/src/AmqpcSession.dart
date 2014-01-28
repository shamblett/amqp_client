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
  
  /**
   * Execution Sync
   */
  void executionSync({bool sync:true}) native "Session::sessionExecutionSync";
  
  /**
   * Message Transfer
   */
  void messageTransfer({String destination:"",
                        int acceptMode:1,
                        int acquireMode:0,
                        AmqpcMessage content:null,
                        bool sync:true}) native "Session::sessionMessageTransfer";   
  
  /**
   * Message Subscribe
   */
  void messageSubscribe({String queue:"",
                         String destination:"",
                         int acceptMode:0,
                         int acquireMode:0,
                         bool exclusive:false,
                         String resumeId:"",
                         int resumeTtl:0,
                         bool sync:true}) native "Session::sessionMessageSubscribe";
  
  /**
   * Message Cancel
   */
  void messageCancel({String destination:"",
                      bool sync:true}) native "Session::sessionMessageCancel";
  
  /**
   * Message Flush
   */
  void messageFlush({String destination:"",
                     bool sync:true}) native "Session::sessionMessageFlush";
  
  /**
   * Message Stop
   */
  void messageStop({String destination:null,
                    bool sync:true}) native "Session::sessionMessageStop";
  
  /**
   * Exchange Declare
   */
  void exchangeDeclare({String exchange:"",
                        String type:"",
                        String alternateExchange:"",
                        bool passive:false,
                        bool durable:false,
                        bool autoDelete:false,
                        bool sync:true}) native "Session::sessionExchangeDeclare";
  
  /**
   * Exchange Delete
   */
  void exchangeDelete({String exchange:"",
                       bool ifUnused:false,
                       bool sync:true}) native "Session::sessionExchangeDelete";
  
  /**
   * Exchange Bind
   */
  void exchangeBind({String queue:"",
                     String exchange:"",
                     String bindingKey:"",
                     bool sync:true}) native "Session::sessionExchangeBind";
  
  /**
   * Exchange Unbind
   */
  void exchangeUnbind({String queue:"",
                       String exchange:"",
                       String bindingKey:"",
                       bool sync:true}) native "Session::sessionExchangeUnbind";
  
  /**
   * Exchange Bound
   */
  AmqpcExchangeBoundResult exchangeBound({String exchange:"",
                                         String queue:"",
                                         String bindingKey:"",
                                         bool sync:true}) native "Session::sessionExchangeBound";
 /**
  * Queue Declare                                        
  */
  void queueDeclare({String queue:"",
                     String alternateExchange:"",
                     bool passive:false,
                     bool durable:false,
                     bool exclusive:false,
                     bool autoDelete:false,
                     bool sync:true}) native "Session::sessionQueueDeclare";
  
  /**
   * Queue Delete
   */
  void queueDelete({String queue:"",
                    bool ifUnused:false,
                    bool ifEmpty:false,
                    bool sync:true}) native "Session:sessionQueueDelete";
  /**
   * Queue Purge
   */
  void queuePurge({String queue:"",
                   bool sync:true}) native "Session::sessionQueuePurge";
  
  
}