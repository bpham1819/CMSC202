// File: Landmass.h
// Desc: This is the parent class for lab 10
// Date: 11/5/2021
// Author: Jeremy Dixon

#ifndef LANDMASS_H
#define LANDMASS_H
#include <iostream>
using namespace std;
 
class Landmass{
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Landmass();
 
  // Destructor
  // Preconditions: None
  // Postconditions: None
  ~Landmass();
 
  // callMyType() - Prints object's type
  // Preconditions: Object exists
  // Postconditions: Object's type is printed
  virtual void CallMyType();
 
  // callMyName() - Prints object's name
  // Preconditions: Object exists
  // Postconditions: Object's name is printed
  virtual void CallMyName() = 0; // <- Declares as purely virtual function
 
  // getType() - returns myType
  // Preconditions: myType is initialized
  // Postconditions: None
  string GetType();
 
  // setType() - sets value of myType
  // Preconditions: None
  // Postconditions: None
  void SetType(string type);
 
  // describeMe() - gives description of given landmass
  // Preconditions: None
  // Postconditions: None
  virtual void DescribeMe() = 0;
 
private:
  string m_myType;
};
 
#endif
