/* 
 * File:   ExtSubscription.cpp
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 29 January 2014, 13:23
 */

#include "ExtSubscription.h"

/* Private functions */

/**
 * getSubscription
 * 
 * @param object
 * @return Subscription* 
 * 
 * Get the Subscription object from Dart
 */
Subscription* getSubscription(Dart_Handle object ) {
    
    void* peer;
    HandleError(Dart_GetPeer(object, &peer));   
    Subscription* subscription = reinterpret_cast<Subscription*>(peer);
    return subscription;
}

/**
 * subscriptionFinalizer
 * 
 * @param subscriptionHandle
 * @param peer
 */
void subscriptionFinalizer(Dart_Handle subscriptionHandle,
                           void* peer) {
    
    /* Close and release the subscription object */
    Subscription* subscription = reinterpret_cast<Subscription*>(peer);
    delete subscription;
    
}

/**
 * createSubscriptionManager
 * 
 * @param subscriptionManager
 * @return Handle to a Dart SubscriptionManager class 
 */
Dart_Handle createSubscriptionManager(SubscriptionManager* manager) {
    
    /* Create a SubscriptionManager class from our root library */
    Dart_Handle className = Dart_NewStringFromCString("AmqpcSubscriptionManager");
    Dart_Handle constructorName = Dart_NewStringFromCString("_nativeConstructor");
    
    Dart_Handle type = Dart_GetType(Dart_RootLibrary(),
                                    className,
                                    0,
                                    NULL);
    
    Dart_Handle managerHandle = HandleError(Dart_New(type,
                                            constructorName,
                                            0,
                                            NULL));
    
    /* Set the manager as the Dart Subscription Manager objects peer pointer */
    HandleError(Dart_SetPeer(managerHandle, manager));
    
    /* Return it */
    return managerHandle;
}

/* Public functions */

void subscriptionGetName(Dart_NativeArguments arguments) {
    
    
    std::string name;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Call the Subscription method */
    if ( Dart_IsInstance(object)) {
        
        Subscription* subscription = getSubscription(object);
        
        try {
            name = subscription->getName();
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
    /* Return the name string */
    Dart_Handle nameHandle = HandleError(Dart_NewStringFromCString(name.c_str()));
    Dart_SetReturnValue(arguments, nameHandle);
    
}

void subscriptionGetQueue(Dart_NativeArguments arguments) {
    
    
    std::string queue;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Call the Subscription method */
    if ( Dart_IsInstance(object)) {
        
        Subscription* subscription = getSubscription(object);
        
        try {
            queue = subscription->getQueue();
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
    /* Return the queue string */
    Dart_Handle queueHandle = HandleError(Dart_NewStringFromCString(queue.c_str()));
    Dart_SetReturnValue(arguments, queueHandle);
    
}

void subscriptionGetSettings(Dart_NativeArguments arguments) {
    
    SubscriptionSettings settings = SubscriptionSettings();
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Call the Subscription method */
    if ( Dart_IsInstance(object)) {
        
        Subscription* subscription = getSubscription(object);
        
        try {
            settings = subscription->getSettings();
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
    /* Create the subscription settings class and return it */
    Dart_Handle subscriptionSettingsHandle = getSubscriptionSettings(settings);
    Dart_SetReturnValue(arguments, subscriptionSettingsHandle);
    
}

void subscriptionSetAutoAck(Dart_NativeArguments arguments) {
    
    int64_t batch = 0;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    HandleError(Dart_GetNativeIntegerArgument(arguments, 1, &batch));
    
    /* Call the Subscription method */
    if ( Dart_IsInstance(object)) {
        
        Subscription* subscription = getSubscription(object);
        
        try {
            subscription->setAutoAck(batch);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
}

void subscriptionGetSession(Dart_NativeArguments arguments) {
    
    Session newSession = Session();
    Session* session = NULL;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Call the Subscription method */
    if ( Dart_IsInstance(object)) {
        
        Subscription* subscription = getSubscription(object);
        
        try {
            newSession = subscription->getSession();
            session = new Session(newSession);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
    /* Create the session class and return it */
    Dart_Handle subscriptionSessionHandle = createSession(session);
    Dart_SetReturnValue(arguments, subscriptionSessionHandle);
    
}

void subscriptionAcquire(Dart_NativeArguments arguments) {
    
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    Dart_Handle messageObject =  HandleError(Dart_GetNativeArgument(arguments, 1));
    Message* message = getMessage(messageObject);
    
    /* Call the Subscription method */
    if ( Dart_IsInstance(object)) {
        
        Subscription* subscription = getSubscription(object);
        
        try {
            subscription->acquire(*message);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
}

void subscriptionAccept(Dart_NativeArguments arguments) {
    
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    Dart_Handle messageObject =  HandleError(Dart_GetNativeArgument(arguments, 1));
    Message* message = getMessage(messageObject);
    
    /* Call the Subscription method */
    if ( Dart_IsInstance(object)) {
        
        Subscription* subscription = getSubscription(object);
        
        try {
            subscription->accept(*message);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
}

void subscriptionRelease(Dart_NativeArguments arguments) {
    
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    Dart_Handle messageObject =  HandleError(Dart_GetNativeArgument(arguments, 1));
    Message* message = getMessage(messageObject);
    
    /* Call the Subscription method */
    if ( Dart_IsInstance(object)) {
        
        Subscription* subscription = getSubscription(object);
        
        try {
            subscription->release(*message);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
}

void subscriptionCancel(Dart_NativeArguments arguments) {
    
     /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Call the Subscription method */
    if ( Dart_IsInstance(object)) {
        
        Subscription* subscription = getSubscription(object);
        
        try {
            subscription->cancel();
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
}

void subscriptionGetSubscriptionmanager(Dart_NativeArguments arguments) {
    
    SubscriptionManager* subscriptionManager = NULL;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Call the Subscription method */
    if ( Dart_IsInstance(object)) {
        
        Subscription* subscription = getSubscription(object);
        
        try {
            SubscriptionManager newSubscriptionManager = subscription->getSubscriptionManager();
            subscriptionManager = new SubscriptionManager(newSubscriptionManager);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
    /* Create the session class and return it */
    Dart_Handle subscriptionManagerHandle = createSubscriptionManager(subscriptionManager);
    Dart_SetReturnValue(arguments, subscriptionManagerHandle);
    
}
    