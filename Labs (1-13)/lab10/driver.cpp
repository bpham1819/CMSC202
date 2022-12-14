#include "Island.h"
#include "Landmass.h"
#include "Continent.h"
#include <iostream>

int main(){

  // Instantiation of child objects
  Island island("Chios");
  Continent NA("North America");

  // Landmass Pointers to child objects (Polymorphism)
  Landmass *island1 = &island;
  Landmass *continent1 = &NA;

  // Island functions calls
  island1->CallMyType();
  island1->CallMyName();
  island1->DescribeMe();

  cout << endl;

  // Continent function calls
  continent1->CallMyType();
  continent1->CallMyName();
  continent1->DescribeMe();

  return 0;
}
