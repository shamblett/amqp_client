/* 
 * File:   ExtMessage.h
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 23 January 2014, 14:37
 */

#ifndef EXTMESSAGE_H
#define	EXTMESSAGE_H

#include "ExtAll.h"

/**
 * Constructor
 */
void messageMessage(Dart_NativeArguments arguments);

/**
 * Message& operator=(const Message&);
 */
void messageEquals(Dart_NativeArguments arguments);

/**
 * std::string& getData(); 
 */
void messageGetData(Dart_NativeArguments arguments);

/**
 * void setData(const std::string&);
 */
void messageSetData(Dart_NativeArguments arguments);

/**
 * void swap(Message&);
 */
void messageSwap(Dart_NativeArguments arguments);

/**
 * void appendData(const std::string&);
 */
void messageAppendData(Dart_NativeArguments arguments);

/**
 * bool hasMessageProperties() const;
 */
void messageHasMessageProperties(Dart_NativeArguments arguments);

/**
 * bool hasDeliveryProperties() const;
 */
void messageHasDeliveryProperties(Dart_NativeArguments arguments);

/**
 * framing::MessageProperties& getMessageProperties();
 */
void messageGetMessageProperties(Dart_NativeArguments arguments);

/**
 * framing::DeliveryProperties& getDeliveryProperties();
 */
void messageGetDeliveryProperties(Dart_NativeArguments arguments);

/**
 * std::string getDestination() const;
 */
void messageGetDestination(Dart_NativeArguments arguments);


/**
 * bool isRedelivered() const;
 */
void messageIsRedelivered(Dart_NativeArguments arguments);

/**
 * void setRedelivered(bool redelivered)
 */
void messageSetRedelivered(Dart_NativeArguments arguments);

/**
 * const framing::SequenceNumber& getId() const;
 */
void messageGetId(Dart_NativeArguments arguments);

#endif	/* EXTMESSAGE_H */

