//Title:  Lab 8 - Debugging
//Author: Danielle Dishop
//Course: CMSC 202
//Desc:   For this lab, you will use GDB to find where the errors occur.
//        You MUST use GDB to get credit for this lab

/* When corrected, this program should output:
The list is empty!
This list has 3 nodes.
15 -> 10 -> 5 -> END
This list has 1 nodes.
15 -> END
*/

#include <iostream>
using namespace std;

struct Node{
public:
  int m_info; //Data
  Node *m_next; //Node pointer
};

class LinkedList{
public:
  LinkedList(); //constructor
  ~LinkedList(); //destructor
  void InsertBegin(int data); //Insert function
  void RemoveEnd(); //Remove the last node
  void Display(); //Display function
private:
  Node *m_head; //Track front of linked list
  Node *m_tail; //Track back of linked list
  int m_size; //Track size of linked list
};

LinkedList::LinkedList(){ //Constructor for linked list
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

LinkedList::~LinkedList(){ //Destructor for linked list
  while (m_size > 0) { //While the list is not empty, Remove the last node
    RemoveEnd();
  }
}

void LinkedList::InsertBegin(int data){
  Node* newNode = new Node; //Create a pointer to the new node
  newNode -> m_info = data; //Set the data for the new node
  newNode -> m_next = m_head; //Set the new node to be 'before' the head node
  m_head = newNode; //Reset the head node to be the new node
  if (m_size == 0) { //If the list was empty,
    m_tail = newNode; //Set the tail node to be the new node
  }
  m_size++; //Increment the size
}

void LinkedList::RemoveEnd(){
  if (m_size == 0) { //If the list is empty
    return; //Do nothing and return
  }
  
  if (m_size == 1) { //If the list only has one node
    delete m_head;
    m_head = nullptr; //null the head node
    m_tail = nullptr; //null the tail node
    m_size--; //Decrement the size
    return;
  }
  
  Node* temp = m_head; //Create a temp node and set it to the head node
  while (temp -> m_next != m_tail) { //Iterate until temp is the next to last node
    temp = temp -> m_next;
  }
  delete m_tail; // Delete the last node
  temp -> m_next = nullptr; //Null temp's next
  m_tail = temp; //Reset the tail node
  m_size--; //Decrement the size
}

void LinkedList::Display(){
  if (m_size == 0) { //If the list is empty, say so
    cout << "The list is empty!" << endl;
  } else {
    cout << "This list has " << m_size << " nodes." << endl;
    Node* temp = m_head; //Create a temp node to move through the list
    while (temp != nullptr) { //For each node, output the data and a separating arrow
      cout << temp -> m_info << " -> ";
      temp = temp -> m_next;
    }
    cout << "END" << endl; //Output the end of the list
  }
}

int main() {
  LinkedList list; //Create a new linked list
  list.Display();
  
  // Insert several nodes into the linked list
  list.InsertBegin(5);
  list.InsertBegin(10);
  list.InsertBegin(15);
  list.Display();
  
  //Remove nodes from the list
  list.RemoveEnd();
  list.RemoveEnd();
  list.Display();
  
  return 0;
}
