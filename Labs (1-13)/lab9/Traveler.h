/*
* Traveler.h
* Based on this class declaration, you need to implement the Traveler.cpp file
*/
#ifndef TRAVELER_H
#define TRAVELER_H
#include "NPC.h"

class Traveler : public NPC {
public:
  Traveler(); //Default constructor
  Traveler(string, string, string, string, string, int); //name, desc, dialogue, origin, weapon, and power
  void Fight(int); //Compares the traveler's power vs the user's power and indicates who won the fight
  void Inquire(); //Outputs which town the traveler is from
  string GetOrigin(); //Returns the town the traveler is from
  string GetWeapon(); //Returns the weapon the traveler has
  int GetPower(); //Returns the power of the traveler
private:
  string m_origin; //Town the traveler is from
  string m_weapon; //Name of the weapon the traveler uses
  int m_power; //Power of the traveler for when you fight
};

#endif
