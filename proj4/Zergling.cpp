#include "Zergling.h"

Zergling::Zergling() {

  SetName("Zergling");
  SetHealth(3);

}

Zergling::Zergling(string name, int hp):Zerg(name, hp) {}

int Zergling::SpecialAttack() {

  cout << GetName() << "scratches at you ferociously!" << endl;

  return 1;

}
