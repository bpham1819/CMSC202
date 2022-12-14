#include <iostream>
#include <cstdlib>
#include "Track.h"

Track::Track() {

  //Calls on SetLength and sets m_length to the constant default length
  SetLength(DEFAULT_LENGTH);

  //Iterates through the m_track array and populates it with the 
  for(int i = 0; i < NUM_RACERS; i++)
    m_track[i] = 0;
  
}

void Track::SetLength(int length) {

  //Conditional checks if length parameter is within the allowable range
  //and sets length to the DEFAULT_LENGTH or MAX_LENGTH not within that range
  if(length < 1)
    m_length = DEFAULT_LENGTH;
  else if(length > MAX_LENGTH)
    m_length = MAX_LENGTH;
  else
    m_length = length;
  
}

void Track::PopulateObstacles() {

  //Iterates through the entire m_obstacle array and
  //populates it a randon number between 0-2  (rand() % 3)
  for(int pos = 0; pos < MAX_LENGTH; pos++)
    m_obstacle[pos] = rand() % 3;
  
}

void Track::GetStatus() {

  //Prints the line that describes the human player's position in the track
  //Calls on ConvertObstacle to print the OBSTACLE_TYPE as a string and GetObstacle
  //to print out what obstacle number  (out of the length) the player is on 
    cout << "You are on a " << ConvertObstacle(0)  << " obstacle (obstacle " << GetObstacle(m_track[0]) + 1 << " of " << m_length  << ")" << endl;

  //Loop which prints out the current position of the computer players like
  //above cout statement for the human player
  for(int racer = 1; racer < NUM_RACERS; racer++)
    cout << "Player " << racer << " is on a " << ConvertObstacle(racer) << " obstacle in (obstacle " << GetObstacle(m_track[racer]) + 1 << " of " << m_length  << ")" << endl;
  
}

int Track::CheckWin() {


  for(int pos = 0; pos < NUM_RACERS; pos++) {

    if(m_track[pos] == m_length)
      return pos;
    
  }
  
  return -1;
}

int Track::GetObstacle(int location) {
  return m_obstacle[location];
}

void Track::IncrementLocation(int player) {
  m_track[player] += 1;
}

void Track::ResetLocation() {
  
  for(int racer = 0; racer < NUM_RACERS; racer++) 
    m_track[racer] = 0;
  
}

string Track::ConvertObstacle(int player) {

  if(m_track[player] == 0)
    return OBSTACLE_TYPE[0];
  else if(m_track[player] == 1)
    return OBSTACLE_TYPE[1];

  return OBSTACLE_TYPE[2];
}

