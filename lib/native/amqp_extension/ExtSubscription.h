/* 
 * File:   ExtSubscription.h
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 29 January 2014, 13:22
 */

#ifndef EXTSUBSCRIPTION_H
#define	EXTSUBSCRIPTION_H

#include "ExtAll.h"

#endif	/* EXTSUBSCRIPTION_H */

/**
 * std::string getName() const;
 */
void subscriptionGetName(Dart_NativeArguments arguments);

/**
 * std::string getQueue() const;
 */
void subscriptionGetQueue(Dart_NativeArguments arguments);

/*
 * const SubscriptionSettings& getSettings() const;
 */
void subscriptionGetSettings(Dart_NativeArguments arguments);

/**
 * void setAutoAck(unsigned int n);
 */
void subscriptionSetAutoAck(Dart_NativeArguments arguments);

/**
 * Session getSession() const;
 */
void subscriptionGetSession(Dart_NativeArguments arguments);

/**
 * void acquire(const Message& m) { acquire(SequenceSet(m.getId())); }
 */
void subscriptionAcquire(Dart_NativeArguments arguments);

/**
 * void accept(const Message& m) { accept(SequenceSet(m.getId())); }
 */
void subscriptionAccept(Dart_NativeArguments arguments);

/**
 * void release(const Message& m) { release(SequenceSet(m.getId())); }
 */
void subscriptionRelease(Dart_NativeArguments arguments);

/**
 * void cancel();
 */
void subscriptionCancel(Dart_NativeArguments arguments);

/**
 * SubscriptionManager getSubscriptionManager();
 */
void subscriptionGetSubscriptionmanager(Dart_NativeArguments arguments);