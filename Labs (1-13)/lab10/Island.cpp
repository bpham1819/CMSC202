#include "Island.h"

using namespace std;

Island::Island() {

  m_myName = "default_island";
  SetType("Island"); 

}

Island::~Island() {

  m_myName = "";

}

Island::Island(string name) {

  m_myName = name;
  SetType("Island");
}

void Island::CallMyName() {

  cout << "I am a beautiful island named " << m_myName << endl;

}

void Island::DescribeMe() {

  cout << "I am surrounded by a body of water." << endl;

}

