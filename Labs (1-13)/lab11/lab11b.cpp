/*****************************************************************************
 ** File: lab11b.cpp
 ** Lab: CMSC 202 Lab 11b - Templates
 ** Author:  CMSC 202
 **
*****************************************************************************/
#include <iostream>
#include <string>
using namespace std;

/*
Implement the UserArray class that creates a dynamically allocated array
of the given size and performs the functions described in the lab document.
*/
/******Implement UserArray Class here******************/

template <class T>
class UserArray {
public:
  UserArray(int);
  ~UserArray();
  void SetArray(T[]);
  void DisplayAll();
  void AddToEach(T);
  T GetItem(int index);
private:
  int m_size;
  T* m_array;

};

template <class T>
UserArray<T>::UserArray(int size) {
  m_size = size;
  m_array = new T[size];
}

template <class T>
UserArray<T>::~UserArray() {
  delete [] m_array;
  m_array = nullptr;
}

template <class T>
void UserArray<T>::SetArray(T array[]) {
  for(int i = 0; i < m_size; i++)
    m_array[i] = array[i];
}

template <class T>
T UserArray<T>::GetItem(int index) {
  for(int i = 0; i < m_size; i++) {
    if(m_array[i] == index) {
       return m_array[i];
    }
  }

  return 0;
}

template <class T>
void UserArray<T>::DisplayAll() {
  for(int i = 0; i < m_size; i++)
    if(i + 1 == m_size)
      cout << m_array[i];
    else 
      cout << m_array[i] << ", ";
  cout << "\n";
}

template <class T>
void UserArray<T>::AddToEach(T var) {
  for(int i = 0; i < m_size; i++)
    m_array[i] += var;
}

//int main provided
int main() {

  //Integer array for lab grades
  UserArray<int> labGrades(10);
  int myGrades[10] = { 6,10,10,7,8,10,10,8,9,10 };
  labGrades.SetArray(myGrades);
  cout << "Lab Grades Array:" << endl;
  labGrades.DisplayAll();
  cout << endl;

  //Add one to each lab grade
  cout << "Lab Grades Array After Adding 1 to Each:" << endl;
  labGrades.AddToEach(1);
  labGrades.DisplayAll();
  cout << endl;
  
  //String array for courses
  UserArray<string> fallCourses(4);
  string courseList[4] = { "CMSC202", "CMSC203", "PHIL100", "MATH152" };
  fallCourses.SetArray(courseList);
  cout << "Fall Course List:" << endl;

  fallCourses.DisplayAll();
  cout << endl;
  
  //Add -FALL2021 to each course
  cout << "Fall Courses After Adding -FALL2021 to Each:" << endl;
  fallCourses.AddToEach("-FALL2021");
  fallCourses.DisplayAll();
  
  return 0;
}
