#include "Mutalisk.h"

Mutalisk::Mutalisk() {

  SetName("Mutalisk");
  SetHealth(5);

}

Mutalisk::Mutalisk(string name, int hp):Zerg(name, hp) {}

int Mutalisk::SpecialAttack() {

  cout << GetName() << " blasts you with their attack!" << endl;
  return 4;

}
