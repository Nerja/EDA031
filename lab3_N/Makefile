# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g -L .
#LDLIBS = -l lab1
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = a1 a2 a3 a4 a5

all: $(PROGS)

a1: a1.o tagremover.o

a2: a2.o

a3: a3.o date.o

a4: a4.o date.o

a5: a5.o date.o

sieve: sieve.o

# Phony targets
.PHONY: all clean

# Standard clean
clean:
	rm -f *.o $(PROGS)

clean2:
	rm -f *.d $(PROGS)

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
