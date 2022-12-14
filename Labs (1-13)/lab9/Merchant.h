/*
* Merchant.h
* Based on this class declaration - you need to implement Merchant.cpp
*/

#ifndef MERCHANT_H
#define MERCHANT_H
#include "NPC.h"

class Merchant : public NPC {
public:
  //Default constructor
  Merchant();
  //Overloaded constructor
  //Name, description, dialogue, ware, price, and quantity
  Merchant(string, string, string, string, double, int); 
  void Sell();
  string GetWares(); //Returns the name of item being sold
  double GetPrice(); //Returns the price of the item being sold
  int GetQuantity(); //Returns the number of the item on hand
private:
  string m_wares; //Name of item that merchant sells (should be a weapon for the story to make sense)
  double m_price; //Price of the item that the merchant sells
  int m_quantity; //How many of the item that the merchant has in stock
};

#endif
