// File: Continent.h
// Desc: This is one of the child classes for lab 10
// Date: 11/5/2021
// Author: Jeremy Dixon

#ifndef CONTINENT_H
#define CONTINENT_H
#include "Landmass.h"
#include <iostream>
using namespace std;
 
class Continent : public Landmass{
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Continent();
 
  // Destructor
  // Preconditions: None
  // Postconditions: None
  ~Continent();
 
  // Overloaded Constructor
  // Preconditions: None
  // Postconditions: Member variables initialized
  Continent(string name);
 
  // callMyName - Prints name
  // Preconditions: Has a name
  // Postconditions: None
  void CallMyName();
 
  // describeMe() - gives description of given landmass
  // Preconditions: None
  // Postconditions: None
  void DescribeMe();
 
private:
  string m_myName;
 
};
 
#endif

