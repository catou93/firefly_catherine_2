###########################################################################
## Makefile generated for Simulink model 'autopilot_hinf'. 
## 
## Makefile     : autopilot_hinf.mk
## Generated on : Thu Aug 02 13:27:14 2018
## MATLAB Coder version: 3.2 (R2016b)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/autopilot_hinf.elf
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.

PRODUCT_NAME              = autopilot_hinf
MAKEFILE                  = autopilot_hinf.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2016b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2016b/bin
MATLAB_ARCH_BIN           = C:/PROGRA~1/MATLAB/R2016b/bin/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:/Users/CATHER~1/Dropbox/ARTICL~1/CONTRO~1
ARCH                      = win64
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C++
MODELREF_LINK_RSPFILE_NAME = autopilot_hinf_ref.rsp
RELATIVE_PATH_TO_ANCHOR   = ..

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Catkin v1.0 | gmake (64-bit Windows)
# Supported Version(s):    
# ToolchainInfo Version:   R2016b
# Specification Revision:  1.0
# 

#-----------
# MACROS
#-----------

CCOUTPUTFLAG = --output_file=
LDOUTPUTFLAG = --output_file=

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Catkin1.0 Assembler
AS = echo as

# C Compiler: Catkin1.0 C Compiler
CC = echo gcc

# Linker: Catkin1.0 Linker
LD = echo gcc

# C++ Compiler: Catkin1.0 C++ Compiler
CPP = echo g++

# C++ Linker: Catkin1.0 C++ Linker
CPP_LD = echo gcc

# Archiver: Catkin1.0 Archiver
AR = echo ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_BIN)
MEX = $(MEX_PATH)/mex

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE = echo


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = -r
ASFLAGS              = -c \
                       $(ASFLAGS_ADDITIONAL) \
                       $(INCLUDES)
CFLAGS               = -c \
                       -O2
CPPFLAGS             =
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = "### Successfully generated all binary outputs."
SHAREDLIB_LDFLAGS    =

#--------------------
# File extensions
#--------------------

OBJ_EXT             = .s.o
ASM_EXT             = .s
H_EXT               = .h
OBJ_EXT             = .c.o
C_EXT               = .c
EXE_EXT             = .elf
SHAREDLIB_EXT       = .so
HPP_EXT             = .hpp
OBJ_EXT             = .cpp.o
CPP_EXT             = .cpp
EXE_EXT             =
SHAREDLIB_EXT       = .so
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/autopilot_hinf.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(MATLAB_ROOT)/simulink/include/sf_runtime -I$(START_DIR)/autopilot_hinf_grt_rtw -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DMAT_FILE=0 -DINTEGER_CODE=0 -DMT=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DONESTEPFCN=1 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=1
DEFINES_IMPLIED = -DTID01EQ=1
DEFINES_STANDARD = -DMODEL=autopilot_hinf -DNUMST=2 -DNCSTATES=16 -DHAVESTDIO -DRT -DUSE_RTMODEL

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_IMPLIED) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/autopilot_hinf_grt_rtw/autopilot_hinf.cpp $(START_DIR)/autopilot_hinf_grt_rtw/autopilot_hinf_data.cpp

MAIN_SRC = $(MATLAB_ROOT)/rtw/c/src/common/rt_cppclass_main.cpp

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = autopilot_hinf.cpp.o autopilot_hinf_data.cpp.o

MAIN_OBJ = rt_cppclass_main.cpp.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : build


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.c.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/autopilot_hinf_grt_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/autopilot_hinf_grt_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/autopilot_hinf_grt_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : ../%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : ../%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : ../%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_cppclass_main.cpp.o : $(MATLAB_ROOT)/rtw/c/src/common/rt_cppclass_main.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : $(MAKEFILE) rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *Object
	$(ECHO) "### Deleted all derived files."


