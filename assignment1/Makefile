#
# Makefile
#
# Adapted from CS50 Problem Set 5
#


# compiler to use
CC = g++

# flags to pass compiler
CFLAGS = -g

# name for executable
EXE = count_inversions

# space-separated list of user-defined header files
HDRS = Vector_inversions.h

# space-separated list of libraries, if any,
# each of which should be prefixed with -l
LIBS =

# space-separated list of source files
SRCS = count_inversions.cpp Vector_inversions.cpp

# automatically generated list of object files
OBJS = $(SRCS:.cpp=.o)


# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# dependencies 
$(OBJS): $(HDRS) Makefile

# housekeeping
clean:
	rm -f $(EXE) *.o
