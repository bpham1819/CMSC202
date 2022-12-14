/*
File: ArcaneEquipment.cpp
*/

#include "ArcaneEquipment.h"

//Default constructor
ArcaneEquipment::ArcaneEquipment(){
  m_numItems = 0;
  m_items = new string[m_CAPACITY];
}

//Implement Copy Constructor here
ArcaneEquipment::ArcaneEquipment(const ArcaneEquipment &source) {

  m_numItems = source.m_numItems;
  m_items = new string[m_CAPACITY];

  for(int i = 0; i < source.m_numItems; i++) {

    m_items[i] = source.m_items[i];

  }  

}

//Implement Overloaded Assignment Operator here
ArcaneEquipment& ArcaneEquipment::operator=(const ArcaneEquipment &source) {

  if(this != &source) {

    delete [] m_items;

    m_numItems = source.m_numItems;
    m_items = new string[m_CAPACITY];

    for(int i = 0; i < source.m_numItems; i++) {

      m_items[i] = source.m_items[i];

    }

  }

  return *this;
    
}

//Implement Destructor here

ArcaneEquipment::~ArcaneEquipment() {

  delete [] m_items;
  m_items = nullptr;
  
}



int ArcaneEquipment::GetNumItems() {
  return m_numItems;
}

void ArcaneEquipment::Insert(const string &equipment) {
  if (m_numItems >= m_CAPACITY){
    cout << "Equipment Capacity Hit" << endl;
  }else {
    m_items[m_numItems++] = equipment;
  }
}

void ArcaneEquipment::DeleteLast() {
  if (m_numItems == 0) {
    cout << "The list is empty!" << endl;
  } else {
    m_items[--m_numItems] = "";
  }
}

ostream &operator<<(ostream &os, const ArcaneEquipment &source) {
  os << "Arcane Equipment List: (SIZE : " << source.m_numItems << ")" << endl;
  for (int i = 0; i < source.m_numItems; i++) {
    os << i + 1 << ". " << source.m_items[i] << endl;
  }
  return os;
}
