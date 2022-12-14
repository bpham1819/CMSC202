#include "Landmass.h"

using namespace std;

Landmass::Landmass() {

  m_myType = "";

}

Landmass::~Landmass() {}

void Landmass::CallMyType() {

  cout << "My type is " << m_myType << endl;

}

string Landmass::GetType() {
  return m_myType;
}

void Landmass::SetType(string type) {
  m_myType = type;
}
