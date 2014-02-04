/* 
 * File:   ExtConnection.cpp
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 20 January 2014, 08:12
 */

#include "ExtConnection.h"

/* Private functions */

/**
 * getConnection
 * 
 * @param object
 * @return Connection* 
 * 
 * Get the Connection object from Dart
 */
Connection* getConnection(Dart_Handle object ) {
    
    void* peer;
    HandleError(Dart_GetPeer(object, &peer));   
    Connection* connection = reinterpret_cast<Connection*>(peer);
    return connection;
}

/**
 * getConnectionSettings
 * 
 * @param object
 * @return ConnectionSettings
 * 
 * Creates a QPID connection settings object from the Dart class
 */
ConnectionSettings getConnectionSettings(Dart_Handle object) {
    
    Dart_Handle name = NULL;
    Dart_Handle fieldHandle = NULL;
    
    ConnectionSettings settings = ConnectionSettings();
 
    /* Protocol */
    name = Dart_NewStringFromCString("protocol");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        const char* protocol;
        HandleError(Dart_StringToCString(fieldHandle, &protocol));
        settings.protocol = protocol; 
    }
    
    /* Host */
    name = Dart_NewStringFromCString("host");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        const char* host;
        HandleError(Dart_StringToCString(fieldHandle, &host));
        settings.host = host;
    }
    
    /* Port */
    name = Dart_NewStringFromCString("port");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        int64_t port = 0;
        HandleError(Dart_IntegerToInt64(fieldHandle, &port));
        settings.port = port;
    }
   
    /* Virtual Host */
    name = Dart_NewStringFromCString("virtualHost");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        const char* vhost;
        HandleError(Dart_StringToCString(fieldHandle, &vhost));
        settings.virtualhost = vhost;
    }
    
    /* Username */
    name = Dart_NewStringFromCString("username");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        const char* username;
        HandleError(Dart_StringToCString(fieldHandle, &username));
        settings.username = username;
    }
    
    /* Password */
    name = Dart_NewStringFromCString("password");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        const char* password;
        HandleError(Dart_StringToCString(fieldHandle, &password));
        settings.password = password;
    }
    
    /* Mechanism */
    name = Dart_NewStringFromCString("mechanism");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) { 
        const char* mechanism;
        HandleError(Dart_StringToCString(fieldHandle, &mechanism));
        settings.mechanism = mechanism;
    }
    
    /* Locale */
    name = Dart_NewStringFromCString("locale");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        const char* locale;
        HandleError(Dart_StringToCString(fieldHandle, &locale));
        settings.locale = locale;
    }
    
    /* Heartbeat */
    name = Dart_NewStringFromCString("heartbeat");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        int64_t heartbeat = 0;
        HandleError(Dart_IntegerToInt64(fieldHandle, &heartbeat));
        settings.heartbeat = heartbeat;
    }
    
    /* Max Channels */
    name = Dart_NewStringFromCString("maxChannels");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        int64_t maxChannels = 0;
        HandleError(Dart_IntegerToInt64(fieldHandle, &maxChannels));
        settings.maxChannels = maxChannels;
    }
    
    /* Max Frame Size */
    name = Dart_NewStringFromCString("maxFrameSize");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        int64_t maxFrameSize = 0;
        HandleError(Dart_IntegerToInt64(fieldHandle, &maxFrameSize));
        settings.maxFrameSize = maxFrameSize;
    }
    
    /* Bounds */
    name = Dart_NewStringFromCString("bounds");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        uint64_t bounds = 0;
        HandleError(Dart_IntegerToUint64(fieldHandle, &bounds));
        settings.bounds = bounds;
    }
    
    /* TCP No Delay */
    name = Dart_NewStringFromCString("tcpNoDelay");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        bool tcpNoDelay = false;
        HandleError(Dart_BooleanValue(fieldHandle, &tcpNoDelay));
        settings.tcpNoDelay = tcpNoDelay;
    }
    
    /* Service */
    name = Dart_NewStringFromCString("service");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        const char* service;
        HandleError(Dart_StringToCString(fieldHandle, &service));
        settings.service = service;
    }
    
    /* Minimum SSF */
    name = Dart_NewStringFromCString("minSsf");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        uint64_t minSsf = 0;
        HandleError(Dart_IntegerToUint64(fieldHandle, &minSsf));
        settings.minSsf = minSsf;
    }
    
    /* Maximum SSF */
    name = Dart_NewStringFromCString("maxSsf");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) { 
        uint64_t maxSsf = 0;
        HandleError(Dart_IntegerToUint64(fieldHandle, &maxSsf));
        settings.maxSsf = maxSsf;
    }
    
    /* Certificate name */
    name = Dart_NewStringFromCString("sslCertName");
    fieldHandle = HandleError(Dart_GetField(object, name));
    if ( !Dart_IsNull(fieldHandle)) {
        const char* sslCertName;
        HandleError(Dart_StringToCString(fieldHandle, &sslCertName));
        settings.sslCertName = sslCertName;
    }
    
    return settings;
}

/**
 * getNegotiatedConnectionSettings
 * 
 * @param settings
 * @param negotiated
 * @return Dart_Handle to our Dart ConnectionSettings object
 */
Dart_Handle getNegotiatedConnectionSettings(ConnectionSettings negotiated) {
    
    /* Create a ConnectionSettings class from our root library */
    Dart_Handle className = Dart_NewStringFromCString("AmqpcConnectionSettings");
    
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
    
    /* Protocol */
    name = Dart_NewStringFromCString("protocol");
    value = Dart_NewStringFromCString(negotiated.protocol.c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Host */
    name = Dart_NewStringFromCString("host");
    value = Dart_NewStringFromCString(negotiated.host.c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Port */
    name = Dart_NewStringFromCString("port");
    value = Dart_NewInteger(negotiated.port);
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    /* Virtual Host */
    name = Dart_NewStringFromCString("virtualHost");
    value = Dart_NewStringFromCString(negotiated.virtualhost.c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Username */
    name = Dart_NewStringFromCString("username");
    value = Dart_NewStringFromCString(negotiated.username.c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Password */
    name = Dart_NewStringFromCString("password");
    value = Dart_NewStringFromCString(negotiated.password.c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Mechanism */
    name = Dart_NewStringFromCString("mechanism");
    value = Dart_NewStringFromCString(negotiated.mechanism.c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Locale */
    name = Dart_NewStringFromCString("locale");
    value = Dart_NewStringFromCString(negotiated.locale.c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Heartbeat */
    name = Dart_NewStringFromCString("heartbeat");
    value = Dart_NewInteger(negotiated.heartbeat);
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Max Channels */
    name = Dart_NewStringFromCString("maxChannels");
    value = Dart_NewInteger(negotiated.maxChannels);
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    
    /* Max Frame Size*/
    name = Dart_NewStringFromCString("maxFrameSize");
    value = Dart_NewInteger(negotiated.maxFrameSize);
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    
    /* Bounds  */
    name = Dart_NewStringFromCString("bounds");
    value = Dart_NewInteger(negotiated.bounds);
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* TCP No Delay */
    name = Dart_NewStringFromCString("tcpNoDelay");
    value = Dart_NewBoolean(negotiated.tcpNoDelay);
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Service */
    name = Dart_NewStringFromCString("service");
    value = Dart_NewStringFromCString(negotiated.service.c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Min SSF  */
    name = Dart_NewStringFromCString("minSsf");
    value = Dart_NewInteger(negotiated.minSsf);
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* Max SSF  */
    name = Dart_NewStringFromCString("maxSsf");
    value = Dart_NewInteger(negotiated.maxSsf);
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    /* SSL Certificate Name */
    name = Dart_NewStringFromCString("sslCertName");
    value = Dart_NewStringFromCString(negotiated.sslCertName.c_str());
    HandleError(Dart_SetField(settings,
                              name,
                              value));
    
    return settings;
    
}

/**
 * connectionFinalizer
 * 
 * @param connectionHandle
 * @param peer
 */
void connectionFinalizer(Dart_Handle connectionHandle,
                         void* peer) {
    
    /* Close and release the connection object */
    Connection* connection = reinterpret_cast<Connection*>(peer);
    connection->close();
    delete connection;
    
}


/* Public functions */

void connectionConnection(Dart_NativeArguments arguments) {
    
     Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
     Connection* newConnection = new Connection();
     
     /* Set the connection as the Dart objects peer pointer */
     HandleError(Dart_SetPeer(object, newConnection));
     
     /**
      * Wrap the connection in a weak persistent handle, if the Dart
      * GC then reclaims this object as it is not in scope we can close
      * the connection cleanly and release it.
     */
     Dart_WeakPersistentHandle connectionHandle = Dart_NewWeakPersistentHandle(
                                                    object,
                                                    newConnection,
                                                    (Dart_WeakPersistentHandleFinalizer)connectionFinalizer);
}

void connectionOpenHost(Dart_NativeArguments arguments) {
    
    /* Defaults and initialisation */
    void* peer;
    const char* host = NULL;
    int64_t port = 5672;
    const char* uid = NULL;
    const char* pwd = NULL;
    const char* virtualHost = NULL;
    int64_t maxFrameSize = 65536;
    bool success = false;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Host name*/
    Dart_Handle hostString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(hostString, &host));
    
    /* Port */
    HandleError(Dart_GetNativeIntegerArgument(arguments, 2, &port));
    
    /* UID */
    Dart_Handle uidString = HandleError(Dart_GetNativeStringArgument(arguments, 3, &peer));
    HandleError(Dart_StringToCString(uidString, &uid));
    
    /* PWD */
    Dart_Handle pwdString = HandleError(Dart_GetNativeStringArgument(arguments, 4, &peer));
    HandleError(Dart_StringToCString(pwdString, &pwd));
    
    /* Vhost */
    Dart_Handle vhostString = HandleError(Dart_GetNativeStringArgument(arguments, 5, &peer));
    HandleError(Dart_StringToCString(vhostString, &virtualHost));
    
    /* Frame size */
    HandleError(Dart_GetNativeIntegerArgument(arguments, 6, &maxFrameSize));
    
    /* Call the Connection method */
    if ( Dart_IsInstance(object)) {
        
        Connection* connection = getConnection(object);
        try {
            connection->open(host,
                             port,
                             uid,
                             pwd,
                             virtualHost,
                             maxFrameSize); 
            success = true;
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
    /* Return value */
    Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(success)));
    
}

void connectionOpenUrl(Dart_NativeArguments arguments) {
    
    /* Defaults and initialisation */
    void* peer;
    Url url = Url();
    const char* urlRaw = NULL;
    const char* uid = NULL;
    const char* pwd = NULL;
    const char* virtualHost = NULL;
    int64_t maxFrameSize = 65536;
    bool success = false;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Url */
    Dart_Handle urlString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(urlString, &urlRaw));
    try {
        url.parse(urlRaw);
    } catch(Exception e) {
         std::cerr << e.what() << std::endl;
         Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(success)));
         return;
    }
   
    /* UID */
    Dart_Handle uidString = HandleError(Dart_GetNativeStringArgument(arguments, 2, &peer));
    HandleError(Dart_StringToCString(uidString, &uid));
    
    /* PWD */
    Dart_Handle pwdString = HandleError(Dart_GetNativeStringArgument(arguments, 3, &peer));
    HandleError(Dart_StringToCString(pwdString, &pwd));
    
    /* Vhost */
    Dart_Handle vhostString = HandleError(Dart_GetNativeStringArgument(arguments, 4, &peer));
    HandleError(Dart_StringToCString(vhostString, &virtualHost));
    
    /* Frame size */
    HandleError(Dart_GetNativeIntegerArgument(arguments, 5, &maxFrameSize));
    
    /* Call the Connection method */
    if ( Dart_IsInstance(object)) {
        
        Connection* connection = getConnection(object);
        try {
            connection->open(url,
                             uid,
                             pwd,
                             virtualHost,
                             maxFrameSize); 
            success = true;
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
    /* Return value */
    Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(success)));
    
}

void connectionOpenUrlSettings(Dart_NativeArguments arguments) {
    
    /* Defaults and initialisation */
    void* peer;
    Url url = Url();
    const char* urlRaw = NULL;
    bool success = false;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Url */
    Dart_Handle urlString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(urlString, &urlRaw));
    try {
        url.parse(urlRaw);
    } catch(Exception e) {
         std::cerr << e.what() << std::endl;
         Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(success)));
         return;
    }
    
    /* Settings */
    Dart_Handle settingsObject = HandleError(Dart_GetNativeArgument(arguments, 2));
    ConnectionSettings settings = getConnectionSettings(settingsObject);
    
    /* Call the Connection method */
    if ( Dart_IsInstance(object)) {
        
        Connection* connection = getConnection(object);
        try {
            connection->open(url,
                             settings); 
            success = true;
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
    /* Return value */
    Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(success)));
    
}

void connectionOpenSettings(Dart_NativeArguments arguments) {
    
     bool success = false;
    
    /* Get and process the arguments, the Dart object is always 0 */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    
    /* Settings */
    Dart_Handle settingsObject = HandleError(Dart_GetNativeArgument(arguments, 1));
    ConnectionSettings settings = getConnectionSettings(settingsObject);
    
    /* Call the Connection method */
    if ( Dart_IsInstance(object)) {
        
        Connection* connection = getConnection(object);
        try {
            connection->open(settings); 
            success = true;
        } catch(Exception& e) {
            std::cerr << e.what() << std::endl;
        }                        
    }
    
    /* Return value */
    Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(success)));
    
    
}

void connectionClose(Dart_NativeArguments arguments) {
    
    bool success = false;
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    if ( Dart_IsInstance(object)) {
    
            Connection* connection = getConnection(object);
            try {
                connection->close();   
                success = true;
            } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
            }
    }
    
    Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(success)));
    
}

void connectionIsOpen(Dart_NativeArguments arguments) {
    
    bool open = false;
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    if ( Dart_IsInstance(object)) {
           
        Connection* connection = getConnection(object);
        try {
                open = connection->isOpen();
        } catch(Exception& e) {
                std::cerr << e.what() << std::endl;
        }
                
    }
    
    Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(open)));
        
}

void connectionGetNegotiatedSettings(Dart_NativeArguments arguments) {
    
    
    /* Get the current connection settings */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Connection* connection = getConnection(object);
    ConnectionSettings nativeConnectionSettings = connection->getNegotiatedSettings(); 
    
    /* Create our class with the Connection values */
    Dart_Handle connectionSettings = getNegotiatedConnectionSettings(nativeConnectionSettings);
    
    /* Return it */
    Dart_SetReturnValue(arguments, connectionSettings);
}

void connectionNewSession (Dart_NativeArguments arguments) {
    
    
    void* peer;
    const char* name = NULL;
    int64_t timeout = 0;
    Session* session = NULL;
   
    /* Get the current connection and the parameters */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Connection* connection = getConnection(object);
    
    /* Name */
    Dart_Handle nameString = HandleError(Dart_GetNativeStringArgument(arguments, 1, &peer));
    HandleError(Dart_StringToCString(nameString, &name));
    
    /* Timeout */
    HandleError(Dart_GetNativeIntegerArgument(arguments, 2, &timeout));
    
    /* Create the new session */
    try {
        Session newSession = connection->newSession(name,
                                                    timeout);
        session = new Session(newSession);
    } catch (Exception& e) {
        std::cerr << e.what() << std::endl;
        throwAmqpcException(e.what());
        
    }
    
    /* Create the new Dart session class */
    Dart_Handle connectionSession = createSession(session);
    
    /* Return the new session */
    Dart_SetReturnValue(arguments, connectionSession);
     
     
}

void connectionResume(Dart_NativeArguments arguments) {
    
    
    bool success = false;
    
    /* Get the current connection and the parameters */
    Dart_Handle object = HandleError(Dart_GetNativeArgument(arguments, 0));
    Connection* connection = getConnection(object);
    
    /* Name */
    Dart_Handle sessionObject = HandleError(Dart_GetNativeArgument(arguments, 1));
    
    /* Get the session */
    void* peer;
    HandleError(Dart_GetPeer(sessionObject, &peer));   
    Session* session = reinterpret_cast<Session*>(peer);
    
    /* Resume the session */
    try {
        connection->resume(*session);
        success = true;
    } catch (Exception& e) {
        std::cerr << e.what() << std::endl;
        
    }
    
    Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(success)));
}
