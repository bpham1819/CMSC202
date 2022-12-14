/**********
* File: Laptop.h
*
* Intended for Lab 5: Classes
*
**********/

#ifndef LAPTOP_H //Protects against multiple inclusion
#define LAPTOP_H //Protects against multiple inclusion

#include <iostream>
#include <string>

using namespace std;

class Laptop {
 public:
  Laptop();
  string GetBrand();
  double GetPrice();
  int GetMemory();
  bool GetBacklit();
  void  SetBrand(string);
  void  SetPrice(double);
  void  SetMemory(int);
  void  SetBacklit(bool);
  bool WorthIt();
 private:
  string m_brand;
  double m_price;
  int m_memory;
  bool m_isBacklit;
};

//Declare the Laptop class here
//Include a generic constructor, all getters and setters for four variables, and WorthIt function



#endif
