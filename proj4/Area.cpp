#include "Area.h"

Area::Area(int id, string name, string desc, int north, int east, int south, int west) {

  m_ID = id;
  m_name = name;
  m_desc = desc;

  m_direction[0] = north;
  m_direction[1] = east;
  m_direction[2] = south;
  m_direction[3] = west;

}

string Area::GetName() {
  return m_name;
}

int Area::GetID() {
  return m_ID;
}

string Area::GetDesc() {
  return m_desc;
}

int Area::CheckDirection(char myDirection) {

  int directionArg;

  if(myDirection == 'n' || myDirection == 'N')
    directionArg = 0;
  else if(myDirection == 'e' || myDirection == 'E')
    directionArg = 1;
  else if(myDirection == 's' || myDirection == 'S')
    directionArg = 2;
  else if(myDirection == 'w' || myDirection == 'W')
    directionArg = 3;

  switch(directionArg) {
  case N:
    return m_direction[N];
  case E:
    return m_direction[E];
  case S:
    return m_direction[S];
  case W:
    return m_direction[W];
  default:
    return -1;    
  }

}

void Area::PrintArea() {

  cout << m_name << endl;
  cout << m_desc << endl;
  cout << "Possible Exits: ";

  for(int i = 0; i < 4; i++) {
    
    if(m_direction[i] != -1 && i == 0)
       cout << "N ";
    else if(m_direction[i] != -1 && i == 1)
      cout << "E ";
    else if(m_direction[i] != -1 && i == 2)
      cout << "S ";
    else if(m_direction[i] != -1 && i == 3)
      cout << "W ";
    
  }

  cout << "\n";
  
}
