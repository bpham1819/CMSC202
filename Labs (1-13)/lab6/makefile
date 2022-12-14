CXX = g++
CXXFLAGS = -Wall

lab6: lab6.cpp Groceries.o
	$(CXX) $(CXXFLAGS) lab6.cpp Groceries.o -o lab6

Groceries.o: Groceries.h Groceries.cpp
	$(CXX) $(CXXFLAGS) -c Groceries.cpp

run:
	./lab6

clean:
	rm *~
