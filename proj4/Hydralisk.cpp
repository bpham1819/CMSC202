#include "Hydralisk.h"

Hydralisk::Hydralisk() {

  SetName("Hydralisk");
  SetHealth(7);

}

Hydralisk::Hydralisk(string name, int hp):Zerg(name, hp) {}

int Hydralisk::SpecialAttack() {

  cout << GetName() << "sprays you with a deadly acid!" << endl;
  return 2;

}
