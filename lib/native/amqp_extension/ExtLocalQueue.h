/* 
 * File:   ExtLocalQueue.h
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 28 January 2014, 14:23
 */

/*
 * Qpid Local Queue class implementation.
 * 
 * See the Dart class for parameter usage and class specifics
 */

#ifndef EXTLOCALQUEUE_H
#define	EXTLOCALQUEUE_H

#include "ExtAll.h"

/**
 * Constructor
 */
void localQueueLocalQueue(Dart_NativeArguments arguments);

/**
 * Message get(sys::Duration timeout=sys::TIME_INFINITE);
 */
void localQueueGet(Dart_NativeArguments arguments);

/**
 * Message pop(sys::Duration timeout=sys::TIME_INFINITE);
 */
void localQueuePop(Dart_NativeArguments arguments);

/**
 * size_t size() const;
 */
void localQueueSize(Dart_NativeArguments arguments);

#endif	/* EXTLOCALQUEUE_H */

