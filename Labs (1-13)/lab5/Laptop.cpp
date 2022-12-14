#include "Laptop.h"
/**********
* File: Laptop.cpp
*
* Intended for Lab 5: Classes
*
**********/

//Constructor -- Already Implemented
Laptop::Laptop() {
  cout << "Manufacturing a Laptop..." << endl;
}
//Implement Getters here
string Laptop::GetBrand() {
  return m_brand;
}

double Laptop::GetPrice() {
  return m_price;
}

int Laptop::GetMemory() {
  return m_memory;
}

bool Laptop::GetBacklit() {
  return m_isBacklit;
}

//Implement Setters here

void Laptop::SetBrand(string s) {
  m_brand = s;
}

void Laptop::SetPrice(double y) {
  m_price = y;
}

void Laptop::SetMemory(int m) {
  m_memory = m;
}

void Laptop::SetBacklit(bool isBacklit) {
  m_isBacklit = isBacklit;
}

//Implement WorthIt here
//Should be greater than or equal to 8gb memory, less than $1000, and backlit to be "worth it
bool Laptop:: WorthIt() {

  if(m_memory >= 8 && m_price < 1000) {
    SetBacklit(true);
  } else {
    SetBacklit(false);
  }
  
  return GetBacklit();
}


