#include "Marine.h"

Marine::Marine() {

  SetName("Marine");
  SetHealth(8);

}

Marine::Marine(string name, int hp):Terran(name, hp) {}

Marine::~Marine() {}

int Marine::SpecialAttack() {

  int specialDmg = rand() % 8 + 1;
  
  cout << GetName() << " spins up doing GATLING DAMAGE!" << endl;
  cout << GetName() << " deals " << specialDmg << " damage! " << endl;
  
  return specialDmg;

}

