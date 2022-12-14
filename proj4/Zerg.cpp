#include "Zerg.h"

Zerg::Zerg() {}

Zerg::Zerg(string name, int hp):Entity(name, hp) {}

int Zerg::Attack() {

  cout << GetName() << " deals 1 point of damage!" << endl;
  return 1;

}
