#include "Groceries.h"

Groceries::Groceries() {
  m_item = "item1";
  m_price = 1;
  m_quantity = 1;
}

Groceries::Groceries(string item, double price, int quantity) {
  m_item = item;
  m_price = price;
  m_quantity = quantity;
}

void Groceries::setItem(string item) {
  m_item = item;
}

void Groceries::setPrice(double price) {
  m_price = price;
}

void Groceries::setQuantity(int quantity) {
  m_quantity = quantity;
}

string Groceries::getItem() {
  return m_item;
}

double Groceries::getPrice() {
  return m_price;
}

int  Groceries::getQuantity() {
  return m_quantity;
}
