CXX = g++
CXXFLAGS = -Wall

lab12: ArcaneEquipment.o lab12.cpp
	$(CXX) $(CXXFLAGS) ArcaneEquipment.o lab12.cpp -o lab12

ArcaneEquipment.o: ArcaneEquipment.h ArcaneEquipment.cpp
	$(CXX) $(CXXFLAGS) -c ArcaneEquipment.cpp

run:
	./lab12

clean:
	rm -f *~ *.o

val:
	valgrind ./lab12
