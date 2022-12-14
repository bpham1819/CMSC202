/*****************************************
** File:    lab3.cpp
** Project: CMSC 202 Lab 3, Fall 2022
**
** Lab 3 involves using arrays. In this file you need to
** implement the flipArray() function as well as populate the array
** and keep track of the length of the array.
**
***********************************************/
#include <iostream>
using namespace std;

// Function Prototype for flipArray HERE********
void flipArray(int array[], int size); //Provided

//Implement global constants HERE********
const int SIZE = 100;

//Implement main HERE*********
int main() {
  

    // Declare your necessary variables.
  int inputValue;
  int myArray[SIZE] = {0};
  int currSize = 0;

    // Populate your array.
  
  cout << "Enter a number (0 when done): ";
  cin >> inputValue;

  while(inputValue > 0 && currSize < SIZE) {
    myArray[currSize] = inputValue;
    currSize++;

    cout << "Enter a number (0 when done): ";
    cin >> inputValue;
  }
  
    

    


    // Display the original array, call flipArray(), display modified array.

  
  cout << "Original Array: " << endl;
  for(int i = 0; i < currSize; i++) {
    cout << myArray[i] << " ";
  }
  
  cout << endl;

  cout << "Flipped Array: " << endl;

  flipArray(myArray, currSize);

  for(int i = 0; i < currSize; i++) {
    cout << myArray[i] << " ";
  }

  cout << endl;
  
  return 0;
}

// Implement flipArray() here
// Hint: only need to iterate through half of the array.
void flipArray(int array[], int size) {
  for(int i = 0; i < size / 2 ; i++) {
    int temp = array[i];
    array[i] = array[size - i - 1];
    array[size - i - 1] = temp;
  }    
}

