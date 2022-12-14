/***************************************************************************** 
 ** File: lab11a.cpp                                                      
 ** Lab: CMSC 202 Lab 11a - Templates
 ** Author:  CMSC 202            
 **
*****************************************************************************/
#include <iostream>
#include <string>
using namespace std;

/*
Implement the functions setToHighest and displayAll so they are templated for 
any three variables of the same type. 

setToHighest will find the variable of the three that is highest and set all 
three variables to the one determined as highest. Note that for strings, 
comparison operators will still use the ASCII table. 

displayAll will take the three variables and display them as 
"Input1: [variable data] 
 Input2: [variable data] 
 Input3: [variable data]"
 */
//******Declare setToHighest here
template <class T>
void setToHighest(T&, T&, T&);

//displayAll provided for you
template <class T>
void displayAll(T&, T&, T&);

int main () {
  //string case
  string fruit1 = "Apple";
  string fruit2 = "Banana";
  string fruit3 = "Coconut";
  cout << "Set all three strings to highest of " << fruit2 << ", " << fruit1 << ", and " << fruit3 << endl;
  cout << "Before:" << endl;
  displayAll(fruit2, fruit1, fruit3);
  setToHighest(fruit2, fruit3, fruit1);
  cout << "After:" << endl;
  displayAll(fruit2, fruit3, fruit1);
  cout << endl;
  
  //integer case
  int num1 = 32;
  int num2 = 512;
  int num3 = 1024;
  cout << "Set all three ints to highest of " << num1 << ", " << num2 << ", and " << num3 << endl;
  cout << "Before:" << endl;
  displayAll(num1, num2, num3);
  setToHighest(num1, num2, num3);
  cout << "After:" << endl;
  displayAll(num1, num2, num3);
  cout << endl;
  
  //float case
  float float1 = 6.2;
  float float2 = 4.1;
  float float3 = 3.9;
  cout << "Set all three floats to highest of " << float1 << ", " << float2 << ", and " << float3 << endl;
  cout << "Before:" << endl;
  displayAll(float1, float2, float3);
  setToHighest(float1, float2, float3);
  cout << "After:" << endl;
  displayAll(float1, float2, float3);
  cout << endl;

  return 0;
}
/*
  Implement the functions setToHighest and displayAll so they are templated for
  any three variables of the same type.

  setToHighest will find the variable of the three that is highest and set all
  three variables to the one determined as highest. Note that for strings,
  comparison operators will still use the ASCII table.
//*****Implement setToHighest here*****
//Set all three arguments equal to the highest
//of the three.
*/
template <class T>
void setToHighest(T& input1, T& input2, T& input3) {

  T highest = input1;

  if(highest < input2)
    highest = input2;

  if(highest < input3)
    highest = input3;

  input1 = highest;
  input2 = highest;
  input3 = highest;
}



//Display all three arguments formatted as directed
//Provided to you
template <class T>
void displayAll(T& input1, T& input2, T& input3) {
  cout << "\tInput1: " << input1 << endl;
  cout << "\tInput2: " << input2 << endl;
  cout << "\tInput3: " << input3 << endl;
}
