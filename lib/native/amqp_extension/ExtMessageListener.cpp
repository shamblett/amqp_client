/* 
 * File:   ExtMessageListener.cpp
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 30 January 2014, 09:50
 */

#include "ExtMessageListener.h"

ExtMessageListener::ExtMessageListener(Dart_WeakPersistentHandle classHandle) {
    
    object = classHandle;
    
}

ExtMessageListener::~ExtMessageListener(){}

void ExtMessageListener::received(Message& msg) {
    
   /* Create our message class */
    Dart_WeakPersistentHandle messageHandle = createMessagePersistent(msg);
    
    /* Invoke the listener function on the Subscription Management class */
    Dart_Handle name = Dart_NewStringFromCString("nativeListenerCallback");
    Dart_Handle arguments[1]; 
    arguments[0] = (Dart_Handle)messageHandle;
    HandleError(Dart_Invoke((Dart_Handle)object,
                            name,
                            1,
                            arguments));
    

}

Dart_WeakPersistentHandle ExtMessageListener::getObject() {
    
    return object;
    
}
