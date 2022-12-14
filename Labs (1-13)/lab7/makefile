CXX = g++
CXXFLAGS = -Wall

lab7: lab7.cpp Train.o
	$(CXX) $(CXXFLAGS) lab7.cpp Train.o -o lab7

Train.o: Train.h Train.cpp
	$(CXX) $(CXXFLAGS) -c Train.cpp

run:
	./lab7

clean:
	rm *~
