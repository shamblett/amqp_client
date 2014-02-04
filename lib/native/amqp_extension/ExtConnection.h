/* 
 * File:   ExtConnection.h
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 20 January 2014, 08:10
 */

/*
 * Qpid Connection class implementation.
 * 
 * See the Dart class for parameter usage and class specifics
 */

#ifndef EXTCONNECTION_H
#define	EXTCONNECTION_H

#include "ExtAll.h"
#include "qpid/Url.h"

/**
 * Constructor
 */
void connectionConnection(Dart_NativeArguments arguments);

/**
 * open(const std::string& host, int port = 5672,
 *             const std::string& uid = "",
 *             const std::string& pwd = "",
 *             const std::string& virtualhost = "/", uint16_t maxFrameSize=65535);
 */
void connectionOpenHost(Dart_NativeArguments arguments);

/**
 * open(const Url& url,
 *             const std::string& uid = "",
 *             const std::string& pwd = "",
 *             const std::string& virtualhost = "/", uint16_t maxFrameSize=65535);
 *
 */
void connectionOpenUrl(Dart_NativeArguments arguments);

/*
 * void open(const ConnectionSettings& settings);
 */
void connectionOpenSettings(Dart_NativeArguments arguments);

/**
 * open(const Url& url, const ConnectionSettings& settings);
 */
void connectionOpenUrlSettings(Dart_NativeArguments arguments);

/**
 * void close();
 * 
 */
void connectionClose(Dart_NativeArguments arguments);

/**
 * bool isOpen() const;
 */
void connectionIsOpen(Dart_NativeArguments arguments);

/*
* const ConnectionSettings& getNegotiatedSettings();
*/
void connectionGetNegotiatedSettings(Dart_NativeArguments arguments);

/**
 * Session newSession(const std::string& name=std::string(), uint32_t timeoutSeconds = 0);
 */
void connectionNewSession(Dart_NativeArguments arguments);

/**
 * void resume(Session& session);
 */
void connectionResume(Dart_NativeArguments arguments);

#endif	/* EXTCONNECTION_H */

