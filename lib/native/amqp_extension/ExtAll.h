/* 
 * File:   ExtAll.h
 * Package: amqp_extension
 * Author: Steve Hamblett
 * Copyright steve@OSCF 2014
 *
 * Created on 20 January 2014, 08:06
 */

#ifndef EXTALL_H
#define	EXTALL_H

/* General includes */
#include <ostream>

/* AMQP includes */
#include "qpid/client/Connection.h"
#include "qpid/client/Message.h"
#include "qpid/client/Session.h"
#include "qpid/client/SubscriptionManager.h" 

using namespace qpid;
using namespace qpid::client;
using namespace qpid::framing;

/* Dart includes */
#include "include/dart_api.h"
#include "include/dart_native_api.h"

/**
 * General library wide native functions
 */
Dart_NativeFunction ResolveName(Dart_Handle name,
                                int argc,
                                bool* auto_setup_scope);

/**
 * General library wide Dart handle checker
 */

Dart_Handle HandleError(Dart_Handle handle);

/**
 * General library wide exception thrower
 */
void throwAmqpcException(const char* message);

/**
 * Creates a Dart Session class from a QPID Session object
 */
Dart_Handle createSession(Session* session);
    
/**
 * 
 * Get a Message object from Dart
 */
Message* getMessage(Dart_Handle object );

/**
 * Get a session object
 */
Session* getSession(Dart_Handle object );

/**
 * Get a local queue object
 */
LocalQueue* getLocalQueue(Dart_Handle object );

/**
 * Create a Dart message class 
 */
Dart_Handle createMessage(Message message);

/*
 * Get a subscriptions settings
 */
Dart_Handle getSubscriptionSettings(SubscriptionSettings subscriptionSettings);

/**
 *  Set a subscriptions settings
 */
SubscriptionSettings setSubscriptionSettings(Dart_Handle object);

/**
 * 
 * Create a weak persistent message 
 */
Dart_WeakPersistentHandle createMessagePersistent(Message message);

#endif	/* EXTALL_H */

