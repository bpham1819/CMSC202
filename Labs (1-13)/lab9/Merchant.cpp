#include "Merchant.h"

Merchant::Merchant() {}

//Name, description, dialogue, ware, price, and quantity
Merchant::Merchant(string name, string desc, string dialogue, string wares, double price, int quantity):NPC(name, desc, dialogue) {

  m_wares = wares;
  m_price = price;
  m_quantity = quantity;

}

void Merchant::Sell() { // may have to change this

  int num = 0;
  
  cout << "Selling " << m_wares << ". How many will you buy?" << endl;
  cin >> num;

  if(num > m_quantity)
    cout << "I'm sorry but we only have " << m_quantity << " " << m_wares << "." << endl;
  else 
    cout << "That'll be " << m_price * m_quantity << "." << endl;

  
}

string Merchant::GetWares() {

  return m_wares;

}

double Merchant::GetPrice() { //Returns the price of the item being sold

  return m_price;

}

int Merchant::GetQuantity() { //Returns the number of the item on hand

  return m_quantity;

}

