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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/classes/interfaces/ControladorSistema.o \
	${OBJECTDIR}/classes/interfaces/Fabrica.o \
	${OBJECTDIR}/classes/interfaces/ISistema.o \
	${OBJECTDIR}/classes/sources/Cine.o \
	${OBJECTDIR}/classes/sources/Credito.o \
	${OBJECTDIR}/classes/sources/Debito.o \
	${OBJECTDIR}/classes/sources/Funcion.o \
	${OBJECTDIR}/classes/sources/Pelicula.o \
	${OBJECTDIR}/classes/sources/Reserva.o \
	${OBJECTDIR}/classes/sources/Sala.o \
	${OBJECTDIR}/classes/sources/Usuario.o \
	${OBJECTDIR}/datatypes/sources/DtCine.o \
	${OBJECTDIR}/datatypes/sources/DtDireccion.o \
	${OBJECTDIR}/datatypes/sources/DtFecha.o \
	${OBJECTDIR}/datatypes/sources/DtFuncion.o \
	${OBJECTDIR}/datatypes/sources/DtHora.o \
	${OBJECTDIR}/datatypes/sources/DtPelicula.o \
	${OBJECTDIR}/datatypes/sources/DtSala.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/g5_lab4

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/g5_lab4: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/g5_lab4 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/classes/interfaces/ControladorSistema.o: classes/interfaces/ControladorSistema.cpp
	${MKDIR} -p ${OBJECTDIR}/classes/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/classes/interfaces/ControladorSistema.o classes/interfaces/ControladorSistema.cpp

${OBJECTDIR}/classes/interfaces/Fabrica.o: classes/interfaces/Fabrica.cpp
	${MKDIR} -p ${OBJECTDIR}/classes/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/classes/interfaces/Fabrica.o classes/interfaces/Fabrica.cpp

${OBJECTDIR}/classes/interfaces/ISistema.o: classes/interfaces/ISistema.cpp
	${MKDIR} -p ${OBJECTDIR}/classes/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/classes/interfaces/ISistema.o classes/interfaces/ISistema.cpp

${OBJECTDIR}/classes/sources/Cine.o: classes/sources/Cine.cpp
	${MKDIR} -p ${OBJECTDIR}/classes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/classes/sources/Cine.o classes/sources/Cine.cpp

${OBJECTDIR}/classes/sources/Credito.o: classes/sources/Credito.cpp
	${MKDIR} -p ${OBJECTDIR}/classes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/classes/sources/Credito.o classes/sources/Credito.cpp

${OBJECTDIR}/classes/sources/Debito.o: classes/sources/Debito.cpp
	${MKDIR} -p ${OBJECTDIR}/classes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/classes/sources/Debito.o classes/sources/Debito.cpp

${OBJECTDIR}/classes/sources/Funcion.o: classes/sources/Funcion.cpp
	${MKDIR} -p ${OBJECTDIR}/classes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/classes/sources/Funcion.o classes/sources/Funcion.cpp

${OBJECTDIR}/classes/sources/Pelicula.o: classes/sources/Pelicula.cpp
	${MKDIR} -p ${OBJECTDIR}/classes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/classes/sources/Pelicula.o classes/sources/Pelicula.cpp

${OBJECTDIR}/classes/sources/Reserva.o: classes/sources/Reserva.cpp
	${MKDIR} -p ${OBJECTDIR}/classes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/classes/sources/Reserva.o classes/sources/Reserva.cpp

${OBJECTDIR}/classes/sources/Sala.o: classes/sources/Sala.cpp
	${MKDIR} -p ${OBJECTDIR}/classes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/classes/sources/Sala.o classes/sources/Sala.cpp

${OBJECTDIR}/classes/sources/Usuario.o: classes/sources/Usuario.cpp
	${MKDIR} -p ${OBJECTDIR}/classes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/classes/sources/Usuario.o classes/sources/Usuario.cpp

${OBJECTDIR}/datatypes/sources/DtCine.o: datatypes/sources/DtCine.cpp
	${MKDIR} -p ${OBJECTDIR}/datatypes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/datatypes/sources/DtCine.o datatypes/sources/DtCine.cpp

${OBJECTDIR}/datatypes/sources/DtDireccion.o: datatypes/sources/DtDireccion.cpp
	${MKDIR} -p ${OBJECTDIR}/datatypes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/datatypes/sources/DtDireccion.o datatypes/sources/DtDireccion.cpp

${OBJECTDIR}/datatypes/sources/DtFecha.o: datatypes/sources/DtFecha.cpp
	${MKDIR} -p ${OBJECTDIR}/datatypes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/datatypes/sources/DtFecha.o datatypes/sources/DtFecha.cpp

${OBJECTDIR}/datatypes/sources/DtFuncion.o: datatypes/sources/DtFuncion.cpp
	${MKDIR} -p ${OBJECTDIR}/datatypes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/datatypes/sources/DtFuncion.o datatypes/sources/DtFuncion.cpp

${OBJECTDIR}/datatypes/sources/DtHora.o: datatypes/sources/DtHora.cpp
	${MKDIR} -p ${OBJECTDIR}/datatypes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/datatypes/sources/DtHora.o datatypes/sources/DtHora.cpp

${OBJECTDIR}/datatypes/sources/DtPelicula.o: datatypes/sources/DtPelicula.cpp
	${MKDIR} -p ${OBJECTDIR}/datatypes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/datatypes/sources/DtPelicula.o datatypes/sources/DtPelicula.cpp

${OBJECTDIR}/datatypes/sources/DtSala.o: datatypes/sources/DtSala.cpp
	${MKDIR} -p ${OBJECTDIR}/datatypes/sources
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/datatypes/sources/DtSala.o datatypes/sources/DtSala.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
