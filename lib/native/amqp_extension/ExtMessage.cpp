/* 
 * File:   ExtMessage.cpp
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 23 January 2014, 14:37
 */
#include "ExtMessage.h"

/* Private functions */

/**
 * messageFinalizer
 * 
 * @param messageHandle
 * @param peer
 */
void messageFinalizer(Dart_Handle messageHandle,
                         void* peer) {
    
    /* Close and release the message object */
    Message* message = reinterpret_cast<Message*>(peer);
    delete message;
    
}

Dart_Handle getMessageId(Uuid uuid) {
    
    /* Create a Uuid class from our root library */
    Dart_Handle className = Dart_NewStringFromCString("AmqpcUuid");
    Dart_Handle constructorName = Dart_NewStringFromCString("_nativeConstructor");
     
    Dart_Handle type = Dart_GetType(Dart_RootLibrary(),
                                    className,
                                    0,
                                    NULL);
    
    Dart_Handle uuidClassHandle = HandleError(Dart_New(type,
                                       constructorName,
                                       0,
                                       NULL));
    
    /* Add the native Uuid class to our Dart class */
    Uuid* newUuid = new Uuid(uuid);
    HandleError(Dart_SetPeer(uuidClassHandle, newUuid));
    
    return uuidClassHandle;
    
}

Dart_Handle getReplyTo(ReplyTo replyTo) {
    
    /* Create a Reply To class from our root library */
    Dart_Handle className = Dart_NewStringFromCString("AmqpcReplyTo");
     
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
    
    /* Exchange */
    name = Dart_NewStringFromCString("exchange");
    value = Dart_NewStringFromCString(replyTo.getExchange().c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Routing Key */
    name = Dart_NewStringFromCString("routingKey");
    value = Dart_NewStringFromCString(replyTo.getRoutingKey().c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    /* Return the class */
    return settings;
            
}

Dart_Handle getMessageProperties(MessageProperties properties) {
    
    /* Create a MessageProperties class from our root library */
    Dart_Handle className = Dart_NewStringFromCString("AmqpcMessageProperties");
    
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
    
    /* Content Length */
    name = Dart_NewStringFromCString("contentLength");
    value = Dart_NewInteger(properties.getContentLength());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Message Identifier */
    name = Dart_NewStringFromCString("messageId");
    value = HandleError(getMessageId(properties.getMessageId()));
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Correlation Identifier */
    name = Dart_NewStringFromCString("correlationId");
    value = Dart_NewStringFromCString(properties.getCorrelationId().c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
   
    /* Reply To */
    name = Dart_NewStringFromCString("replyTo");
    value = HandleError(getReplyTo(properties.getReplyTo()));
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Content Type */
    name = Dart_NewStringFromCString("contentType");
    value = Dart_NewStringFromCString(properties.getContentType().c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Content Encoding */
    name = Dart_NewStringFromCString("contentEncoding");
    value = Dart_NewStringFromCString(properties.getContentEncoding().c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* User Identity */
    name = Dart_NewStringFromCString("userId");
    value = Dart_NewStringFromCString(properties.getUserId().c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
     /* Application Identity */
    name = Dart_NewStringFromCString("appId");
    value = Dart_NewStringFromCString(properties.getUserId().c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    return settings;
    
}

Dart_Handle getDeliveryProperties(DeliveryProperties properties) {
    
    /* Create a DeliveryProperties class from our root library */
    Dart_Handle className = Dart_NewStringFromCString("AmqpcDeliveryProperties");
    
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
    
    /*  Discard Unroutable */
    name = Dart_NewStringFromCString("discardUnroutable");
    value = Dart_NewBoolean(properties.getDiscardUnroutable());
    HandleError(Dart_SetField(settings,
                              name,
                              value));

    /* Immediate */
    name = Dart_NewStringFromCString("immediate");
    value = Dart_NewBoolean(properties.getImmediate());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    /* Redelivered */
    name = Dart_NewStringFromCString("redelivered");
    value = Dart_NewBoolean(properties.getImmediate());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Priority */
    name = Dart_NewStringFromCString("priority");
    value = Dart_NewInteger(properties.getPriority());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Delivery Mode */
    name = Dart_NewStringFromCString("deliveryMode");
    value = Dart_NewInteger(properties.getDeliveryMode());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    /* Time To Live  */
    name = Dart_NewStringFromCString("ttl");
    value = Dart_NewInteger(properties.getTtl());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Timestamp  */
    name = Dart_NewStringFromCString("timestamp");
    value = Dart_NewInteger(properties.getTimestamp());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Expiration Time  */
    name = Dart_NewStringFromCString("expiration");
    value = Dart_NewInteger(properties.getExpiration());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Exchange  */
    name = Dart_NewStringFromCString("exchange");
    value = Dart_NewStringFromCString(properties.getExchange().c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
   
    
    /* Routing Key */
    name = Dart_NewStringFromCString("routingKey");
    value = Dart_NewStringFromCString(properties.getRoutingKey().c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    
    /* Resume Identifier  */
    name = Dart_NewStringFromCString("resumeId");
    value = Dart_NewStringFromCString(properties.getResumeId().c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Resume Time To Live  */
    name = Dart_NewStringFromCString("resumeTtl");
    value = Dart_NewInteger(properties.getResumeTtl());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
   
    return settings;
    
}
/* Public functions */

void messageMessage(Dart_NativeArguments arguments) {
    
     
     /* Construct the native message object */
     Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
     Dart_Handle name = NULL;
     Dart_Handle fieldHandle = NULL;
     
     /* Data */
     const char* data = NULL;
     name = Dart_NewStringFromCString("_data");
     fieldHandle = HandleError(Dart_GetField(object, name));
     if ( !Dart_IsNull(fieldHandle)) {
       
        HandleError(Dart_StringToCString(fieldHandle, &data));
     }
     
     /* Routing key */
     const char* routingKey = NULL;
     name = Dart_NewStringFromCString("_routingKey");
     fieldHandle = HandleError(Dart_GetField(object, name));
     if ( !Dart_IsNull(fieldHandle)) {
       
        HandleError(Dart_StringToCString(fieldHandle, &routingKey));
     }
     
     Message* newMessage = new Message(data, routingKey);
     
     /* Set the message as the Dart objects peer pointer */
     HandleError(Dart_SetPeer(object, newMessage));
     
     /**
      * Wrap the message in a weak persistent handle, if the Dart
      * GC then reclaims this object as it is not in scope we can close
      * the connection cleanly and release it.
     */
     Dart_WeakPersistentHandle connectionHandle = Dart_NewWeakPersistentHandle(
                                                    object,
                                                    newMessage,
                                                    (Dart_WeakPersistentHandleFinalizer)messageFinalizer);
}

/**
 * Equal operator
 * 
 * @param arguments
 */
void messageEquals(Dart_NativeArguments arguments){
    
    /* Construct the native message objects */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Dart_Handle objectToTest = HandleError(Dart_GetNativeArgument(arguments, 1)); 
    bool isEqual = false;
    
    /* Get the native message objects */
    Message* message = getMessage(object);
    Message* messageToTest = getMessage(objectToTest);
    
    if ( Dart_IsInstance(object)) {
        
        try {
            if ( message == messageToTest ) isEqual = true;
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    }
        
    /* Return value */
    Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(isEqual)));
}   

void messageGetData(Dart_NativeArguments arguments) {
    
    /* Construct the native message object */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Message* message = getMessage(object);
    std::string data;
    
    if ( Dart_IsInstance(object)) {
        
        try {
            data = message->getData();
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    }
    
    /* Return the data */
   Dart_Handle dataHandle = HandleError(Dart_NewStringFromCString(data.c_str()));
   Dart_SetReturnValue(arguments, dataHandle); 
    
}

void messageSetData(Dart_NativeArguments arguments){
    
    /* Construct the native message object */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Message* message = getMessage(object);
    
    /* Get the message body */
    const char* body = NULL;
    void* peer;
    
    Dart_Handle bodyString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(bodyString, &body));
    
    /* Set the body */
    if ( Dart_IsInstance(object)) {
        
        try {
             message->setData(body);
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    }   
    
}

void messageSwap(Dart_NativeArguments arguments) {
    
    /* Construct the native message objects */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Dart_Handle objectToSwap = HandleError(Dart_GetNativeArgument(arguments, 1));
    
    /* Get the native message objects */
    Message* message = getMessage(object);
    Message* messageToSwap = getMessage(objectToSwap);
    
    /* Do the swap */
    if ( Dart_IsInstance(object)) {
        
        try {
             message->swap(*messageToSwap);
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    }  
           
}

void messageAppendData(Dart_NativeArguments arguments) {
    
    /* Construct the native message object */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Message* message = getMessage(object);
    
    /* Get the message body */
    const char* body = NULL;
    void* peer;
    
    Dart_Handle bodyString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(bodyString, &body));
    
    /* Append  the body */
    if ( Dart_IsInstance(object)) {
        
        try {
             message->appendData(body);
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    }   
     
}

void messageHasMessageProperties(Dart_NativeArguments arguments) {
    
    /* Construct the native message object */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Message* message = getMessage(object);
    bool hasProperties = false;

    /* Get the properties flag */
    if ( Dart_IsInstance(object)) {
        
        try {
             hasProperties = message->hasMessageProperties();
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    } 
    
    /* Return value */
    Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(hasProperties)));
    
}

void messageHasDeliveryProperties(Dart_NativeArguments arguments) {
    
    /* Construct the native message object */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Message* message = getMessage(object);
    bool hasProperties = false;

    /* Get the properties flag */
    if ( Dart_IsInstance(object)) {
        
        try {
             hasProperties = message->hasMessageProperties();
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    } 
    
    /* Return value */
    Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(hasProperties)));
    
}

void messageGetMessageProperties(Dart_NativeArguments arguments) {
    
    /* Construct the native message object */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Message* message = getMessage(object);
    MessageProperties properties;
    
    /* Get the message properties */
    if ( Dart_IsInstance(object)) {
        
        try {
             properties = message->getMessageProperties();
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    } 
    
    /* Construct our Message Properties class */
    Dart_Handle messagePropertiesHandle = HandleError(getMessageProperties(properties));
    
    /* Return it */
    Dart_SetReturnValue(arguments, messagePropertiesHandle); 
    
    
    
}

void messageGetDeliveryProperties(Dart_NativeArguments arguments) {
    
    /* Construct the native message object */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Message* message = getMessage(object);
    DeliveryProperties properties;
    
    /* Get the message properties */
    if ( Dart_IsInstance(object)) {
        
        try {
             properties = message->getDeliveryProperties();
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    } 
    
    /* Construct our DeliveryProperties class */
    Dart_Handle deliveryPropertiesHandle = HandleError(getDeliveryProperties(properties));
    
    /* Return it */
    Dart_SetReturnValue(arguments, deliveryPropertiesHandle);    
    
}

void messageGetDestination(Dart_NativeArguments arguments) {
    
    /* Construct the native message object */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Message* message = getMessage(object);
    std::string destination;
    
    /* Get the message properties */
    if ( Dart_IsInstance(object)) {
        
        try {
             destination = message->getDestination();
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    } 
    
    /* Return value */
   Dart_Handle destinationHandle = HandleError(Dart_NewStringFromCString(destination.c_str()));
   Dart_SetReturnValue(arguments, destinationHandle); 
    
}

void messageIsRedelivered(Dart_NativeArguments arguments) {
    
    /* Construct the native message object */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Message* message = getMessage(object);
    bool reDelivered = false;
    
    /* Get the message re-delivered flag */
    if ( Dart_IsInstance(object)) {
        
        try {
             reDelivered = message->isRedelivered();
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    } 
    
    Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(reDelivered)));
    
}

void messageSetRedelivered(Dart_NativeArguments arguments) {
    
     /* Construct the native message object */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Message* message = getMessage(object);
    bool reDelivered = false;
    
    /* Get the argument */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 1, &reDelivered));

    /* Set the message re-delivered flag */
    if ( Dart_IsInstance(object)) {
        
        try {
             message->setRedelivered(reDelivered);
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    }
}

void messageGetId(Dart_NativeArguments arguments) {
    
    /* Construct the native message object */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Message* message = getMessage(object);
    uint32_t sequence = -1;
    
    /* Get the message sequence number */
    if ( Dart_IsInstance(object)) {
        
        try {
             SequenceNumber id = message->getId();
             sequence = id.getValue();
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    }
    
    /* Return value */
    Dart_SetReturnValue(arguments, HandleError(Dart_NewInteger(sequence)));
    
    
    
}