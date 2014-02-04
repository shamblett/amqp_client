/* 
 * File:   ExtAll.cpp
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 20 January 2014, 08:34
 */

#include "ExtAll.h"

Dart_Handle HandleError(Dart_Handle handle) {
    
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
  
}

void throwAmqpcException(const char* message) {
    
    /* Create an exception class */
    Dart_Handle className = Dart_NewStringFromCString("AmqpcException");
    
    Dart_Handle type = Dart_GetType(Dart_RootLibrary(),
                                    className,
                                    0,
                                    NULL);
    
    Dart_Handle exception = HandleError(Dart_New(type,
                                        Dart_Null(),
                                        0,
                                        NULL));
    
    /* Set the message field */
    Dart_Handle value = Dart_NewStringFromCString(message);
    Dart_Handle name = Dart_NewStringFromCString("message");
    HandleError(Dart_SetField(exception,
                              name,
                              value));
    
    /* Throw the exception */
    Dart_Handle exceptionHandle = Dart_NewUnhandledExceptionError(exception);
    HandleError(Dart_ThrowException(exceptionHandle));
}

/**
 * createSession
 * 
 * @param session
 * @return Handle to a Dart Session class 
 */
Dart_Handle createSession(Session* session) {
    
    /* Create a Session class from our root library */
    Dart_Handle className = Dart_NewStringFromCString("AmqpcSession");
    Dart_Handle constructorName = Dart_NewStringFromCString("_nativeConstructor");
    
    Dart_Handle type = Dart_GetType(Dart_RootLibrary(),
                                    className,
                                    0,
                                    NULL);
    
    Dart_Handle sessionHandle = HandleError(Dart_New(type,
                                            constructorName,
                                            0,
                                            NULL));
    
    /* Set the session as the Dart Session objects peer pointer */
    HandleError(Dart_SetPeer(sessionHandle, session));
    
    /* Return it */
    return sessionHandle;
}

/**
 * getMessage
 * 
 * @param object
 * @return Session* 
 * 
 * Get the Message object from Dart
 */
Message* getMessage(Dart_Handle object ) {
    
    void* peer;
    HandleError(Dart_GetPeer(object, &peer));   
    Message* message = reinterpret_cast<Message*>(peer);
    return message;
}

/**
 * getSession
 * 
 * @param object
 * @return Session* 
 * 
 * Get the Session object from Dart
 */
Session* getSession(Dart_Handle object ) {
    
    void* peer;
    HandleError(Dart_GetPeer(object, &peer));   
    Session* session = reinterpret_cast<Session*>(peer);
    return session;
}

/**
 * get:LocalQueue
 * 
 * @param object
 * @return LocalQueue* 
 * 
 * Get the Local Queue object from Dart
 */
LocalQueue* getLocalQueue(Dart_Handle object ) {
    
    void* peer;
    HandleError(Dart_GetPeer(object, &peer));   
    LocalQueue* localQueue = reinterpret_cast<LocalQueue*>(peer);
    return localQueue;
}
/**
 * Create a Dart message class 
 *
 */
Dart_Handle createMessage(Message message) {
    
    /* Create a Message class from our root library */
    Dart_Handle className = Dart_NewStringFromCString("AmqpcMessage");
    Dart_Handle constructorName = Dart_NewStringFromCString("_nativeConstructor");
     
    Dart_Handle type = Dart_GetType(Dart_RootLibrary(),
                                    className,
                                    0,
                                    NULL);
    
    Dart_Handle messageClassHandle = HandleError(Dart_New(type,
                                       constructorName,
                                       0,
                                       NULL));
    
    /* Add the native message class to our Dart class */
    Message* newMessage = new Message(message);
    HandleError(Dart_SetPeer(messageClassHandle, newMessage));
    
    return messageClassHandle;
    
}

Dart_WeakPersistentHandle createMessagePersistent(Message message) {
    
    /* Create a Message class from our root library */
    Dart_Handle className = Dart_NewStringFromCString("AmqpcMessage");
    
    Dart_Handle type = Dart_GetType(Dart_RootLibrary(),
                                    className,
                                    0,
                                    NULL);
     
    Dart_Handle messageClassHandle = HandleError(Dart_Allocate(type));
            
    /* Add the native message class to our Dart class */
    Message* newMessage = new Message(message);
    HandleError(Dart_SetPeer(messageClassHandle, newMessage));
    
    Dart_WeakPersistentHandle returnHandle = Dart_NewWeakPersistentHandle(messageClassHandle,
                                                             NULL,
                                                             NULL);
    return returnHandle;
    
}

Dart_Handle getSubscriptionSettings(SubscriptionSettings subscriptionSettings) {
    
    /* Create a Reply To class from our root library */
    Dart_Handle className = Dart_NewStringFromCString("AmqpcSubscriptionSettings");
     
    Dart_Handle type = Dart_GetType(Dart_RootLibrary(),
                                    className,
                                    0,
                                    NULL);
    
    Dart_Handle settings = HandleError(Dart_New(type,
                                       Dart_Null(),
                                       0,
                                       NULL));
    Dart_Handle name = NULL;
    Dart_Handle value  = NULL;
    
    /* Accept Mode */
    name = Dart_NewStringFromCString("_acceptMode");
    value = Dart_NewInteger(subscriptionSettings.acceptMode);
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Acquire Mode */
    name = Dart_NewStringFromCString("_acquireMode");
    value = Dart_NewInteger(subscriptionSettings.acquireMode);
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Auto Acknowledge */
    name = Dart_NewStringFromCString("_autoAck");
    value = Dart_NewInteger(subscriptionSettings.autoAck);
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Completion Mode */
    name = Dart_NewStringFromCString("_completionMode");
    value = Dart_NewInteger(subscriptionSettings.completionMode);
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Exclusive  */
    name = Dart_NewStringFromCString("_exclusive");
    value = Dart_NewBoolean(subscriptionSettings.exclusive);
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Return the settings */
    return settings;
    
}

SubscriptionSettings setSubscriptionSettings(Dart_Handle object) {
    
    /* Create a Reply To class from our root library */
    
    Dart_Handle name = NULL;
    Dart_Handle value  = NULL;
    SubscriptionSettings settings;
    
    /* Accept Mode */
    name = Dart_NewStringFromCString("_acceptMode");
    value = HandleError(Dart_GetField(object, name));
    int64_t acceptMode = 0;
    HandleError(Dart_IntegerToInt64(value, &acceptMode));
    settings.acceptMode = (qpid::framing::message::AcceptMode)acceptMode;
    
    /* Acquire Mode */
    name = Dart_NewStringFromCString("_acquireMode");
    value = HandleError(Dart_GetField(object, name));
    int64_t acquireMode = 0;
    HandleError(Dart_IntegerToInt64(value, &acquireMode));
    settings.acquireMode = (qpid::framing::message::AcquireMode)acquireMode;
    
    /* Auto Acknowledge */
    name = Dart_NewStringFromCString("_autoAck");
    value = HandleError(Dart_GetField(object, name));
    int64_t autoAck = 0;
    HandleError(Dart_IntegerToInt64(value, &autoAck));
    settings.autoAck = autoAck;
    
    /* Completion Mode */
    name = Dart_NewStringFromCString("_completionMode");
    value = HandleError(Dart_GetField(object, name));
    int64_t completionMode = 0;
    HandleError(Dart_IntegerToInt64(value, &completionMode));
    settings.completionMode = (qpid::client::CompletionMode)completionMode;
    
    /* Exclusive  */
    name = Dart_NewStringFromCString("_exclusive");
    value = HandleError(Dart_GetField(object, name));
    bool exclusive;
    HandleError(Dart_BooleanValue(value, &exclusive));    
    settings.exclusive = exclusive;
    
    /* Return the settings */
    return settings;
    
}