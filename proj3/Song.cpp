/*****************************************
 ** File:    Song.cpp
 ** Project: CMSC 202 Project 3, Fall 2022
 ** Author:  Brian Pham
 ** Date:    11/3/2022
 ** Section: 11:30/12:45
 ** E-mail:  bpham3@umbc.edu
 **
 ** This file contains the cpp file for Song.h
 ** This program is contains definitions needed to manipulate a
 ** song object or pointer so that it can exists within 
 ** a Playlist for the MusicPlayer.
 ***********************************************/

#include "Song.h"

Song::Song() {
  
  m_title = "New Title";
  m_artist = "New Artist";
  m_year = 0;
  m_rank = 0;
  m_next = nullptr;

}

Song::Song(string title, string artist, int year, int rank) {

  m_title = title;
  m_artist = artist;
  m_year = year;
  m_rank = rank;
  m_next = nullptr;

}

//Basic definitions for Getters/Setters
string Song::GetTitle() {
  return m_title;
}

string Song::GetArtist() {
  return m_artist;
}

int Song::GetYear() {
  return m_year;
}

int Song::GetRank() {
  return m_rank;
}

void Song::SetTitle(string title) {
  m_title = title;
}

void Song::SetArtist(string artist) {
  m_artist = artist;
}

void Song::SetYear(int year) {
  m_year = year;
}

void Song::SetRank(int rank) {
  m_rank = rank;
}

Song* Song::GetNext() {
  return m_next;
}

void Song::SetNext(Song* song) {
  m_next = song;
}
  
  

  
