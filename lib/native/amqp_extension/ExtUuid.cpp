/* 
 * File:   ExtUid.cpp
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 20 January 2014, 08:12
 */

#include "ExtUuid.h"

/* Private functions */

/**
 * getUuid
 * 
 * @param object
 * @return Uuid* 
 * 
 * Get the Uuid object from Dart
 */
Uuid* getUuid(Dart_Handle object ) {
    
    void* peer;
    HandleError(Dart_GetPeer(object, &peer));   
    Uuid* uuid = reinterpret_cast<Uuid*>(peer);
    return uuid;
}

/**
 * uuidFinalizer
 * 
 * @param uuidHandle
 * @param peer
 */
void uuidFinalizer(Dart_Handle uuidHandle,
                   void* peer) {
    
    /* Close and release the uuid object */
    Uuid* uuid  = reinterpret_cast<Uuid*>(peer);
    delete uuid;
    
}

/* Public functions */

void uuidUuid(Dart_NativeArguments arguments) {
    
     
     /* Construct the native uuid object */
     Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
     Dart_Handle name = NULL;
     Dart_Handle fieldHandle = NULL;
     
     /* Unique */
     bool unique = false;
     name = Dart_NewStringFromCString("_unique");
     fieldHandle = HandleError(Dart_GetField(object, name));
     if ( !Dart_IsNull(fieldHandle)) {
       
        HandleError(Dart_BooleanValue(fieldHandle, &unique));
     }
    
     Uuid* newUuid = new Uuid(unique);
     
     /* Set the uuid as the Dart objects peer pointer */
     HandleError(Dart_SetPeer(object, newUuid));
     
     /**
      * Wrap the uuid in a weak persistent handle, if the Dart
      * GC then reclaims this object as it is not in scope we can close
      * the connection cleanly and release it.
     */
     Dart_WeakPersistentHandle uuidHandle = Dart_NewWeakPersistentHandle(
                                                    object,
                                                    newUuid,
                                                    (Dart_WeakPersistentHandleFinalizer)uuidFinalizer);
}

void uuidGenerate(Dart_NativeArguments arguments) {
    
    /* Construct the native uuid object */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    Uuid* uuid = getUuid(object);
    
    if ( Dart_IsInstance(object)) {
        
        try {
            uuid->generate();
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    }
    
}

void uuidStr(Dart_NativeArguments arguments) {
    
    /* Construct the native uuid object */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    Uuid* uuid = getUuid(object);
    std::string str;
    
    if ( Dart_IsInstance(object)) {
        
        try {
            str = uuid->str();
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    }
    
    /* Return value */
   Dart_Handle uuidHandle = HandleError(Dart_NewStringFromCString(str.c_str()));
   Dart_SetReturnValue(arguments, uuidHandle); 
    
}

void uuidClear(Dart_NativeArguments arguments) {
    
   /* Construct the native uuid object */
   Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    Uuid* uuid = getUuid(object);
    
    if ( Dart_IsInstance(object)) {
        
        try {
            uuid->clear();
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    }
     
}

void uuidIsNull(Dart_NativeArguments arguments) {
    
    /* Construct the native uuid object */
   Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
   Uuid* uuid = getUuid(object);
   bool isNull = false;
   
    if ( Dart_IsInstance(object)) {
        
        try {
            isNull = uuid->isNull();
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }    
        
    }
    
   /* Return value */
   Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(isNull)));
   
}