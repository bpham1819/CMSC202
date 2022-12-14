/*
* NPC.h
* Generic Non-player character (NPC)
* Based on this class declaration, you need to implement NPC.cpp
*/

#ifndef NPC_H
#define NPC_H
#include <iostream>
#include <string>
using namespace std;

class NPC {
public:
  NPC(); //Default constructor
  NPC(string, string, string); //Overloaded constructor where passed name, description, and dialogue
  void Talk(); //Makes the NPC talk (outputs the dialogue)
  void Description(); //Describes the NPC (outputs the description)
  string GetName(); //Getter for name
  string GetDesc(); //Getter for description
  string GetDialogue(); //Getter for dialogue
private:
  string m_name; //Name of the NPC
  string m_desc; //Descriptin of the NPC
  string m_dialogue; //What the NPC says
};

#endif
