/* 
 * File:   ExtSession.h
 * Package: amqp_extension
 * Author: S. Hamblett <steve.hamblett@linux.com>
 * Copyright steve@OSCF 2014
 *
 * Created on 22 January 2014, 15:42
 */

#ifndef EXTSESSION_H
#define	EXTSESSION_H

#include "ExtAll.h"

/*
BOOST_PARAMETER_MEMFUN(void, executionSync, 0, 1, ExecutionSyncParameters) {
        return no_keyword::Session_0_10::executionSync(
            p[arg::sync|true]);
*/
void sessionExecutionSync(Dart_NativeArguments arguments);

/**
 * BOOST_PARAMETER_MEMFUN(void, messageTransfer, 0, 5, MessageTransferParameters) {
        return no_keyword::Session_0_10::messageTransfer(
            p[arg::destination|std::string()],
            p[arg::acceptMode|1],
            p[arg::acquireMode|0],
            p[arg::content|Message(std::string())],
            p[arg::sync|true]);
    }
 */
void sessionMessageTransfer(Dart_NativeArguments arguments);

/**
 * BOOST_PARAMETER_MEMFUN(void, messageSubscribe, 0, 9, MessageSubscribeParameters) {
        return no_keyword::Session_0_10::messageSubscribe(
            p[arg::queue|std::string()],
            p[arg::destination|std::string()],
            p[arg::acceptMode|0],
            p[arg::acquireMode|0],
            p[arg::exclusive|false],
            p[arg::resumeId|std::string()],
            p[arg::resumeTtl|0],
            p[arg::arguments|FieldTable()],
            p[arg::sync|true]);
    }
 */
void sessionMessageSubscribe(Dart_NativeArguments arguments);


/**
 *  BOOST_PARAMETER_MEMFUN(void, messageCancel, 0, 2, MessageCancelParameters) {
        return no_keyword::Session_0_10::messageCancel(
            p[arg::destination|std::string()],
            p[arg::sync|true]);
    }
 */
void sessionMessageCancel(Dart_NativeArguments arguments);


/**
 * BOOST_PARAMETER_MEMFUN(void, messageFlush, 0, 2, MessageFlushParameters) {
        return no_keyword::Session_0_10::messageFlush(
            p[arg::destination|std::string()],
            p[arg::sync|true]);
    }
 */
void sessionMessageFlush(Dart_NativeArguments arguments);

/**
 * BOOST_PARAMETER_MEMFUN(void, messageStop, 0, 2, MessageStopParameters) {
        return no_keyword::Session_0_10::messageStop(
            p[arg::destination|std::string()],
            p[arg::sync|true]);
    }
 */
void sessionMessageStop(Dart_NativeArguments arguments);


/**
 * BOOST_PARAMETER_MEMFUN(void, exchangeDeclare, 0, 8, ExchangeDeclareParameters) {
        return no_keyword::Session_0_10::exchangeDeclare(
            p[arg::exchange|std::string()],
            p[arg::type|std::string()],
            p[arg::alternateExchange|std::string()],
            p[arg::passive|false],
            p[arg::durable|false],
            p[arg::autoDelete|false],
            p[arg::arguments|FieldTable()],
            p[arg::sync|true]);
    }
 */
void sessionExchangeDeclare(Dart_NativeArguments arguments);


/**
 * BOOST_PARAMETER_MEMFUN(void, exchangeDelete, 0, 3, ExchangeDeleteParameters) {
        return no_keyword::Session_0_10::exchangeDelete(
            p[arg::exchange|std::string()],
            p[arg::ifUnused|false],
            p[arg::sync|true]);
 */
void sessionExchangeDelete(Dart_NativeArguments arguments);


/**
 * BOOST_PARAMETER_MEMFUN(void, exchangeBind, 0, 5, ExchangeBindParameters) {
        return no_keyword::Session_0_10::exchangeBind(
            p[arg::queue|std::string()],
            p[arg::exchange|std::string()],
            p[arg::bindingKey|std::string()],
            p[arg::arguments|FieldTable()],
            p[arg::sync|true]);
    }
 */
void sessionExchangeBind(Dart_NativeArguments arguments);

/**
 * BOOST_PARAMETER_MEMFUN(void, exchangeUnbind, 0, 5, ExchangeUnbindParameters) {
        return no_keyword::Session_0_10::exchangeUnbind(
            p[arg::queue|std::string()],
            p[arg::exchange|std::string()],
            p[arg::bindingKey|std::string()],
            p[arg::arguments|FieldTable()],
            p[arg::sync|true]);
    }
 */
void sessionExchangeUnbind(Dart_NativeArguments arguments);

/**
 * BOOST_PARAMETER_MEMFUN(qpid::framing::ExchangeBoundResult, exchangeBound, 0, 5, ExchangeBoundParameters) {
        return no_keyword::Session_0_10::exchangeBound(
            p[arg::exchange|std::string()],
            p[arg::queue|std::string()],
            p[arg::bindingKey|std::string()],
            p[arg::arguments|FieldTable()],
            p[arg::sync|true]);
    }
 */
void sessionExchangeBound(Dart_NativeArguments arguments);

/**
 * BOOST_PARAMETER_MEMFUN(void, queueDeclare, 0, 8, QueueDeclareParameters) {
        return no_keyword::Session_0_10::queueDeclare(
            p[arg::queue|std::string()],
            p[arg::alternateExchange|std::string()],
            p[arg::passive|false],
            p[arg::durable|false],
            p[arg::exclusive|false],
            p[arg::autoDelete|false],
            p[arg::arguments|FieldTable()],
            p[arg::sync|true]);
    }
 */
void sessionQueueDeclare(Dart_NativeArguments arguments);

/**
 * BOOST_PARAMETER_MEMFUN(void, queueDelete, 0, 4, QueueDeleteParameters) {
        return no_keyword::Session_0_10::queueDelete(
            p[arg::queue|std::string()],
            p[arg::ifUnused|false],
            p[arg::ifEmpty|false],
            p[arg::sync|true]);
    }
 */
void sessionQueueDelete(Dart_NativeArguments arguments);


/**
 * BOOST_PARAMETER_MEMFUN(void, queuePurge, 0, 2, QueuePurgeParameters) {
        return no_keyword::Session_0_10::queuePurge(
            p[arg::queue|std::string()],
            p[arg::sync|true]);
    }
 */
void sessionQueuePurge(Dart_NativeArguments arguments);

#endif	/* EXTSESSION_H */

