#include "NPC.h"

NPC::NPC() {} //Look at Lab doc later

NPC::NPC(string name, string desc, string dialogue) {

  m_name = name;
  m_desc = desc;
  m_dialogue = dialogue;
  
}

void NPC::Talk() { //Makes the NPC talk (outputs the dialogue)

  cout << m_dialogue;

}

void NPC::Description() { //Describes the NPC (outputs the description)

  cout << m_desc << endl;

}


string NPC::GetName() { //Getter for name

  return m_name;

}


string NPC::GetDesc() { //Getter for description

  return m_desc;

}


string NPC::GetDialogue() { //Getter for dialogue

  return m_dialogue;

}
