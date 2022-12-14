/*****************************************
 ** File:    Playlist.cpp
 ** Project: CMSC 202 Project 3, Fall 2022
 ** Author:  Brian Pham
 ** Date:    11/3/2022
 ** Section: 11:30/12:45
 ** E-mail:  bpham3@umbc.edu
 **
 ** This file contains the cpp file for Playlist.h
 ** This program is contains definitions needed to manipulate a
 ** playlist object or pointer so that it can exists within
 ** the MusicPlayer.
 ***********************************************/
#include "Playlist.h"

Playlist::Playlist() {

  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;

}

Playlist::~Playlist() {

  //Loops until every node within playlist is deleted
  while(m_size > 0) {

    //If there's only one song in the playlist, it'll delete m_head
    //and decrements the size by one
    if(m_size == 1) {

      delete m_head;
      m_head = nullptr;
      m_tail = nullptr;
      m_size--;
       
    } else {
      
      Song* temp = m_head; //Create a temp node and set it to the head node

      //sets m_head to the node after it
      m_head = m_head -> GetNext();
      delete temp; //deletes the node previously stored as m_head
      temp = nullptr;
      m_size--; //Decrement the size

    }
  }

}

void Playlist::AddSong(string title, string artist, int year, int rank) {

  //Stores the information within the arguement as a new song object
  Song* newSong = new Song(title, artist, year, rank);

  //If the playlist is empty, m_head/m_tail is set to the new song and size is incremented
  if(m_size == 0) {
    m_head = newSong;
    m_tail = newSong;
    m_size++;
    return;
  } else {
    //Sets m_tail to the new song
    m_tail -> SetNext(newSong);
    //m_next of the newSong ptr is set to nullptr as the last node in playlist
    newSong -> SetNext(nullptr);
    //m_tail now the song last added
    m_tail = newSong;
    m_size++; //size incremented
  }
}

Song* Playlist::GetPlaylistDetails(int location) {
  
  Song* curr = m_head; //a song ptr to iterate through the Playlist
  Song* song; //a song ptr to store the song (from the playlist) to return
  int ctr = 0; //counter which increments to match the number of location
  
  while(curr != nullptr) {

    //If the ctr equals the location, song ptr will point to the current
    //song being pointed at through curr
    if(ctr == location)
      song = curr;

    //curr pointer iterates by pointing to its m_next
    curr = curr -> GetNext();
    ctr++; //counter increments
  }

  return song;
}

//Basic getter to return the size of playlist
int Playlist::Size() {
  return m_size;
}

void Playlist::PlayAt(int location) {

  //Song pointers to iterate through the playlist
  //and keep track of the current and prevous song
  Song* curr = m_head;
  Song* prev = m_head;
  int ctr = 0; //counter which increments to match the number of location

  //If there's only one song in the playlist, the song will simply
  //be deleted size will be decremented
  if(m_size == 1) {
    
    delete curr; //deletes m_head or the only song
    curr = nullptr;
    m_size--; //size decremented
    return;
    
  }

  //Process that occurs if the first song from the playlist is selected to be deleted
  if(location == 0) {

    //m_head now becomes the next song in playlist
    m_head = m_head -> GetNext();
    delete curr; //first song is deleted
    m_size--; //size decremented
    return;

  }

  //If the last song from the playlist is selected to be deleted
  if(location == m_size) {

    //temporary pointer  used to point to the last song in the playlist
    Song* temp = m_tail;

    //curr will iterate through the playlist until it points to the song
    //before the last song in the playlist
    while(curr -> GetNext() != m_tail)
      curr = curr -> GetNext();

    //m_tail is now set equal to the previous song from the last
    m_tail = curr;
    delete temp; //deletes the last song
    curr -> SetNext(nullptr); //the new last song in the playlist m_next is set to null
    m_size--; //size decremented
    return;
    
  }

  //loop that goes through the playlist if the selected song to play is
  //is the middle of the playlist
  while(curr != nullptr) {

    if(ctr == location) {
          
      //previous song's m_next is set equal to
      //the current songs m_next
      prev -> SetNext(curr -> GetNext());
      delete curr; //current song selected is deleted
      m_size--; // size decremented
      return;
      
    }

    //previous equals the current and current moves on to the next song
    //if the location was not targeted yet
    prev = curr;
    curr = curr -> GetNext();
    ctr++; //counter incremented
  }
}

  

  
  
