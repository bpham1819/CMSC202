#include "Game.h"

Game::Game() {

  m_myTerran = nullptr;
  m_curArea = START_AREA;
  m_curZerg = nullptr;
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  m_filename = FILE_NAME;
  m_wins = START_WINS;

}

Game::Game(string filename) {

  m_myTerran = nullptr;
  m_curArea = START_AREA;
  m_curZerg = nullptr;
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  m_filename = filename;
  m_wins = START_WINS;

}
  
Game::~Game() {

  //deconstructs Terran pointer
  delete m_myTerran;
  m_myTerran = nullptr;

  //deconstructs Zerg pointer
  delete m_curZerg;
  m_curZerg = nullptr;

  //iterates through and deletes each Area within the map
  for(int i = 0; i < int(m_myMap.size()); i++) {

    delete m_myMap.at(i);
    m_myMap.at(i) = nullptr;

  }

  m_myMap.clear();

}

void Game::LoadMap() {

  //declared variables used to store each parameter for an area
  int ID, north, east, south, west;
  string name, desc, line;

  //declared pointer to create a new area for each one
  //in the text file
  Area* newArea;

  //opens the mape file
  ifstream areaFile(m_filename);

  //loops that grabs each line before a DELIMITER pops up
  while(getline(areaFile, line, DELIMITER)) {

    ID = stoi(line); //initializes the ID var
    getline(areaFile, line, DELIMITER);
    name = line; //initializes the name var
    getline(areaFile, line, DELIMITER);
    desc = line; //initializes the description var
    getline(areaFile, line, DELIMITER);
    north = stoi(line); //initializes the north direction var
    getline(areaFile, line, DELIMITER);
    east = stoi(line); //initializes the east direction  var
    getline(areaFile, line, DELIMITER);
    south = stoi(line); //initializes the south direction var
    getline(areaFile, line, DELIMITER);
    west = stoi(line); //initializes the west direction var
    getline(areaFile, line);

    //intantiates a new area within the initialized variables
    newArea = new Area(ID, name, desc, north, east, south, west);
    m_myMap.push_back(newArea); //adds the new area to the map
    
  }

  areaFile.close(); //closes the text file that was used
  
}


void Game::TerranCreation() {

  //stored string var used for the user's name
  string terranName = "Brian";
  int selection; //var used to store the user's choice
  Entity *newTerran; // Entity pointer used to store the selected Terran

  //continues to print out the menu selection until user inputs
  //a valid number
  do {

    //Menu selection for each Terran
    cout << "Select a class" << endl;
    cout << "1. Marine" << endl;
    cout << "2. Ghost" << endl;
    cout << "3. Battlecruiser" << endl;
    cout << "4. No Class" << endl;
    cin >> selection;

  } while(selection < 1 || selection > 4);

  //A new terran will be created based on the corresponding selection
  if(selection == 1)
    newTerran = new Marine(terranName, MARINE_HEALTH);
  else if(selection == 2)
    newTerran = new Ghost(terranName, GHOST_HEALTH);
  else if(selection == 3)
    newTerran = new Battlecruiser(terranName, BATTLECRUISER_HEALTH);
  else
    newTerran = new Terran(terranName, TERRAN_HEALTH);

  //sets m_myTerran to the newly created Terran
  m_myTerran = newTerran;

}

void Game::StartGame() {
  //Simply prints the first line of the game
  cout << "Welcome to UMBC Starcraft!" << endl;

  LoadMap(); //Loads the map based on the text file used
  TerranCreation(); //creates the terran
  cout << "\n" << endl;
  //Prints the area of the first map
  m_myMap.at(m_curArea) -> PrintArea();

  //Calls the Action function to display the menu
  Action();

}

void Game::Action() {

  int choice;
  bool running = true;

  m_curZerg = RandomZerg();

  while(running) {

    do {

      cout << "What would you like to do?" << endl;
      cout << "1. Look" << endl;
      cout << "2. Move" << endl;
      cout << "3. Attack Zerg" << endl;
      cout << "4. Rest" << endl;
      cout << "5. Check Stats" << endl;
      cout << "6. Quit" << endl;
      cin >> choice;

    } while(choice < 1 || choice > 6);

    if(choice == 1) {
      m_myMap.at(m_curArea) -> PrintArea();      
    } else if(choice == 2) {
      Move();
    } else if(choice == 3) {

      if(m_curZerg == nullptr)
	cout << "There is no Zerg to Attack." << endl;
      else
	Attack();

      if(m_myTerran == nullptr)
        running = false;
      
    } else if(choice == 4) {
      Rest();
    } else if(choice == 5) {
      Stats();
    } else {
      cout << "\nGoodbye!" << endl;
      running = false;
	
    }

  }

}

Entity* Game::RandomZerg() {

  Entity* Zerg = nullptr;
  int randZerg = rand() % 4 + 1;

  if(randZerg == 1) {
    
    Zerg = new Zergling("Zergling", ZERGLING_HEALTH);
    cout << "A small terrifying zergling waits here." << endl;
    return Zerg;
    
  } else if(randZerg == 2) {
    
    Zerg = new Mutalisk("Mutalisk", MUTALISK_HEALTH);
    cout << "A large flying mutalisk hovers here." << endl;
    return Zerg;
    
  } else if(randZerg == 3) {
    
    Zerg = new Hydralisk("Hydralisk", HYDRALISK_HEALTH);
    cout << "A medium sized hydralisk slithers here waiting to cover you with acid. " << endl;
    return Zerg;
    
  }

  cout << "It is peaceful here." << endl;
  return Zerg;

}

void Game::Rest() {

  if(m_curZerg == nullptr && m_numRests > 0) {
    
    m_myTerran -> SetHealth(m_myTerran -> GetHealth() + REST_HEAL);
    m_numSpecial = NUM_SPECIAL;
    m_numRests--;

  } else if(m_curZerg == nullptr && m_numRests == 0) {
    cout << "You have no more rests." << endl;
  } else { 
    cout<< "You cannot rest with a zerg in the area." << endl;
  }

}
  
void Game::Move() {

  char direction;
  
  do {
    
    cout << "Which direction? (N E S W)" << endl;
    cin >> direction;

    if (cin.peek() == '\n')
      cin.ignore();

  } while(m_myMap.at(m_curArea) -> CheckDirection(direction) == -1);

  m_curArea = m_myMap.at(m_curArea) -> CheckDirection(direction);
 
  m_myMap.at(m_curArea) -> PrintArea();

  delete m_curZerg;
  m_curZerg = RandomZerg();
  
}

void Game::Stats() {

  cout << "Name: " << m_myTerran -> GetName() << endl;
  cout << "HP: " << m_myTerran -> GetHealth() << endl;
  cout << "Rests: " << m_numRests << endl;
  cout << "Special: " << m_numSpecial << endl;
  cout << "Wins: " << m_wins << endl;
  
}

void Game::Attack() {

  int attackType, terranAttack, zergAttack,
    zergSpecialChance = rand() % 4 + 1;
  bool zergAlive = true, terranAlive = true;
  
  while(zergAlive && terranAlive) {
    
    do {

      cout << "1. Normal Attack" << endl;
      cout << "2. Special Attack" << endl;
      cin >> attackType;

    } while(attackType < 1 || attackType > 2);

    if(attackType == 1) {
      terranAttack = m_myTerran -> Attack();
    } else {
      terranAttack = m_myTerran -> SpecialAttack();
      m_numSpecial--;
    }

    if(zergSpecialChance == 1)
      zergAttack  = m_myTerran -> SpecialAttack();
    else
      zergAttack = m_curZerg -> Attack();
  
    m_myTerran -> SetHealth(m_myTerran -> GetHealth() - zergAttack);
    m_curZerg -> SetHealth(m_curZerg -> GetHealth() - terranAttack);

    if(m_myTerran -> GetHealth() > 0 && m_curZerg -> GetHealth() > 0) {
      
      cout << *m_myTerran << endl;
      cout << *m_curZerg << endl;
      
    } else {       

      if(m_myTerran -> GetHealth() <= 0)
        terranAlive = false;

      if(m_curZerg -> GetHealth() <= 0)
        zergAlive = false;

    }

  }

  ProcessBattle(zergAlive, terranAlive);
  
}

void Game::ProcessBattle(bool zergAlive, bool terranAlive) {

  int chanceOfRest = rand() % 10 + 1;

  if(terranAlive) {
    
    cout << "You have defeated the " << m_curZerg -> GetName() << "." << endl;
    m_wins++;
    
    if(chanceOfRest == 1) {
      cout << "You have earned another rest action!" << endl;
      m_numRests++;
    }

    delete m_curZerg;
    m_curZerg = nullptr;
    
  } else if(zergAlive) {

    cout << "You were defeated by the " << m_curZerg -> GetName() << "! Damn you suck!" << endl;

    delete m_myTerran;
    m_myTerran = nullptr;
    
  } else {
    
    cout << "Both you and the " << m_curZerg -> GetName() << " self-destructed!" << endl;

    delete m_myTerran;
    m_myTerran = nullptr;
    
    delete m_curZerg;
    m_curZerg = nullptr;
    
  }

}


  


    

  
