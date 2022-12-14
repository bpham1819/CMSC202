#include "Ghost.h"

Ghost::Ghost() {

  SetName("Ghost");
  SetHealth(10);

}

Ghost::Ghost(string name, int hp):Terran(name, hp) {}

Ghost::~Ghost() {}

int Ghost::SpecialAttack() {

  int specialDmg = (rand() % (12 - 1)) + 2;
  
  cout << GetName() << " performs a sneak attack!" << endl;
  cout << GetName() << " deals " << specialDmg << " damage!" << endl;
  
  return specialDmg;

}
