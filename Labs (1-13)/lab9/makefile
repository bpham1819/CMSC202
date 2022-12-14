CXX = g++
CXXFLAGS = -Wall

lab9: NPC.o Merchant.o Traveler.o lab9.cpp
	$(CXX) $(CXXFLAGS) NPC.o Merchant.o Traveler.o lab9.cpp -o lab9

NPC.o: NPC.h NPC.cpp
	$(CXX) $(CXXFLAGS) -c NPC.cpp -o NPC.o

Merchant.o: Merchant.h Merchant.cpp NPC.o
	$(CXX) $(CXXFLAGS) -c Merchant.cpp -o Merchant.o

Traveler.o: Traveler.h Traveler.cpp NPC.o
	$(CXX) $(CXXFLAGS) -c Traveler.cpp -o Traveler.o

run:
	./lab9

clean:
	rm *~
