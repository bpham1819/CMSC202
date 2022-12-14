#include "Processor.h"
 
Processor::Processor(string filename) {
  m_fileName = filename;  
}

Processor::~Processor() {

  //iterates through m_processes until each process is deleted
  //from the vector
  for(int i = 0; i < int(m_processes.size()); i++) {
    delete m_processes.at(i);
    m_processes.at(i) = nullptr;
  }

  //clears m_proceses
  m_processes.clear();

  //iterates through m_threads
  for(int x = 0; x < NUM_THREADS; x++) {
    
      //removes all the processes in the current thread (x)
      m_threads.at(x) -> Clear();

      //deletes each thread and sets them equal to null
      delete m_threads.at(x);
      m_threads.at(x) = nullptr;
    
  }

  //clears m_threads
  m_threads.clear();
    
}

void Processor::InitializeProcessor() {

  DisplayTitle();
  LoadProcesses(m_fileName);
  PopulateThreads();
  MainMenu();

}

bool Processor::LoadProcesses(string filename) {

  //name stores the process's name
  //line stores the line received from the txt file
  string name, line;
  //id, call, and duration obtained from each Process
  int id, call, duration;

  //Used to create the newProcess to store in m_processes
  Process *newProcess;

  //Declares file and opens the file passed in
  ifstream file(filename);
   
  //process continues as long as there is a long to be parsed in the input file
  while(getline(file, line, DELIMITER)) {

    name = line; //stores the name from the process
    getline(file, line, DELIMITER); //parses the line until the DELIMITER '|' is reached
    id = stoi(line); //stores the id from the process
    getline(file, line, DELIMITER);
    call = stoi(line); //stores the call from the process
    getline(file, line);
    duration = stoi(line); //stores the duration from the process

    //instantiates a new process using the name, id, call, and duration obtained
    newProcess = new Process(name, id, call, duration);

    //adds the new process into m_processes vector
    m_processes.push_back(newProcess);

  }
  
  //closes the file stream
  file.close();

  //If m_processes is not populated, the file was not read
  //and thus the function returns false;
  if(int(m_processes.size()) == 0)
    return false;

  //loop iterates over the number of threads in m_threads
  for(int i = 0; i < NUM_THREADS; i++) {
    //adds a new thread with its corresponding process to m_threads
    AddThread(m_processes.at(i));
  }
  
  //returns true indicating that the file was read
  return true;
  
}

void Processor::AddThread(Process* baseProcess) {

  //Is executed if m_threads isn't at capacity
  if(int(m_threads.size()) < NUM_THREADS) {
    
    //Creates the new thread to add to m_threads
    Lstack<Process*>* newThread = new Lstack<Process*>();

    //Adds the base process to newThread
    newThread -> Push(baseProcess);

    //Adds the newThread to m_threads
    m_threads.push_back(newThread);
    
  }
  
}

int Processor::GetProcessCalled(int id) {

  //index that is preset to -1 if id was not found
  int index = -1;

  //loops through all processes to find a matching id
  for(int i = 0; i < int(m_processes.size()); i++) {

    //if id is matched, index now equals the location of that
    //particular process
    if(m_processes.at(i) -> m_id == id)
      index = i;

  }

  //returns the index
  return index;
  
}

void Processor::PopulateThreads() {

  //Iterates through m_threads based on the NUM_THREADS
  for(int x = 0; x < NUM_THREADS; x++) {
    
    //loop will continue to add processes until the current process's
    //m_call is -1
    while(m_threads.at(x) -> Top() -> m_call != -1) {

      //Adds the new process (based on the current process's m_call)
      //to the corresponding thread and uses GetProcessCalled
      //to locate the specific process in m_processes
      m_threads.at(x) -> Push(m_processes.at(GetProcessCalled(m_threads.at(x) -> Top() -> m_call)));
      
    }
    
  }

}

void Processor::MainMenu() {

  int input; //stores the user input
  bool running = true; //bool var to keep the MainMenu running
  //Displays the menu to the user and checks for input validation

  //MainMenu continues to run until user quits
  while(running) {
    
    do {

      cout << "Choose an option " << endl;
      cout << "1. Display Threads " << endl;
      cout << "2. Start Thread " << endl;
      cout << "3. Quit " << endl;
      cin >> input; //user enters their option

    } while(input < 1 || input > 3);

    if(input == 1) //Calls DisplayThreads if user input = 1
      DisplayThread(); 
    else if(input == 2) //Calls StartThreads if user input = 2
      StartThreads();
    else { //prints statement and quits the UMBC Processor
      cout << "Thank you for trying UMBC Processor! " << endl;
      running = false;
    }

  }

}

void Processor::DisplayProcesses() {

  //Iterates through m_processes and displays each process
  for(int i = 0; i < int(m_processes.size()); i++)
    cout << *m_processes.at(i);

}

void Processor::ListThreads() {

  //Iterates through the amount of threads in m_threads and
  //prints each thread with the amount of processes each contains in
  //a numbered list
  for(int i = 0; i < NUM_THREADS; i++)
    cout << i + 1 << ". Thread " << i + 1 <<" ("
	 << m_threads.at(i) -> GetSize() << " processes)" << endl;

}

int Processor::ChooseThread() {

  int input; //used to store the user input

  //Used to check for input validation
  do {

    cout << "What thread would you like to view?" << endl;
    //ListThreads is called to display each thread and their number of processes
    ListThreads();
    cin >> input; //user enters choice of thread

  } while(input < 1 || input > NUM_THREADS);

  return input - 1;

}

void Processor::DisplayThread() {

  //stores the index of the chosen thread
  int threadLocation = ChooseThread();

  //iterates through each thread
  for(int i = 0; i < m_threads.at(threadLocation) -> GetSize(); i++)
    cout << *m_threads.at(threadLocation) -> At(i);

}

void Processor::StartThreads() {
  
  //Iterates through m_threads based on the NUM_THREADS
  for(int x = 0; x < NUM_THREADS; x++) {

    int totalDuration = 0; //stores the total duration for each process
    
    //Iterates through the current thread
    for(int y = 0; y < m_threads.at(x) -> GetSize(); y++)      
      totalDuration += m_threads.at(x) -> At(y) -> m_duration;

    //Prints out the total duration of the current thread
    cout << "Thread " << x + 1 << " took " << totalDuration << " milliseconds to complete" << endl;

    m_threads.at(x) -> Clear();

  }

}

void Processor::DisplayTitle() {
  cout << "Welcome to UMBC Processor!" << endl;
}
