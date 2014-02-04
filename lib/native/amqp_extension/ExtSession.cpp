/* 
 * File:   ExtSession.cpp
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 22 January 2014, 15:42
 */

#include "ExtSession.h"

/* Private functions */


Dart_Handle getboundResult(ExchangeBoundResult result) {
    
    /* Create an ExchangeBoundResult class from our root library */
    Dart_Handle className = Dart_NewStringFromCString("AmqpcExchangeBoundResult");
    
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
    
    /* Exchange Not Found  */
    name = Dart_NewStringFromCString("_exchangeNotFound");
    value = Dart_NewBoolean(result.getExchangeNotFound());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Queue Not Found  */
    name = Dart_NewStringFromCString("_queueNotFound");
    value = Dart_NewBoolean(result.getQueueNotFound());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Queue Not Matched  */
    name = Dart_NewStringFromCString("_queueNotMatched");
    value = Dart_NewBoolean(result.getQueueNotMatched());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Key Not Matched  */
    name = Dart_NewStringFromCString("_keyNotMatched");
    value = Dart_NewBoolean(result.getKeyNotMatched());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Key Not Matched  */
    name = Dart_NewStringFromCString("_keyNotMatched");
    value = Dart_NewBoolean(result.getKeyNotMatched());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Arguments Not Matched  */
    name = Dart_NewStringFromCString("_argsNotMatched");
    value = Dart_NewBoolean(result.getArgsNotMatched());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Return value */
    return settings;
    
}
/* Public functions */

void sessionExecutionSync(Dart_NativeArguments arguments) {
    
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 1, &sync));
    
    /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
            session->executionSync(sync);
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }

}

void sessionMessageTransfer(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    const char* destination = NULL;
    int64_t acceptMode = 1;
    int64_t acquireMode = 0;
    void* peer;
    
     /* Destination */
    Dart_Handle destinationString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(destinationString, &destination));
    
    /* Accept Mode */
    HandleError(Dart_GetNativeIntegerArgument(arguments, 2, &acceptMode));
    
    /* Acquire Mode */
    HandleError(Dart_GetNativeIntegerArgument(arguments, 3, &acquireMode));
    
    /* Message */
    Dart_Handle messageObject = HandleError(Dart_GetNativeArgument(arguments, 4));
    HandleError(Dart_GetPeer(messageObject, &peer));   
    Message* message = reinterpret_cast<Message*>(peer);
   
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 5, &sync));
   
    /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
            session->messageTransfer(destination,
                                     acceptMode,
                                     acquireMode,
                                     *message,
                                     sync);
             
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
}

void sessionMessageSubscribe(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    const char* queue = NULL;
    const char* destination = NULL;
    int64_t acceptMode = 1;
    int64_t acquireMode = 0;
    bool exclusive = false;
    const char* resumeId = NULL;
    FieldTable table = FieldTable();
    int64_t resumeTTL = 0;
    void* peer;
    
    /* Queue */
    Dart_Handle queueString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(queueString, &queue));
    
    /* Destination */
    Dart_Handle destinationString = HandleError(Dart_GetNativeStringArgument(arguments, 2, &peer));
    HandleError(Dart_StringToCString(destinationString, &destination));
    
    /* Accept Mode */
    HandleError(Dart_GetNativeIntegerArgument(arguments, 3, &acceptMode));
    
    /* Acquire Mode */
    HandleError(Dart_GetNativeIntegerArgument(arguments, 4, &acquireMode));
    
    /* Exclusive */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 5, &exclusive));
   
    /* Resume Id */
    Dart_Handle resumeIdString = HandleError(Dart_GetNativeStringArgument(arguments, 6, &peer));
    HandleError(Dart_StringToCString(destinationString, &resumeId));
    
    /* Resume TTL */
    HandleError(Dart_GetNativeIntegerArgument(arguments, 7, &resumeTTL));
    
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 8, &sync));
    
    /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
            session->messageSubscribe(queue,
                                      destination,
                                      acceptMode,
                                      acquireMode,
                                      exclusive,
                                      resumeId,
                                      resumeTTL,
                                      table,
                                      sync);
             
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
       
}

void sessionMessageCancel(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    const char* destination = NULL;
    void* peer;
    
     /* Destination */
    Dart_Handle destinationString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(destinationString, &destination));
    
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 2, &sync));
    
     /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
            session->messageCancel(destination,
                                   sync);
             
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
}

void sessionMessageFlush(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    const char* destination = NULL;
    void* peer;
    
     /* Destination */
    Dart_Handle destinationString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(destinationString, &destination));
    
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 2, &sync));
    
     /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
            session->messageFlush(destination,
                                  sync);
             
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
}

void sessionMessageStop(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    const char* destination = NULL;
    void* peer;
    
     /* Destination */
    Dart_Handle destinationString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(destinationString, &destination));
    
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 2, &sync));
    
     /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
            session->messageStop(destination,
                                 sync);
             
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
}

void sessionExchangeDeclare(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    const char* exchange = NULL;
    const char* type = NULL;
    const char* altExchange = NULL;
    bool passive = false;
    bool durable = false;
    bool autoDelete = false;
    FieldTable table = FieldTable();
    void* peer;
    
    /* Exchange */
    Dart_Handle exchangeString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(exchangeString, &exchange));
    
    /* Type */
    Dart_Handle typeString = HandleError(Dart_GetNativeStringArgument(arguments, 2, &peer));
    HandleError(Dart_StringToCString(typeString, &type));
    
    /* Alternate Exchange */
    Dart_Handle altExchangeString = HandleError(Dart_GetNativeStringArgument(arguments, 3, &peer));
    HandleError(Dart_StringToCString(altExchangeString, &altExchange));
    
    /* Passive */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 4, &passive));
   
    /* Durable */
     HandleError(Dart_GetNativeBooleanArgument(arguments, 5, &durable));
    
    /* Auto Delete */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 6, &autoDelete));
     
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 7, &sync));
    
    /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
            session->exchangeDeclare(exchange,
                                     type,
                                     altExchange,
                                     passive,
                                     durable,
                                     autoDelete,
                                     table,
                                     sync);
             
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    } 
      
}

void sessionExchangeDelete(Dart_NativeArguments arguments) {
    
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    const char* exchange = NULL;
    bool ifUnused = false;
    FieldTable table = FieldTable();
    void* peer;
    
    /* Exchange */
    Dart_Handle exchangeString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(exchangeString, &exchange));
    
    /* If Unused */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 2, &ifUnused));
    
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 3, &sync));
    
    /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
            session->exchangeDelete(exchange,
                                    ifUnused,
                                    sync);
             
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    } 
}

void sessionExchangeBind(Dart_NativeArguments arguments) {
    
  /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    const char* queue = NULL;
    const char* exchange = NULL;
    const char* bindingKey = NULL;
    FieldTable table = FieldTable();
    void* peer;
    
    /* Queue */
    Dart_Handle queueString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(queueString, &queue));
    
    /* Exchange  */
    Dart_Handle exchangeString = HandleError(Dart_GetNativeStringArgument(arguments, 2, &peer));
    HandleError(Dart_StringToCString(exchangeString, &exchange));
      
    /* Binding Key  */
    Dart_Handle bindingKeyString = HandleError(Dart_GetNativeStringArgument(arguments, 3, &peer));
    HandleError(Dart_StringToCString(bindingKeyString, &bindingKey));
    
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 4, &sync));
    
    /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
            session->exchangeBind(queue,
                                  exchange,
                                  bindingKey,
                                  table,
                                  sync);
             
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    } 
    
}

void sessionExchangeUnbind(Dart_NativeArguments arguments) {
    
  /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    const char* queue = NULL;
    const char* exchange = NULL;
    const char* bindingKey = NULL;
    void* peer;
    
    /* Queue */
    Dart_Handle queueString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(queueString, &queue));
    
    /* Exchange  */
    Dart_Handle exchangeString = HandleError(Dart_GetNativeStringArgument(arguments, 2, &peer));
    HandleError(Dart_StringToCString(exchangeString, &exchange));
      
    /* Binding Key  */
    Dart_Handle bindingKeyString = HandleError(Dart_GetNativeStringArgument(arguments, 3, &peer));
    HandleError(Dart_StringToCString(bindingKeyString, &bindingKey));
    
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 4, &sync));
    
    /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
            session->exchangeUnbind(queue,
                                  exchange,
                                  bindingKey,
                                  sync);
             
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    } 
    
}

void sessionQueueDeclare(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    const char* queue = NULL;
    const char* altExchange = NULL;
    bool passive = false;
    bool durable = false;
    bool exclusive = false;
    bool autoDelete = false;
    FieldTable table = FieldTable();
    void* peer;
    
    /* Queue  */
    Dart_Handle queueString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(queueString, &queue));
    
    /* Alternate Exchange */
    Dart_Handle altExchangeString = HandleError(Dart_GetNativeStringArgument(arguments, 2, &peer));
    HandleError(Dart_StringToCString(altExchangeString, &altExchange));
    
    /* Passive */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 3, &passive));
   
    /* Durable */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 4, &durable));
    
     /* Exclusive */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 5, &exclusive));
    
    /* Auto Delete */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 6, &autoDelete));
     
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 7, &sync));
    
    /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
            session->queueDeclare(queue,
                                  altExchange,
                                  passive,
                                  durable,
                                  exclusive,
                                  autoDelete,
                                  table,
                                  sync);
             
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    } 
    
}

void sessionQueueDelete(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    const char* queue = NULL;
    bool ifUnused = false;
    bool empty = false;
    void* peer;
    
    /* Queue  */
    Dart_Handle queueString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(queueString, &queue));
    
    /* If Unused */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 2, &ifUnused));
    
    /* Empty */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 3, &empty));
    
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 4, &sync));
    
    /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
            session->queueDelete(queue,
                                 ifUnused,
                                 empty,
                                 sync);
             
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
}

void sessionQueuePurge(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    const char* queue = NULL;
    void* peer;
    
    /* Queue  */
    Dart_Handle queueString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(queueString, &queue));
    
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 2, &sync));
    
    /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
            session->queuePurge(queue,
                                sync);
             
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
}

void sessionExchangeBound(Dart_NativeArguments arguments) {
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    bool sync = true;
    const char* queue = NULL;
    const char* exchange = NULL;
    const char* bindingKey = NULL;
    FieldTable table = FieldTable();
    void* peer;
    ExchangeBoundResult boundResult = ExchangeBoundResult();
    
    /* Exchange  */
    Dart_Handle exchangeString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(exchangeString, &exchange));
    
    /* Queue */
    Dart_Handle queueString = HandleError(Dart_GetNativeStringArgument(arguments, 2, &peer));
    HandleError(Dart_StringToCString(queueString, &queue));
      
    /* Binding Key  */
    Dart_Handle bindingKeyString = HandleError(Dart_GetNativeStringArgument(arguments, 3, &peer));
    HandleError(Dart_StringToCString(bindingKeyString, &bindingKey));
    
    /* Sync flag */
    HandleError(Dart_GetNativeBooleanArgument(arguments, 4, &sync));
    
    /* Call the session method */
    if ( Dart_IsInstance(object)) {
        
        Session* session = getSession(object);
        try {
           boundResult =  session->exchangeBound(exchange,
                                                 queue,
                                                 bindingKey,
                                                 table,
                                                 sync);
             
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
     /* Construct our Exchange Bound Results  class */
    Dart_Handle boundResultHandle = HandleError(getboundResult(boundResult));
    
    /* Return it */
    Dart_SetReturnValue(arguments, boundResultHandle); 
}