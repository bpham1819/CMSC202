/*
File: ArcaneEquipment.h
Header file for the Arcane Equipment class
*/
#ifndef ARCANE_EQUIPMENT_H
#define ARCANE_EQUIPMENT_H

#include <iostream>
#include <string>
using namespace std;

class ArcaneEquipment {
public:
  //Default Constructor
  ArcaneEquipment();
  
  //Copy Constructor
  ArcaneEquipment(const ArcaneEquipment &source);
  
  //Overloaded Assignment Operator
  ArcaneEquipment &operator=(const ArcaneEquipment &source);

  //Destructor
  ~ArcaneEquipment();
  
  //Getter for m_numItems
  int GetNumItems();

  //Inserts equipment into the items array
  void Insert(const string &equipment);

  //Removes the last piece of equipment from the items array
  void DeleteLast();

  //Friend Function, overloaded << operator
  friend ostream &operator<<(ostream &os, const ArcaneEquipment &source);

private:
  int m_numItems;            //Current number of items in the m_items array
  string *m_items;           //Array of equipment
  const int m_CAPACITY = 13; //Maximum capacity of the m_items array.
};

#endif
