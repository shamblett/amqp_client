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
      
  void messageTransfer({String destination:"",
                        int acceptMode:1,
                        int acquireMode:0,
                        AmqpcMessage content:null,
                        bool sync:true}) native "Session::sessionMessageTransfer";   
  
  void messageSubscribe({String queue:"",
                         String destination:"",
                         int acceptMode:0,
                         int acquireMode:0,
                         bool exclusive:false,
                         String resumeId:"",
                         int resumeTtl:0,
                         bool sync:true}) native "Session::sessionMessageSubscribe";
  
  void messageCancel({String destination:"",
                      bool sync:true}) native "Session::sessionMessageCancel";
  
  
  void messageFlush({String destination:"",
                     bool sync:true}) native "Session::sessionMessageFlush";
  
  void messageStop({String destination:null,
                    bool sync:true}) native "Session::sessionMessageStop";
  
  
  void exchangeDeclare({String exchange:"",
                        String type:"",
                        String alternateExchange:"",
                        bool passive:false,
                        bool durable:false,
                        bool autoDelete:false,
                        bool sync:true}) native "Session::sessionExchangeDeclare";
  
  void exchangeDelete({String exchange:"",
                       bool ifUnused:false,
                       bool sync:true}) native "Session::sessionExchangeDelete";
  
  void exchangeBind({String queue:"",
                     String exchange:"",
                     String bindingKey:"",
                     bool sync:true}) native "Session::sessionExchangeBind";
  
  void exchangeUnbind({String queue:"",
                       String exchange:"",
                       String bindingKey:"",
                       bool sync:true}) native "Session::sessionExchangeUnbind";
  
  
  void queueDeclare({String queue:"",
                     String alternateExchange:"",
                     bool passive:false,
                     bool durable:false,
                     bool exclusive:false,
                     bool autoDelete:false,
                     bool sync:true}) native "Session::QueueDeclare";
  
  void queueDelete({String queue:"",
                    bool ifUnused:false,
                    bool ifEmpty:false,
                    bool sync:true}) native "Session:sessionQueueDelete";
  
  void queuePurge({String queue:"",
                   bool sync:true}) native "Session::queuePurge";
  
  
}