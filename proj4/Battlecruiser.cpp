#include "Battlecruiser.h"

Battlecruiser::Battlecruiser() {

  SetName("Battlecruiser");
  SetHealth(12);

}

Battlecruiser::Battlecruiser(string name, int hp):Terran(name, hp) {}

Battlecruiser::~Battlecruiser() {}

int Battlecruiser::SpecialAttack() {

  int specialDmg = (rand() % (12 - 2)) + 3;
  
  cout << GetName() << " uses the Yomato Cannon!" << endl;
  cout << GetName() << " deals " << specialDmg << " damage! " << endl;
  
  return specialDmg;

}

