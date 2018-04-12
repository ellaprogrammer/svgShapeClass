#Ella Queen 912602059
#Makefile for HW3 with fill as executable

CXXFLAGS=-Wall

all: fill

Shape.o: Shape.cpp

Domain.o: Domain.cpp Shape.o

fill.o: fill.cpp 

fill: fill.o Shape.o Domain.o
	$(CXX) -o $@ $^

execs: fill

clean:
	rm -f *.o fill