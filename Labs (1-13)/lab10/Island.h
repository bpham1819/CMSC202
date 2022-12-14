// File: Island.h
// Desc: This is one of the child classes for lab 10
// Date: 11/5/2021
// Author: Jeremy Dixon

#ifndef ISLAND_H
#define ISLAND_H
#include "Landmass.h"
#include <iostream>
using namespace std;
 
class Island : public Landmass{
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Island();
 
  // Destructor
  // Preconditions: None
  // Postconditions: None
  ~Island();
 
  // Overloaded Constructor
  // Preconditions: None
  // Postconditions: Member variables initialized
  Island(string name);
 
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
