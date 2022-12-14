#include <iostream>
#include "Player.h"

Player::Player() {

  //Calls on the setters (with the exception of m_wins) to set a Player to its default values
  SetName("Beannie");
  SetRaces(0);
  SetFalls(0);
  m_wins = 0;

  //Iterates through the stat array to set each stat to the starting value
  for(int i = 0; i < NUM_STATS; i++)
    m_stat[i] = START_STAT;

}

Player::Player(string name) {

  //Same process as the default constructor but SetName parameter is the string given from the parameter
  SetName(name);
  SetRaces(0);
  SetFalls(0);
  m_wins = 0;
  
  for(int i = 0; i < NUM_STATS; i++)
    m_stat[i] = START_STAT;
  
}

//returns m_name of player
string Player::GetName() {
  return m_name;
}

//Sets the m_name of player
void Player::SetName(string name) {
  m_name = name; 
}

//returns the value of speed located at the first index of m_stat
int Player::GetSpeed() {
  return m_stat[0];
}

//returns the value of agility located at the second index of m_stat
int Player::GetAgility() {
  return m_stat[1];
}

//returns the value of jump located at the third index of m_stat
int Player::GetJump() {
  return m_stat[2];
}

//returns the number of m_races the player has gone through
int Player::GetRaces() {
  return m_races;
}

//returns the number of m_falls the player has gone through
int Player::GetFalls() {
  return m_falls;
}

//sets m_races equal to the parameter 'races'
void Player::SetRaces(int races) {
  m_races = races;
}

//sets m_falls equal to the parameter 'falls'
void Player::SetFalls(int falls) {
  m_falls = falls;
}

void Player::DisplayStatus() {

  //Display output for the current status of the player using getters
  //for each piece of information from the player. m_wins is simply
  //printed out for the num of Wins.
  cout << "*****The Might Racer " << GetName() << "**********" << endl;
  cout << "Races: " << GetRaces() << endl;
  cout << "Wins: " << m_wins << endl;
  cout << "Falls: " << GetFalls() << "\n" << endl;
  cout << "Stats" << endl;
  cout << "Speed: " << GetSpeed()  << endl;
  cout << "Agility: " << GetAgility() << endl;
  cout << "Jump: " << GetJump() << endl;

}

void Player::IncreaseStat() {

  //Integer variable used to store the user's choice
  int statChoice = 0;

  //Loop continuously displays the options until the user correctly
  //inputs either 1, 2 or 3
  do {
   
    cout << "Which stat would you like to increase?" << endl;
    cout << "1. Speed" << endl;
    cout << "2. Agility" << endl;
    cout << "3. Jump" << endl;
    cin >> statChoice; // stores user's input into stat choice
    
  } while(statChoice != 1 || statChoice != 2 || statChoice != 3);

  //Conditional which increments the specific stat which corresponds to
  //The user's option. If the chosen stat is already maxed at 10, the
  //function will simply exit.
  if(statChoice == 1 && m_stat[0] < MAX_STAT)
    m_stat[0] += 1;
  else if(statChoice == 2 && m_stat[1] < MAX_STAT)
    m_stat[1] += 1;
  else if(statChoice == 3 && m_stat[2] < MAX_STAT) 
    m_stat[2] += 1;
  else
    return;

}

//Returns a specific stat location by setting the position to
//the parameter of the function
int Player::GetStat(int stat) {
  return m_stat[stat];
}

//Increments m_wins of player by 1
void Player::IncreaseWins() {
  m_wins += 1;
}

































