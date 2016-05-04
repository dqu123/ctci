# CTCI Makefile
CXX = g++
CXXFLAGS = -std=c++0x -Wall -g
SRCS = $(wildcard *.cc) # Compile all C++ files separately
PROG = $(SRCS:.cc=)

all: $(PROG)

$(PROG): % : %.o
	$(CXX) $^ -o $@

clean:
	$(RM) $(PROG) *.o *~

tidy:
	rm -rf *.o

.PHONY: all clean tidy
