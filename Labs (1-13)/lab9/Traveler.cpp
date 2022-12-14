#include "Traveler.h"

Traveler::Traveler() {}

//name, desc, dialogue, origin, weapon, and power
Traveler::Traveler(string name, string desc, string dialogue, string origin, string weapon, int power):NPC(name, desc, dialogue) {
  

  m_origin = origin;
  m_weapon = weapon;
  m_power = power;
  
}

void Traveler::Fight(int myPower) { //Compares the traveler's power vs the user's power and indicates who won the fight
  
  if(myPower > GetPower())
    cout << "You defeated " << GetName() << "!" << endl;
  else if(myPower < GetPower())
    cout << "You lost to " << GetName() << "!" << endl;
  else
    cout << "Your power and " << GetName() << "'s power are equally matched!" << endl;

}

void Traveler::Inquire() { //Outputs which town the traveler is from

  cout << "I am from " << GetOrigin() << ".";

}

string Traveler::GetOrigin() { //Returns the town the traveler is from

  return m_origin;

}

string Traveler::GetWeapon() { //Returns the weapon the traveler has

  return m_weapon;

}

int Traveler::GetPower() { //Returns the power of the traveler

  return m_power;

}
