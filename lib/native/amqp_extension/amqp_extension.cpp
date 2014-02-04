/**
 * AMQP Client Native Extension for Dart
 * 
 * S. Hamblett <steve.hamblett@linux.com> 16/01/2014
 * 
 * Copyright steve@OSCF
 * 
 * Implements the native bindings for the AMQP Qpid client  
 */

#include "ExtAll.h"
#include "ExtConnection.h"
#include "ExtSession.h"
#include "ExtMessage.h"
#include "ExtUuid.h"
#include "ExtLocalQueue.h"
#include "ExtSubscription.h"
#include "ExtSubscriptionManager.h"

/*
 * Dart Native extension bindings
 */

/* LIbrary Initialise function */
DART_EXPORT Dart_Handle amqp_extension_Init(Dart_Handle parent_library) {
  
  if (Dart_IsError(parent_library)) { return parent_library; }

  Dart_Handle result_code = Dart_SetNativeResolver(parent_library, ResolveName);
  if (Dart_IsError(result_code)) return result_code;

  return Dart_Null();
  
}

/*
 * Dart Native extension name resolver
 */

struct FunctionLookup {
  const char* name;
  Dart_NativeFunction function;
};

FunctionLookup function_list[] = {
    
    /* Connection class */
    {"Connection::Connection", connectionConnection},
    {"Connection::openHost", connectionOpenHost},
    {"Connection::openUrl", connectionOpenUrl},
    {"Connection::openUrlSettings", connectionOpenUrlSettings},
    {"Connection::openSettings", connectionOpenSettings},
    {"Connection::isOpen", connectionIsOpen},
    {"Connection::close", connectionClose},
    {"Connection::getNegotiatedSettings", connectionGetNegotiatedSettings},
    {"Connection::connectionNewSession", connectionNewSession},
    {"Connection::connectionResume", connectionResume},
    
    /* Session class */
    {"Session::sessionExecutionSync", sessionExecutionSync},
    {"Session::sessionMessageTransfer", sessionMessageTransfer},
    {"Session::sessionMessageSubscribe", sessionMessageSubscribe},
    {"Session::sessionMessageCancel", sessionMessageCancel},
    {"Session::sessionMessageFlush", sessionMessageFlush},
    {"Session::sessionMessageStop", sessionMessageStop},
    {"Session::sessionExchangeDeclare", sessionExchangeDeclare},
    {"Session::sessionExchangeDelete", sessionExchangeDelete},
    {"Session::sessionExchangeBind", sessionExchangeBind},
    {"Session::sessionExchangeUnbind", sessionExchangeUnbind},
    {"Session::sessionQueueDeclare", sessionQueueDeclare},
    {"Session:sessionQueueDelete", sessionQueueDelete},
    {"Session::sessionQueuePurge", sessionQueuePurge},
    {"Session::sessionExchangeBound", sessionExchangeBound},
    
    /* Message class */
    {"Message::Message", messageMessage},
    {"Message::messageEquals", messageEquals},
    {"Message::messageGetData", messageGetData},
    {"Message::messageSetData", messageSetData},
    {"Message::messageSwap", messageSwap},
    {"Message::MessageAppendData", messageAppendData},
    {"Message::messageHasMessageProperties", messageHasMessageProperties},
    {"Message::messageHasDeliveryProperties", messageHasDeliveryProperties},
    {"Message::messageGetMessageProperties", messageGetMessageProperties},
    {"Message::messageGetDeliveryProperties", messageGetDeliveryProperties},
    {"Message::messageGetDestination", messageGetDestination},
    {"Message::messageIsRedelivered", messageIsRedelivered},
    {"Message::messageSetRedelivered", messageSetRedelivered},
    {"Message::messageGetId", messageGetId},
    
    /* Uuid */
    {"Uuid::Uuid", uuidUuid},
    {"Uuid::uuidGenerate", uuidGenerate},
    {"Uuid::uuidStr", uuidStr},
    {"Uuid::uuidClear", uuidClear},
    {"Uuid::uuidIsNull", uuidIsNull},
    
    /*  LocalQueue class */
    {"LocalQueue::LocalQueue", localQueueLocalQueue},
    {"LocalQueue::localQueueGet", localQueueGet},
    {"LocalQueue::localQueuePop", localQueuePop},
    {"LocalQueue::localQueueSize", localQueueSize},
    
    /* Subscription class */
    {"Subscription::subscriptionGetName", subscriptionGetName},
    {"Subscription::subscriptionGetQueue", subscriptionGetQueue},
    {"Subscription::subscriptionGetSettings", subscriptionGetSettings},
    {"Subscription::subscriptionSetAutoAck", subscriptionSetAutoAck},
    {"Subscription::subscriptionGetSession", subscriptionGetSession},
    {"Subscription::subscriptionAcquire", subscriptionAcquire},
    {"Subscription::subscriptionAccept", subscriptionAccept},
    {"Subscription::subscriptionRelease", subscriptionRelease},
    {"Subscription::subscriptionCancel", subscriptionCancel},
    {"Subscription::subscriptiongetSubscriptionmanager", subscriptionGetSubscriptionmanager},
    
    /* Subscription Manager class */
    {"SubscriptionManager::subscriptionManager", SubscriptionManagersubscriptionManager},
    {"SubscriptionManager::subscriptionManagerSubscribeLocal", subscriptionManagerSubscribeLocal},
    {"SubscriptionManager::subscriptionManagerSubscribeListen", subscriptionManagerSubscribeListen},
    {"SubscriptionManager::subscriptionManagerGet", subscriptionManagerGet},
    {"SubscriptionManager::subscriptionManagerGetSubscription", subscriptionManagerGetSubscription},
    {"SubscriptionManager::subscriptionManagerCancel", subscriptionManagerCancel},
    {"SubscriptionManager::subscriptionManagerRun", subscriptionManagerRun},
    {"SubscriptionManager::subscriptionManagerStop", subscriptionManagerStop},
    {"SubscriptionManager::subscriptionManagerSetAutoStop", subscriptionManagerSetAutoStop},
    {"SubscriptionManager::subscriptionManagerSetDefaultSettings", SubscriptionManagersubscriptionManagerSetDefaultSettings},
    {"SubscriptionManager::subscriptionManagerGetDefaultSettings", subscriptionManagerGetDefaultSettings},
    {"SubscriptionManager::subscriptionManagerSetAcceptMode", subscriptionManagerSetAcceptMode},
    {"SubscriptionManager::subscriptionManagerSetAcquireMode", subscriptionManagerSetAcquireMode},
    {"SubscriptionManager::subscriptionManagerGetSession", subscriptionManagerGetSession},
    
    
    /* End */
    {NULL, NULL}};


Dart_NativeFunction ResolveName(Dart_Handle name,
                                int argc,
                                bool* auto_setup_scope) {
  *auto_setup_scope = true;
  Dart_NativeFunction result;
  if (!Dart_IsString(name)) return NULL;
  Dart_EnterScope();
  const char* cname;
  HandleError(Dart_StringToCString(name, &cname));

  for (int i=0; function_list[i].name != NULL; ++i) {
    if (strcmp(function_list[i].name, cname) == 0) {
      result = function_list[i].function;
      break;
    }
  }
  
  Dart_ExitScope();
  return result; 
  
}
