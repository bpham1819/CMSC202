/*
 * Lab9.cpp
 * Inheritance
 * This lab explores inheritance through the lens of NPC's (Non-Player Characters) in a hypothetical game
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "NPC.h"
#include "Merchant.h"
#include "Traveler.h"

using namespace std;

// Requirement 1 - Populate these values (think of it like a mad libs!)

const string TOWN = "Littleville";

// STATISTICS (these can be whatever your creative mind desires)
//Basic NPC Stats
const string NPC_NAME = "Bob"; //Random townperson
const string NPC_DESC = "I am just an NPC..."; //Description of townsperson
const string NPC_DIALOGUE = "Welcome to Littleville!";//Townsperson's greeting

//Merchant Stats
const string M_NAME = "Charlie"; //Name of the Merchant
const string M_DESC = "I am the Merchant."; //Desc of Merchant
const string M_DIALOGUE = "Welcome to my Store!"; //Greeting of Merchant
const string M_WARES = "Sword"; //Weapon that the merchant sells
const double M_PRICE = 10.50; //Price of item
const int M_QUANTITY = 3; //Quantity of item in stock

//Traveler Stats
const string T_NAME = "Ryan"; //Name of enemy
const string T_DESC = "The ENEMY is awaiting"; //Desc of enemy
const string T_DIALOGUE = "I am the only Traveler"; //What the enemy says to you
const string T_ORIGIN = "Bigville"; //Where the enemy is from
const string T_WEAPON = "Daggers"; //Enemy's weapon
const int T_POWER = 50; //Enemy's initial power (from 1 - 100)

int main(){
  srand(time(NULL)); //Randomization for calculating starting power
  NPC npc(NPC_NAME, NPC_DESC, NPC_DIALOGUE); //Create a new generic NPC
  Merchant merchant(M_NAME, M_DESC, M_DIALOGUE, M_WARES, M_PRICE, M_QUANTITY); //Create a new merchant
  Traveler traveler(T_NAME, T_DESC, T_DIALOGUE, T_ORIGIN, T_WEAPON, T_POWER); //Create a new traveler (enemy)

  string name;
  int power = rand()%100+1; //Give the user a power between 1 - 100

  //Request general information from user
  cout << "Your Name: ";
  getline(cin, name, '\n');

  /* Beginning of adventure */
    cout << "Welcome to your Adventure!" << endl << endl;
  cout << endl << "You stop to rest from your long travels in a town by the name of " << TOWN
       << "." << endl;
  
  /* Encounter a town person (generic NPC) */
  cout << "You come upon a local townsperson." << endl;
  npc.Description();
  cout << endl << endl;
  cout << "You approach them." << endl;
  cout << npc.GetName() << ": \"";
  npc.Talk();
  cout << "\"" << endl;
  cout << "You cannot think of a reply so you leave." << endl << endl;
  
  //You meet a new NPC (a traveler)
  cout << "You come upon another traveler." << endl;
  cout << "They make you feel a little uneasy." << endl;
  traveler.Description();
  cout << "You decide to introduce yourself." << endl;
  cout << name << ": \"Hello!\"" << endl;
  cout << traveler.GetName() << ": \"";
  traveler.Talk();
  cout << "\"" << endl;
  cout << "You think his greeting peculiar and ask him where he is from." << endl;
  cout << traveler.GetName() << ": \"";
  traveler.Inquire();
  cout << "\"" << endl << endl;

  cout << "You've never liked anyone from " << traveler.GetOrigin()
       << "." << endl;
  cout << "You want to challenge " << traveler.GetName() << " to a duel." << endl;
  cout << "However, you are weaponless so you need to go to a shop to buy a new weapon.";
  cout << endl << endl;

  //Visit Merchant to buy weapon
  cout << "You look around the small town for a shop, and soon find one. You walk in." << endl;
  merchant.Description();
  cout << endl;
  cout << merchant.GetName() << ": \"";
  merchant.Talk();
  cout << "\"" << endl;
  
  merchant.Sell();
  cout << "With your supplies refilled, you head off to duel." << endl << endl;

  //Traveler Part 2
  cout << "You make your way back for the duel." << endl;
  traveler.Fight(power);
  cout << "You leave, never turning back." << endl;

  return 0;
}
