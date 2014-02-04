/* 
 * File:   ExtMessageListener.h
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 30 January 2014, 09:48
 */

#ifndef EXTMESSAGELISTENER_H
#define	EXTMESSAGELISTENER_H

#include "ExtAll.h"

#endif	/* EXTMESSAGELISTENER_H */

class ExtMessageListener : public MessageListener {
    
    public:
        
        /**
        * Construct with a Dart class object
        * @param classHandle
        */
        ExtMessageListener(Dart_WeakPersistentHandle classHandle);
   
        ~ExtMessageListener();
    
        /**
        * Overridden receive function
        */
        void received(Message& msg);
    
        /**
        * Dart object getter
        */
        Dart_WeakPersistentHandle getObject();
    
    private :
        
        Dart_WeakPersistentHandle object;
        
};