#include "Continent.h"

using namespace std;

Continent::Continent() {

  m_myName = "default_continent";
  SetType("Continent");
  
}

Continent::~Continent() {

  m_myName = "";
  
}

Continent::Continent(string name) {

  m_myName = name;
  SetType("Continent");
}

void Continent::CallMyName() {

  cout << "I am the continent of " << m_myName << endl;

}

void Continent::DescribeMe() {

  cout << "I am one of the seven continents!"  << endl;

}

