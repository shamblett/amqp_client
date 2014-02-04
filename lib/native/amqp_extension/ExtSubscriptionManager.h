/* 
 * File:   ExtSubscriptionManager.h
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 30 January 2014, 07:41
 */

#ifndef EXTSUBSCRIPTIONMANAGER_H
#define	EXTSUBSCRIPTIONMANAGER_H

#include "ExtAll.h"

 /**
 * Constructor
 */
void SubscriptionManagersubscriptionManager(Dart_NativeArguments arguments);

/**
 * Subscription subscribe(LocalQueue& localQueue,
                           const std::string& queue,
                           const SubscriptionSettings& settings,
                           const std::string& name=std::string());
 */
void subscriptionManagerSubscribeLocal(Dart_NativeArguments arguments);


/**
 * Subscription subscribe(MessageListener& listener,
                           const std::string& queue,
                           const std::string& name=std::string());
 */
void subscriptionManagerSubscribeListen(Dart_NativeArguments arguments);


/**
 * Message get(const std::string& queue, sys::Duration timeout=sys::TIME_INFINITE);
 */
void subscriptionManagerGet(Dart_NativeArguments arguments);

/**
 * Subscription getSubscription(const std::string& name) const;
 */
void subscriptionManagerGetSubscription(Dart_NativeArguments arguments);

/**
 * void cancel(const std::string& name); 
 */
void subscriptionManagerCancel(Dart_NativeArguments arguments);


/**
 * void run();
 */
void subscriptionManagerRun(Dart_NativeArguments arguments);

/**
 * void stop();
 */
void subscriptionManagerStop(Dart_NativeArguments arguments);

/*
 * void setAutoStop(bool set=true);
 */
void subscriptionManagerSetAutoStop(Dart_NativeArguments arguments);

/**
 * void setDefaultSettings(const SubscriptionSettings& s);
 */
void SubscriptionManagersubscriptionManagerSetDefaultSettings(Dart_NativeArguments arguments);

/*
 * SubscriptionSettings& getDefaultSettings();
 */
void subscriptionManagerGetDefaultSettings(Dart_NativeArguments arguments);

/*
 * void setAcceptMode(AcceptMode mode);
 */
void subscriptionManagerSetAcceptMode(Dart_NativeArguments arguments);

/*
 * void setAcquireMode(AcquireMode mode);
 */
void subscriptionManagerSetAcquireMode(Dart_NativeArguments arguments);

/**
 * Session getSession() const;
 */
void subscriptionManagerGetSession(Dart_NativeArguments arguments);


#endif	/* EXTSUBSCRIPTIONMANAGER_H */

