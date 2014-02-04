#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ExtAll.o \
	${OBJECTDIR}/ExtConnection.o \
	${OBJECTDIR}/ExtLocalQueue.o \
	${OBJECTDIR}/ExtMessage.o \
	${OBJECTDIR}/ExtMessageListener.o \
	${OBJECTDIR}/ExtSession.o \
	${OBJECTDIR}/ExtSubscription.o \
	${OBJECTDIR}/ExtSubscriptionManager.o \
	${OBJECTDIR}/ExtUuid.o \
	${OBJECTDIR}/amqp_extension.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib -lqpidclient

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libamqp_extension.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libamqp_extension.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libamqp_extension.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/ExtAll.o: ExtAll.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/qpid/client -I../../Development/google/dart/dart/dart-sdk -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExtAll.o ExtAll.cpp

${OBJECTDIR}/ExtConnection.o: ExtConnection.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/qpid/client -I../../Development/google/dart/dart/dart-sdk -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExtConnection.o ExtConnection.cpp

${OBJECTDIR}/ExtLocalQueue.o: ExtLocalQueue.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/qpid/client -I../../Development/google/dart/dart/dart-sdk -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExtLocalQueue.o ExtLocalQueue.cpp

${OBJECTDIR}/ExtMessage.o: ExtMessage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/qpid/client -I../../Development/google/dart/dart/dart-sdk -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExtMessage.o ExtMessage.cpp

${OBJECTDIR}/ExtMessageListener.o: ExtMessageListener.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/qpid/client -I../../Development/google/dart/dart/dart-sdk -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExtMessageListener.o ExtMessageListener.cpp

${OBJECTDIR}/ExtSession.o: ExtSession.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/qpid/client -I../../Development/google/dart/dart/dart-sdk -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExtSession.o ExtSession.cpp

${OBJECTDIR}/ExtSubscription.o: ExtSubscription.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/qpid/client -I../../Development/google/dart/dart/dart-sdk -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExtSubscription.o ExtSubscription.cpp

${OBJECTDIR}/ExtSubscriptionManager.o: ExtSubscriptionManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/qpid/client -I../../Development/google/dart/dart/dart-sdk -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExtSubscriptionManager.o ExtSubscriptionManager.cpp

${OBJECTDIR}/ExtUuid.o: ExtUuid.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/qpid/client -I../../Development/google/dart/dart/dart-sdk -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExtUuid.o ExtUuid.cpp

${OBJECTDIR}/amqp_extension.o: amqp_extension.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/qpid/client -I../../Development/google/dart/dart/dart-sdk -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/amqp_extension.o amqp_extension.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libamqp_extension.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
