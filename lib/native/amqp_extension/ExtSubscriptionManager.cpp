/* 
 * File:   ExtSubscriptionManager.cpp
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 30 January 2014, 07:42
 */

#include "ExtSubscriptionManager.h"
#include "ExtMessageListener.h"

/* Private functions */

/**
 * getSubscriptionManager
 * 
 * @param object
 * @return SubscriptionManager* 
 * 
 * Get the SubscriptionManager object from Dart
 */
SubscriptionManager* getSubscriptionManager(Dart_Handle object ) {
    
    void* peer;
    HandleError(Dart_GetPeer(object, &peer));   
    SubscriptionManager* subscriptionManager = reinterpret_cast<SubscriptionManager*>(peer);
    return subscriptionManager;
}

/**
 * SubscriptionManagerFinalizer
 * 
 * @param SubscriptionManagerHandle
 * @param peer
 */
void subscriptionManagerFinalizer(Dart_Handle SubscriptionManagerHandle,
                                  void* peer) {
    
    /* Close and release the SubscriptionManager object */
    SubscriptionManager* subscriptionManager = reinterpret_cast<SubscriptionManager*>(peer);
    delete subscriptionManager;
    
}

/**
 * createSubscription
 * 
 * @param subscription
 * @return Handle to a Dart Subscription class 
 */
Dart_Handle createSubscription(Subscription* subscription) {
    
    /* Create a Subscription class from our root library */
    Dart_Handle className = Dart_NewStringFromCString("AmqpcSubscription");
    Dart_Handle constructorName = Dart_NewStringFromCString("_nativeConstructor");
    
    Dart_Handle type = Dart_GetType(Dart_RootLibrary(),
                                    className,
                                    0,
                                    NULL);
    
    Dart_Handle subscriptionHandle = HandleError(Dart_New(type,
                                            constructorName,
                                            0,
                                            NULL));
    
    /* Set the manager as the Dart Subscription objects peer pointer */
    HandleError(Dart_SetPeer(subscriptionHandle, subscription));
    
    /* Return it */
    return subscriptionHandle;
}

/* Public functions */

void SubscriptionManagersubscriptionManager(Dart_NativeArguments arguments) {
    
     Session* session = NULL;
    
     /* Construct the native SubscriptionManager object */
     Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
     
     /* Get the session parameter */
     session = getSession(HandleError(Dart_GetNativeArgument(arguments, 1)));
     
     /* Construct the Subscription Manager */
     SubscriptionManager* subscriptionManager = new SubscriptionManager(*session);
     
     /* Set the SubscriptionManager as the Dart objects peer pointer */
     HandleError(Dart_SetPeer(object, subscriptionManager));
     
     /**
      * Wrap the subscriptionManager in a weak persistent handle, if the Dart
      * GC then reclaims this object as it is not in scope we can close
      * the connection cleanly and release it.
     */
     Dart_WeakPersistentHandle connectionHandle = Dart_NewWeakPersistentHandle(
                                                    object,
                                                    subscriptionManager,
                                                    (Dart_WeakPersistentHandleFinalizer)subscriptionManagerFinalizer);
     
     
}

void subscriptionManagerSubscribeLocal(Dart_NativeArguments arguments) {
    
    const char* name = NULL;
    const char* queue = NULL;
    void* peer;
    Subscription subscription;
    Subscription* newSubscription = NULL;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Local Queue */
    Dart_Handle localQueueObject = HandleError(Dart_GetNativeArgument(arguments, 1));
    LocalQueue* localQueue = getLocalQueue(localQueueObject);
    
    /* Queue */
    Dart_Handle queueString = HandleError(Dart_GetNativeStringArgument(arguments, 2, &peer));
    HandleError(Dart_StringToCString(queueString, &queue));
    
    /* Name */
    Dart_Handle nameString = HandleError(Dart_GetNativeStringArgument(arguments, 3, &peer));
    HandleError(Dart_StringToCString(nameString, &name));
    
    /* Call the manager method */
    if ( Dart_IsInstance(object)) {
        
        SubscriptionManager* manager = getSubscriptionManager(object);
        try {
            subscription = manager->subscribe(*localQueue,
                                              queue,
                                              name);
            newSubscription = new Subscription(subscription);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }
        
    }
    
    /* Create and return the Subscription object */
    Dart_Handle subscriptionHandle = createSubscription(newSubscription);
    Dart_SetReturnValue(arguments, subscriptionHandle);
    
}

void subscriptionManagerSubscribeListen(Dart_NativeArguments arguments) {
    
    const char* name = NULL;
    const char* queue = NULL;
    void* peer;
    Subscription subscription;
    Subscription* newSubscription = NULL;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Queue */
    Dart_Handle queueString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(queueString, &queue));
    
    /* Name */
    Dart_Handle nameString = HandleError(Dart_GetNativeStringArgument(arguments, 2, &peer));
    HandleError(Dart_StringToCString(nameString, &name));
    
    /* Instantiate a message listener */
    Dart_WeakPersistentHandle newObject = Dart_NewWeakPersistentHandle(object, NULL, NULL);
    ExtMessageListener* listener = new ExtMessageListener(newObject);
    
    /* Call the manager method */
    if ( Dart_IsInstance(object)) {
        
        SubscriptionManager* manager = getSubscriptionManager(object);
        try {
            subscription = manager->subscribe(*listener,
                                              queue,
                                              name);
            newSubscription = new Subscription(subscription);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }
        
    }
    
     /* Create and return the Subscription object */
    Dart_Handle subscriptionHandle = createSubscription(newSubscription);
    Dart_SetReturnValue(arguments, subscriptionHandle);
    
}

void subscriptionManagerGet(Dart_NativeArguments arguments) {
    
    const char* queue = NULL;
    int64_t timeout;
    void* peer;
    Message message;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Queue */
    Dart_Handle queueString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(queueString, &queue));
    
    /* Timeout */
    HandleError(Dart_GetNativeIntegerArgument(arguments, 2, &timeout));
    if ( timeout == -1 ) timeout = sys::TIME_INFINITE;
    
    /* Call the manager method */
    if ( Dart_IsInstance(object)) {
        
        SubscriptionManager* manager = getSubscriptionManager(object);
        try {
            message = manager->get(queue,
                                   timeout);
            
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }
        
    }
    
    /* Create and return the message object */
    Dart_Handle messageHandle = createMessage(message);
    Dart_SetReturnValue(arguments, messageHandle);
    
}

void subscriptionManagerGetSubscription (Dart_NativeArguments arguments) {
    
    const char* name = NULL;
    void* peer;
    Subscription subscription;
    Subscription* newSubscription = NULL;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Name */
    Dart_Handle nameString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(nameString, &name));
    
    /* Call the manager method */
    if ( Dart_IsInstance(object)) {
        
        SubscriptionManager* manager = getSubscriptionManager(object);
        try {
            subscription = manager->getSubscription(name);
            newSubscription = new Subscription(subscription);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }
        
    }
    
     /* Create and return the Subscription object */
    Dart_Handle subscriptionHandle = createSubscription(newSubscription);
    Dart_SetReturnValue(arguments, subscriptionHandle);
    
}

void subscriptionManagerCancel(Dart_NativeArguments arguments) {
    
    const char* name = NULL;
    void* peer;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Name */
    Dart_Handle nameString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(nameString, &name));
    
    /* Call the manager method */
    if ( Dart_IsInstance(object)) {
        
        SubscriptionManager* manager = getSubscriptionManager(object);
        try {
            manager->cancel(name);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }
        
    }
    
}

void subscriptionManagerRun(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Call the manager method */
    if ( Dart_IsInstance(object)) {
        
        SubscriptionManager* manager = getSubscriptionManager(object);
        try {
            manager->run();
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }
        
    }
    
}

void subscriptionManagerStop(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Call the manager method */
    if ( Dart_IsInstance(object)) {
        
        SubscriptionManager* manager = getSubscriptionManager(object);
        try {
            manager->stop();
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }
        
    }
    
}

void subscriptionManagerSetAutoStop(Dart_NativeArguments arguments) {
    
    bool set = true;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Set */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 1, &set));
    
    /* Call the manager method */
    if ( Dart_IsInstance(object)) {
        
        SubscriptionManager* manager = getSubscriptionManager(object);
        try {
            manager->setAutoStop(set);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }
        
    }
}

void SubscriptionManagersubscriptionManagerSetDefaultSettings(Dart_NativeArguments arguments) {
    
    
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Set the subscription settings*/
    Dart_Handle settingsHandle = HandleError(Dart_GetNativeArgument(arguments, 1));
    SubscriptionSettings settings = setSubscriptionSettings(settingsHandle);
    
    /* Call the manager method */
    if ( Dart_IsInstance(object)) {
        
        SubscriptionManager* manager = getSubscriptionManager(object);
        try {
            manager->setDefaultSettings(settings);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }
        
    }  
    
}

void subscriptionManagerGetDefaultSettings(Dart_NativeArguments arguments) {
    
    
    SubscriptionSettings settings;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Call the manager method */
    if ( Dart_IsInstance(object)) {
        
        SubscriptionManager* manager = getSubscriptionManager(object);
        try {
            settings = manager->getDefaultSettings();
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }
        
    }  
    
    /* Return the settings */
    Dart_Handle settingsHandle = getSubscriptionSettings(settings);
    Dart_SetReturnValue(arguments, settingsHandle);
    
}

void subscriptionManagerSetAcceptMode(Dart_NativeArguments arguments) {
    
    int64_t acceptMode;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Accept Mode */
    HandleError(Dart_GetNativeIntegerArgument(arguments, 1, &acceptMode));
    
    /* Call the manager method */
    if ( Dart_IsInstance(object)) {
        
        SubscriptionManager* manager = getSubscriptionManager(object);
        try {
            manager->setAcceptMode((qpid::framing::message::AcceptMode)acceptMode);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }
        
    }
}

void subscriptionManagerSetAcquireMode(Dart_NativeArguments arguments) {
    
    int64_t acquireMode;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Acquire Mode */
    HandleError(Dart_GetNativeIntegerArgument(arguments, 1, &acquireMode));
    
    /* Call the manager method */
    if ( Dart_IsInstance(object)) {
        
        SubscriptionManager* manager = getSubscriptionManager(object);
        try {
            manager->setAcquireMode((qpid::framing::message::AcquireMode)acquireMode);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }
        
    }
}

void subscriptionManagerGetSession(Dart_NativeArguments arguments) {
    
    
    Session newSession = Session();
    Session* session = NULL;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Call the manager method */
    if ( Dart_IsInstance(object)) {
        
        SubscriptionManager* manager = getSubscriptionManager(object);
        
        try {
            newSession = manager->getSession();
            session = new Session(newSession);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
    /* Create the session class and return it */
    Dart_Handle subscriptionSessionHandle = createSession(session);
    Dart_SetReturnValue(arguments, subscriptionSessionHandle);
    
}