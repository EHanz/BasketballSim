########################################################
# Makefile for CSCI 375
#   In many cases you will ONLY need to modify the
#   SRCS variable below
# Author: Gary M. Zoppetti, Ph.D. and Chad Hogg
########################################################

########################################################
# Variable definitions
########################################################
# C++ compiler
CXX := g++
#CXX := clang++

# Include directories, prefaced with "-I"
INCDIRS  := -isystem /usr/include/catch2

# C++ compiler flags
# Use the first for debugging, the second for release
CXXFLAGS := -g -Wall -std=c++14 $(INCDIRS)
#CXXFLAGS := -O3 -Wall -std=c++14 $(INCDIRS)

# Linker. For C++ should be $(CXX).
LINK := $(CXX)

# Linker flags. Usually none.
LDFLAGS := 

# Library paths, prefaced with "-L". Usually none.
LDPATHS := 

# Libraries used, prefaced with "-l".
LDLIBS := 

# All source files, separated by spaces. Don't include header files. 
SRCS := Main.cpp Player.cpp Team.cpp

# Extension for source files. Do NOT modify.
SOURCESUFFIX := cpp

# Determines object files based on SRCS.
OBJS := $(SRCS:.$(SOURCESUFFIX)=.o)

# Executable name. Defaults to basename of first name in SRCS.
EXEC := $(patsubst %.o, %, $(word 1, $(OBJS))).out

# Command to generate dependency rules for make. 
MAKEDEPEND := $(CXX) $(CPPFLAGS) $(CXXFLAGS) -MM -MP

#############################################################
# Rules
#############################################################

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(LINK) $(LDFLAGS) $(LDPATHS) $^ -o $@ $(LDLIBS)

-include Makefile.deps

#############################################################

.PHONY : clean

clean :
	$(RM) $(EXEC) $(OBJS) a.out core
	$(RM) Makefile.deps *~

.PHONY :  Makefile.deps
Makefile.deps :
	$(MAKEDEPEND) $(SRCS) > $@

#############################################################
#############################################################