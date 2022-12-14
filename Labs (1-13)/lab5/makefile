CXX = g++
CXXFLAGS = -Wall

lab5: Laptop.o lab5.cpp
	$(CXX) $(CXXFLAGS) Laptop.o lab5.cpp -o lab5
Laptop.o: Laptop.cpp Laptop.h
	$(CXX) $(CXXFLAGS) -c Laptop.cpp

clean:
	rm *~
	rm *.o

run:
	./lab5
