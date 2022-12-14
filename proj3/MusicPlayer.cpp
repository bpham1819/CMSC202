/*****************************************
 ** File:    MusicPlayer.cpp
 ** Project: CMSC 202 Project 3, Fall 2022
 ** Author:  Brian Pham
 ** Date:    11/3/2022
 ** Section: 11:30/12:45
 ** E-mail:  bpham3@umbc.edu
 **
 ** This file contains the cpp file for MusicPlayer.h
 ** This program is contains definitiions needed for the
 ** MusicPlayer to operate so that the program can run.
 ***********************************************/
#include <fstream>
#include "MusicPlayer.h"

MusicPlayer::MusicPlayer() {
  m_playList = new Playlist();
}

MusicPlayer::~MusicPlayer() {

  //Iterates through every song to delete and set to null
  for(int i = 0; i < int(m_songCatalog.size()); i++) {
    delete m_songCatalog.at(i);
    m_songCatalog.at(i) = nullptr;
  }

  //clears the song catalog
  m_songCatalog.clear();

  //deletes playlist and sets it to null
  delete m_playList;
  m_playList = nullptr;

}

void MusicPlayer::LoadCatalog(string filename) {

  //title & artist strings are used to store the info
  //needed for song object
  //Line string is declared to store the parsed info from the input file
  string title, artist, line;
  int year, rank; //year and rank integers are used to store the info needed for song
  Song* song; //Song declared to represent each song name/info from the input file

  //declares the file stream and opens the file
  ifstream catalog(filename);

  //process continues as long as there is a long to be parsed in the input file
  while(getline(catalog, line, DELIMITER)) {

    title = line; //obtains title from the song
    getline(catalog, line, DELIMITER); //parses the line until the DELIMITER '|' is reached
    artist = line; //stores the artist from the song
    getline(catalog, line, DELIMITER);
    year = stoi(line); //stores the year from the song
    getline(catalog, line);
    rank = stoi(line); //stores the rank from the song


    //takes each stored value and forms the the new song to be stored in the catalog
    song = new Song(title, artist, year, rank);
    m_songCatalog.push_back(song); // adds a song to the end of the catalog

  }

  //closes the file stream
  catalog.close();
}

void MusicPlayer::MainMenu() {

  //integer used to store the user input
  int choice;
  //bool used for the loop
  bool start = true;

  cout << "Songs loaded: " << int(m_songCatalog.size()) << endl;

  //continues to display the user's options until the user inputs 5 (quits)
  while(start) {

    //continues to display options until user's input is valid
    do {

      cout << "What would you like to do?" << endl;
      cout << "1. Display Songs by Year" << endl;
      cout << "2. Add Song" << endl;
      cout << "3. Display Playlist" << endl;
      cout << "4. Play Song" << endl;
      cout << "5. Quit" << endl;
      cin >> choice;

    } while(choice < 1 || choice > 5);

    //The corresponding function will process based on the user's input
    if(choice == 1)
      DisplaySongs();
    if(choice == 2)
      AddSong();
    if(choice == 3)
      DisplayPlaylist();
    if(choice == 4)
      PlaySong();
    if(choice == 5)
      start = false;

  }
  
}

void MusicPlayer::DisplaySongs() {

  int year; //integer used to store the user's input

  //continues to ask the user for the year to display until user's input is valid
  do {
    
    cout << "Which year would you like to display? (2010-2021)" << endl;
    cin >> year;

  } while(year < LOW_YEAR || year > HIGH_YEAR);

  cout << "*****" << year << "*****" << endl;

  //iterates through every song within the song catalog that corresponds to the selected year
  for(int i = 0; i < int(m_songCatalog.size()); i++) {

    if(m_songCatalog.at(i)->GetYear() == year) {
      //Displays the song information using the overloaded operator from
      //the Song class
      cout << i + 1 << ". " << *m_songCatalog.at(i) << endl;
    }

  }
  
}

void MusicPlayer::AddSong() {

  //title & artist strings as well as year & artist integers
  //are used to store the info needed for AddSong argument in playlist
  string title, artist;
  int year, rank, songNum;

  //Display for if the playlist is empty
  if(m_playList->Size() == 0)
    cout << "***Current Playlist is Empty***" << endl;

  cout << "Choose the songs you would like to add to the playlist." << endl;

  //Displays the songs from the songCatalog based on the selected year
  DisplaySongs();

  //continues to ask the user for the song to add until user's input is valid
  do {
    
  cout << "Enter the number of the song you would like to add: " << endl;
  cin >> songNum;

  } while(songNum < 1 || songNum > 1200);

  //stores the title, artist, year, and rank of that song to its corresponding variables
  title = m_songCatalog.at(songNum - 1) -> GetTitle();
  artist = m_songCatalog.at(songNum - 1) -> GetArtist();
  year = m_songCatalog.at(songNum - 1) -> GetYear();
  rank = m_songCatalog.at(songNum - 1) -> GetRank();

  //Adds the song to the playlist
  m_playList -> AddSong(title, artist, year, rank);

  //Displays the song info of the song that was added
  cout << "Added: " << *m_playList -> GetPlaylistDetails(m_playList -> Size() - 1) << endl;

}


void MusicPlayer::DisplayPlaylist() {

  //Display for if the playlist is empty
  if(m_playList -> Size() == 0) {
    
    cout << "***Current Playlist is Empty***" << endl;
    return;
    
  }
  
  cout << "Your Playlist" << endl;

  //Iterates through the playlist and displays every song in it
  for(int i = 0; i < m_playList -> Size(); i++) { 
    cout << i + 1 << ". " << *m_playList -> GetPlaylistDetails(i) << endl;
  }

}

void MusicPlayer::PlaySong() {

  int songNum; //stores the user inputs

  //Calls the displayplaylist function to display if the playlist is empty
  if(m_playList -> Size() == 0) {
    
     DisplayPlaylist();
     return;
     
  }

  DisplayPlaylist();
  
  //continues to ask the user for the song number until user's input is valid
  do {
    
    cout << "Which song would you like to play?" << endl;
    cin >> songNum;

  } while(songNum < 1 || songNum > m_playList -> Size());

  //Displays the song that was selected to play
  cout << "Played: " << *m_playList -> GetPlaylistDetails(songNum - 1) << endl;

  //Calls on playlist PlayAt function to "Play" (remove) the song
  m_playList -> PlayAt(songNum - 1);
  
}

  
