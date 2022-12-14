#include "Train.h"

// Constructor
// Gets the linked list ready to be used
Train::Train(){
  m_head = nullptr;
  m_size = 0;
}

// Destructor
// Removes all the train cars from the train
Train::~Train(){
  TrainCar* next = m_head->m_next;
  while(next != nullptr){ // iterates through the list until the end is found
    delete m_head; // delete the head 
    m_head = next; // iterate m_head
    next = next->m_next; // iterate the next ptr
  }
  delete m_head; // clean up the last node 
  m_head = nullptr; // always set hanging pointers to nullptr
}

// COMPLETE THIS FUNCTION
// insert a train car into the back of the train
void Train::InsertCar(string name) {

  TrainCar *temp = new TrainCar();
  
  temp -> m_name = name;
  temp -> m_next = nullptr;
  
  if(m_size == 0) {
    m_head = temp;
    m_tail = temp;
  } else {
    m_tail -> m_next = temp;
    temp -> m_next = nullptr;
    m_tail = temp;
  }
  
  m_size++;
}

// COMPLETE THIS FUNCTION
// remove the last train car
void Train::RemoveLast(){
  
  if(m_size == 0) {
    cout << "No nodes in linked list" << endl;
    return;
  } else if(m_size == 1) {
    delete m_head;
    m_head = nullptr;
    m_tail = nullptr;
    m_size--;
  } else {

    TrainCar *curr = m_head;
    while(curr -> m_next != m_tail) {
      curr = curr -> m_next;
    }

    delete curr -> m_next;
    m_tail = curr;
    m_tail -> m_next = nullptr;
    m_size--;
  }
}

// display()
// iterates through the train and says all their names
void Train::Display(){
  TrainCar* current = m_head;

  while(current != nullptr){ // iterate through the list
    cout << current->m_name << " -> ";
    current = current->m_next;
  }
  cout << "END" << endl << "Size: " << m_size << endl; 
} 
