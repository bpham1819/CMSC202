#include "Terran.h"

Terran::Terran() {

  SetName("Terran");
  SetHealth(10);

}


Terran::Terran(string name, int hp):Entity(name, hp) {}

Terran::~Terran() {}

int Terran::Attack() {

  int dmg = rand() % 6 + 1;
  cout << GetName() << " attacks dealing " << dmg << " damage" << endl;
  return dmg;

}

int Terran::SpecialAttack() {

  cout<< "Terran does not have a special attack." << endl;
  return 0;

}

