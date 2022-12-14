CXX = g++
CXXFLAGS = -Wall -g

proj4: proj4.cpp Game.o Area.o Entity.o Zerg.o Terran.o Zergling.o Mutalisk.o Hydralisk.o Battlecruiser.o Ghost.o Marine.o
	$(CXX) $(CXXFLAGS) Game.o Area.o Entity.o Zerg.o Terran.o Zergling.o Mutalisk.o Hydralisk.o Battlecruiser.o Ghost.o Marine.o proj4.cpp -o proj4

Game.o: Game.cpp Game.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

Area.o: Area.cpp Area.h
	$(CXX) $(CXXFLAGS) -c Area.cpp

Battlecruiser.o: Battlecruiser.cpp Battlecruiser.h Terran.o Entity.o
	$(CXX) $(CXXFLAGS) -c Battlecruiser.cpp

Ghost.o: Ghost.cpp Ghost.h Terran.o Entity.o
	$(CXX) $(CXXFLAGS) -c Ghost.cpp

Marine.o: Marine.cpp Marine.h Terran.o Entity.o
	$(CXX) $(CXXFLAGS) -c Marine.cpp

Terran.o: Terran.cpp Terran.h Entity.o
	$(CXX) $(CXXFLAGS) -c Terran.cpp

Hydralisk.o: Hydralisk.cpp Hydralisk.h Zerg.o Entity.o
	$(CXX) $(CXXFLAGS) -c Hydralisk.cpp

Mutalisk.o: Mutalisk.cpp Mutalisk.h Zerg.o Entity.o
	$(CXX) $(CXXFLAGS) -c Mutalisk.cpp

Zergling.o: Zergling.cpp Zergling.h Zerg.o Entity.o
	$(CXX) $(CXXFLAGS) -c Zergling.cpp

Zerg.o: Zerg.cpp Zerg.h Entity.o
	$(CXX) $(CXXFLAGS) -c Zerg.cpp 

Entity.o: Entity.cpp Entity.h
	$(CXX) $(CXXFLAGS) -c Entity.cpp

run1:
	./proj4 proj4_map1.txt

run2:
	./proj4 proj4_map2.txt

val1:
	valgrind ./proj4 proj4_map1.txt

val2:
	valgrind ./proj4 proj4_map2.txt

clean:
	rm *~
	rm *.o
