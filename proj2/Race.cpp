#include <iostream>
#include <cstdlib>
#include "Race.h"

Race::Race() {}

void Race::StartRace() {

  int lengthOfRace;
  int userChoice;
  int winner;

  m_track.ResetLocation();
  
  m_myPlayer.SetRaces(m_myPlayer.GetRaces() + 1); //#2

  do {
    
    cout << "How long would you like the race?" << endl;
    cin >> lengthOfRace;

  } while(lengthOfRace > MAX_LENGTH || lengthOfRace < 1);

  m_track.SetLength(lengthOfRace); //#3
  m_track.PopulateObstacles();

  do {
    
    userChoice = RaceOptions();

    if(userChoice == 1)
      m_track.GetStatus();
    else
      ProgressRace(userChoice);
      
  } while(m_track.CheckWin() == -1);

  winner = m_track.CheckWin();

  if(winner == 0) {
    
    cout << "You won the race!" << endl;
    m_myPlayer.IncreaseStat();
    m_myPlayer.IncreaseWins();
    
  } else if(winner == 1 || winner == 2 || winner == 3) {
    cout << "Player " << winner << " won the race!" << endl;
  }

}

void Race::GetRacerInfo() {

  string playerName;

  cout << "What is your racer's name?" << endl;
  getline(cin, playerName);

  m_myPlayer.SetName(playerName);

}

void Race::ProgressRace(int action) {

  int difficulty = rand() % BASE_DIFFICULTY + 1; //rand # (1-100)
  int skillOfPlayer = 0;
  int numOfFalls = 0;


  string obstacleOfPlayer = m_track.ConvertObstacle(0);

  if(obstacleOfPlayer == "speed" && action  == 0) {
    skillOfPlayer = BASE_SKILL + (5 * m_myPlayer.GetSpeed());
  } else if(obstacleOfPlayer == "agility" && action  == 1) {
    skillOfPlayer = BASE_SKILL + (5 * m_myPlayer.GetAgility());
  } else if(obstacleOfPlayer == "jump" && action == 2) {
    skillOfPlayer = BASE_SKILL + (5 * m_myPlayer.GetJump());
  } else {
    skillOfPlayer = BASE_SKILL;
  }
  
  cout << "You are trying to progress the race!" << endl;

  if(skillOfPlayer >= difficulty) {

    cout << "You made it through the " << m_track.ConvertObstacle(0) << " obstacle!" << endl;
    m_track.IncrementLocation(0);

  } else {

    cout << "You fell!" << endl;
    numOfFalls++;
    m_myPlayer.SetFalls(numOfFalls);

  }
    
  ProgressComputer(difficulty);
}

bool Race::MainMenu() {

  int userChoice;

  do {
    
    cout << "What would you like to do?" << endl;
    cout << "1. Start New Race" << endl;
    cout << "2. View Racer History" << endl;
    cout << "3. Quit" << endl;
    cin >> userChoice;
    
  } while(userChoice != 1 && userChoice != 2 &&  userChoice != 3);
  
  if(userChoice == 1) {
    
    StartRace();
    return 1;
    
  } else if(userChoice == 2) {

    m_myPlayer.DisplayStatus();
    return 1;
    
  }

  return 0;  
}

int Race::RaceOptions() {

  int choice;

  do {
    
    cout << "What would you like to do?" << endl;
    cout << "1. Get Race Status" << endl;
    cout << "2. Try to Sprint (Speed)" << endl;
    cout << "3. Try to Dodge (Agility)" << endl;
    cout << "4. Try to Jump (Jump)" << endl;
    cin >> choice;

  } while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
	  
  return choice;
}

void Race::ManageGame() {

  bool menuChoice = false;
  
  RaceTitle();
  GetRacerInfo();

  do {
    menuChoice = MainMenu();
  } while(menuChoice == false);
  
  cout << "Thanks for playing UMBC Race!" << endl;

}

void Race::ProgressComputer(int obstacleDifficulty) {

  int randNumber;
  
  for(int player = 1; player < NUM_RACERS; player++) {

    randNumber = (rand() % (COMP_MAX + 1 - COMP_MIN)) + COMP_MIN;

    if(randNumber >= obstacleDifficulty) {

      cout << "Player " << player << " made it through the " << m_track.ConvertObstacle(player) << " obstacle " << endl;
      m_track.IncrementLocation(player);

    } else {
      cout << "Player " << player << " fell!" << endl;
    }
    
  }    
  
}


