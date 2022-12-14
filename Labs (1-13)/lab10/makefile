CXX = g++
CXXFLAGS = -Wall

driver: Landmass.o Island.o Continent.o driver.cpp
	$(CXX) $(CXXFLAGS) Landmass.o Island.o Continent.o driver.cpp -o driver

Continent.o: Continent.h Continent.cpp Landmass.o
	$(CXX) $(CXXFLAGS) -c Continent.cpp

Island.o: Island.h Island.cpp Landmass.o
	$(CXX) $(CXXFLAGS) -c Island.cpp

Landmass.o: Landmass.h Landmass.cpp
	$(CXX) $(CXXFLAGS) -c Landmass.cpp

run:
	./driver

clean:
	rm *~
