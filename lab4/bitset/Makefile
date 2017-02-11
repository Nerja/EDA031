# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = g++

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
LDFLAGS =   -g
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = simplebitsettest bitsettest1 bitsettest2 test

all: $(PROGS)

# Targets rely on implicit rules for compiling and linking
simplebitsettest: simplebitsettest.o simplebitset.o
bitsettest1: bitsettest1.o bitreference.o bitset.o
bitsettest2: bitsettest2.o bitreference.o bitset.o bitsetiterator.o

# Phony targets
.PHONY: all clean testa4

test:
	./simplebitsettest > simpleoutout
	./bitsettest1 > bitsettest1outout
	./bitsettest2 > bitsettest2outout
	diff bitsettest1outout simpleoutout
	diff bitsettest2outout simpleoutout



# Standard clean
clean:
	rm -f *.o $(PROGS)

# Generate dependencies in *.d files
%.d: %.cc
	@set -e; rm -f $@; \
         $(CPP) -MM $(CPPFLAGS) $< > $@.$$$$; \
         sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
         rm -f $@.$$$$

# Include the *.d files
SRC = $(wildcard *.cc)
include $(SRC:.cc=.d)
