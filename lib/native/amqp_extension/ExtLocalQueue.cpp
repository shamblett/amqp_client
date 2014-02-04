/* 
 * File:   ExtLocalQueue.cpp
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 20 January 2014, 08:12
 */

#include "ExtLocalQueue.h"

/* Private functions */

/**
 * localQueueFinalizer
 * 
 * @param localQueueHandle
 * @param peer
 */
void localQueueFinalizer(Dart_Handle localQueueHandle,
                         void* peer) {
    
    /* Close and release the local queue object */
    LocalQueue* localQueue = reinterpret_cast<LocalQueue*>(peer);
    delete localQueue;
    
}

/* Public functions */

void localQueueLocalQueue(Dart_NativeArguments arguments) {
    
     Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
     LocalQueue* newLocalQueue = new LocalQueue();
     
     /* Set the connection as the Dart objects peer pointer */
     HandleError(Dart_SetPeer(object, newLocalQueue));
     
     /**
      * Wrap the local queue in a weak persistent handle, if the Dart
      * GC then reclaims this object as it is not in scope we can close
      * the connection cleanly and release it.
     */
     Dart_WeakPersistentHandle localQueueHandle = Dart_NewWeakPersistentHandle(
                                                    object,
                                                    newLocalQueue,
                                                    (Dart_WeakPersistentHandleFinalizer)localQueueFinalizer);
}

void localQueueGet(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    int64_t timeout;
    HandleError(Dart_GetNativeIntegerArgument(arguments, 1, &timeout));
    if ( timeout == -1 ) timeout = sys::TIME_INFINITE;
    
    LocalQueue localQueue = LocalQueue();
    Message message = Message();
      
    /* Call the Local Queue  method */
    if ( Dart_IsInstance(object)) {
        
        LocalQueue* localQueue = getLocalQueue(object);
        try {
            message = localQueue->get(timeout);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
    /* Create the message class and return it */
    Dart_Handle messageHandle = HandleError(createMessage(message));
    
    /* Return it */
    Dart_SetReturnValue(arguments, messageHandle); 
    
}

void localQueuePop(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    int64_t timeout;
    HandleError(Dart_GetNativeIntegerArgument(arguments, 1, &timeout));
    if ( timeout == -1 ) timeout = sys::TIME_INFINITE;
    
    LocalQueue localQueue = LocalQueue();
    Message message = Message();
      
    /* Call the Local Queue  method */
    if ( Dart_IsInstance(object)) {
        
        LocalQueue* localQueue = getLocalQueue(object);
        try {
            message = localQueue->pop(timeout);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
    /* Create the message class and return it */
    Dart_Handle messageHandle = HandleError(createMessage(message));
    
    /* Return it */
    Dart_SetReturnValue(arguments, messageHandle); 
    
}

void localQueueSize(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    size_t size = 0;
    
    /* Call the Local Queue  method */
    if ( Dart_IsInstance(object)) {
        
        LocalQueue* localQueue = getLocalQueue(object);
        try {
            size = localQueue->size();
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
    /* Return the size */
    Dart_SetReturnValue(arguments, HandleError(Dart_NewInteger(size)));
    
}



