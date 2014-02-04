/* 
 * File:   ExtUuid.h
 * Author: steve
 *
 * Created on 24 January 2014, 16:32
 */

#ifndef EXTUUID_H
#define	EXTUUID_H

#include "ExtAll.h"

/**
 * Constructor
 */
void uuidUuid(Dart_NativeArguments arguments);

/**
 * void generate();
 */
void uuidGenerate(Dart_NativeArguments arguments);

/**
 * std::string str() const
 */
void uuidStr(Dart_NativeArguments arguments);

/**
 * void clear();
 */
void uuidClear(Dart_NativeArguments arguments);

/**
 * bool isNull() const;
 */
void uuidIsNull(Dart_NativeArguments arguments);

#endif	/* EXTUUID_H */

