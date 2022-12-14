//File: lab6.cpp                                                                                                              

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Groceries.h"
using namespace std;

//COMPLETE THIS FUNCTION                                                                                                      
void fillVector(vector<Groceries> &groceryList){

  string itemName;
  double price;
  int quantity, numItems;
  // ask for amount of grocery items

  cout << "How many grocery items do you want to add to the list?" << endl;
  cin >> numItems;

  
  // ask for name, price, quantity of each item and                                                                           
  // add completed grocery item to vector

    for(int i = 0 ; i < numItems; i++) {
      cout << "Enter name of grocery item: " << endl;
      cin >> itemName;

      cout << "Enter price: " << endl;
      cin >> price;

      cout << "Enter quantity: " << endl;
      cin >> quantity;

      groceryList.push_back(Groceries(itemName, price, quantity));

    }
}

//COMPLETE THIS FUNCTION                                                                                                      
void printVectorWithoutIterator(vector<Groceries> &groceryList){

  // print each item's name, price, and quantity with correct                                                                 
  // precision for price                                                                                                      
  // DON'T USE ITERATOR

      cout << "Grocery List (without Iterator): " << "\n" << endl;
    
      for(int i = 0; i < (int)groceryList.size(); i++) { 
        
        cout << groceryList[i].getItem() << " " << "(" << groceryList[i].getQuantity()
	<< ") : $" << fixed << setprecision(2) << groceryList[i].getPrice() << endl;

      }
}

//COMPLETE THIS FUNCTION                                                                                                      
void printVectorWithIterator(vector<Groceries> &groceryList){

  // print each item's name, price, and quantity with correct                                                                 
  // precision for price                                                                                                      
  // USE ITERATOR
      
  cout << "Grocery List (with Iterator): " << "\n" << endl;

    for (vector<Groceries>::iterator it = groceryList.begin(); it != groceryList.end(); ++it) {
      
      Groceries x = *it;
      cout << x.getItem() << " " << x.getPrice() << " " << x.getQuantity() << endl;
      
    }
}

void checkStatus(vector<Groceries> &groceryList){

  //DEFINE ENUM HERE BASED ON NAMES BELOW
  enum Status {nonMem, bronze, silver};
  
  int listSize = groceryList.size();

  switch (listSize) {
  case nonMem: cout << "You did not purchase enough items to become a member." << endl;
    break;
  case bronze: cout << "You purchased enough items to become a bronze member." << endl;
    break;
  case silver: cout << "You purchased enough items to become a silver member." << endl;
    break;
  default: cout << "You purchased enough items to become a gold member!" << endl;
  }
}

int main(){

  vector<Groceries> groceryList; //Creates a new vector of Groceries

  fillVector(groceryList); //Populates the vector of Groceries
  printVectorWithoutIterator(groceryList); //Displays the contents of the vector
  cout << endl;
  printVectorWithIterator(groceryList); //Alterate way to display the contents of the vector
  checkStatus(groceryList); //calls function defined above (must define enum)

  return 0;
}
