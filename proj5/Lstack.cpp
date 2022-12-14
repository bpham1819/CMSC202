#ifndef LSTACK_CPP
#define LSTACK_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Templated node class used in templated linked list
template <class T>
class Node {
   public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data; //Templated data for node
  Node<T>* m_next; //Templated node pointer to next node
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = nullptr;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
   return m_data;
}

//Sets the data in a Node
template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Lstack {
 public:
  // Name: Lstack() (Linked List Stack) - Default Constructor
  // Desc: Used to build a new templated stack (as a linked list) m_head = top
  // Preconditions: None
  // Postconditions: Creates a new lstack where m_head points to nullptr and m_size = 0
  // Required
  Lstack();
  // Name: ~Lstack() - Destructor
  // Desc: Used to destruct a Lstack
  // Preconditions: There is an existing lstack with at least one node
  // Postconditions: An lstack is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks. (Allowed to use Clear in this function)
  // Required
 ~Lstack();
  // Name: Lstack (Copy Constructor)
  // Preconditions: Creates a copy of existing LStack
  //                Requires an existing Lstack
  // Hint: Make sure that the copy is not inverted
  // Postconditions: Copy of existing Lstack
  // Required
  Lstack(const Lstack&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Requires two Lstacks holding the same type of data
  //                After running, both stacks are identical with no memory loss
  //                Requires an existing Lstack
  // Postconditions: Two identical Lstack
  // Hint: Make sure that the destination Lstack has the same data in the same order as source
  // Required
  Lstack<T>& operator= (Lstack&);
  // Name: Push
  // Preconditions: Takes in data. Creates new node. 
  //                Requires an existing Lstack
  // Postconditions: Adds a new node to the top of the lstack.
  // Required
  void Push(const T&);
  // Name: Pop
  // Preconditions: Requires an existing Lstack with at least one node 
  // Postconditions: Removes top node in the lstack.
  // Assume that the Lstack has at least one node (Will check prior to call)
  // Required
  void Pop();
  // Name: Display
  // Preconditions: Outputs the lstack.
  // Postconditions: Displays the data in each node of lstack
  // Required (used only for testing lstack_test)
  void Display();
  // Name: Top
  // Preconditions: Requires an existing Lstack
  // Postconditions: Returns whatever data is on top
  // Required
  T Top();
  // Name: IsEmpty
  // Preconditions: Requires an existing Lstack
  // Postconditions: Returns true if the Lstack is empty else false.
  // Required
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires an existing Lstack
  // Postconditions: Returns m_size
  // Required
  int GetSize();
  // Name: Find()
  // Preconditions:  Requires an existing Lstack
  // Postconditions: Iterates and if it finds the thing, returns index, else -1
  // Required
  int Find(T&);
  // Name: Clear
  // Preconditions:  Requires an existing Lstack
  // Postconditions: Removes all nodes in Lstack
  // Required
  void Clear();
  // Name: At(int)
  // Preconditions:  Requires an existing Lstack
  // Postconditions: Returns the data at a specific index;
  //                 Index will be checked prior to call (assume int is valid)
  // Required
  T At (int x);
private:
  Node <T> *m_head; //Node pointer for the head
  int m_size; //Number of nodes in stack
};

//**********Implement Lstack Class Here***********
//**********All Functions Are Required Even If Not Used for Processor**************

template <class T>
Lstack<T>::Lstack() {

  m_head = nullptr;  //Sets m_head to null
  m_size = 0; //Sets size to 0

}

template <class T>
Lstack<T>::~Lstack() {

  //destructs every node by popping them off the stack
  //until the stack is empty
  while(m_size > 0)
    Pop();
   
}

template <class T>
Lstack<T>::Lstack(const Lstack& source) {

  //If there is only one node in the stack to copy, process inside
  // will execute
  if(source.m_size == 1) {
    
    //Creates a deep copy by passing the dereferenced value of
    //m_head and m_size
    m_head = new Node(*source.m_head);
    m_size = source.m_size;

  } else {

    //sets new copy m_head equal to to the m_head from the Lstack
    //that was passed in
    m_head = new Node(*source.m_head);
    m_size = source.m_size;

    //temp node used to iterate through the passed in Lstack
    Node<T> *curr = source.m_head -> GetNext();
    //temp node used to iterate through the current Lstack
    Node<T> *currCopy = m_head;

    //iterates through the stack
    while(curr != nullptr) {

      //Node<T> temp = new Node(curr -> GetData());
      //currCopy -> SetNext
      //copies the data from the passed in Lstack into the new Lstack
      currCopy -> SetNext(new Node(curr -> GetData()));

      //moves on to the next node to copy
      curr = curr -> GetNext();
      currCopy = currCopy -> GetNext();

    }

  }
  
}

template <class T>
Lstack<T>& Lstack<T>::operator= (Lstack<T>& other) {

  if(this != &other) {

    while(m_size > 0) {

      //if the stack only contains 1 node, m_head will be deleted
      //and the size will be decremented
      if(m_size == 1) {

	delete m_head;
	m_size--;

      } else { //If there is more than one node within the stack

	Node <T> *temp = m_head;
	
	//sets m_head to the node after it
	m_head = m_head -> GetNext();

	//deletes the temporary node
	delete temp;
	//m_size--; Decrement the size
	m_size--;

      }

    }

    if(other.m_size == 1) {

      //Creates a deep copy by passing the dereferenced value of
      //m_head and m_size
      m_head = new Node(*other.m_head);
      m_size = other.m_size;

    } else {

      //sets new copy m_head equal to to the m_head from the Lstack
      //that was passed in
      m_head = new Node(*other.m_head);
      m_size = other.m_size;

      //temp node used to iterate through the passed in Lstack
      Node<T> *curr = other.m_head -> GetNext();
      //temp node used to iterate through the current Lstack
      Node<T> *currCopy = m_head;

      //iterates through the stack
      while(curr != nullptr) {

	//Node<T> temp = new Node(curr -> GetData());
	//currCopy -> SetNext
	//copies the data from the passed in Lstack into the new Lstack
	currCopy -> SetNext(new Node(curr -> GetData()));

	//moves on to the next node to copy
	curr = curr -> GetNext();
	currCopy = currCopy -> GetNext();

      }
      
    }
    
  }

  return *this;
}

template <class T>
void Lstack<T>::Push(const T& data) {

  Node<T> *newNode = new Node(data);
  //If there's nothing in the stack, m_head will be set
  //equal to the newNode pushed in, and size will increment
  if(m_size == 0) {

    m_head = newNode;
    m_size++;
    
  //If there are already nodes within the stack, newNode will
  //become the new m_head and size will increment
  } else {

    newNode -> SetNext(m_head);
    m_head = newNode;
    m_size++;

  }
  
}

template <class T>
void Lstack<T>::Pop() {

  //If there's only one node (m_head), then m_head will be
  //deleted and set equal to nullptr for security
  if(m_size == 1) {

    delete m_head;
    m_head = nullptr;
    m_size--; //size decremented
    
  //If there is more than one node within the stack, the node at
  //the top of the stack will be popped
  } else {

    //used to store the node to delete; the top node
    Node<T> *temp = m_head;

    //m_head now points to the node after it
    m_head = m_head -> GetNext();

    delete temp; 
    temp = nullptr;
    m_size--; //size decremented

  }

}

template <class T>
void Lstack<T>::Display() {

  //If there's no nodes in the Lstack, statement will print
  if(m_size == 0) {
    cout <<  "Nothing to Display." << endl;
  } else {
    
    //starting node to iterate through the Lstack
    Node<T> *curr = m_head;

    //while curr has not passed the bottom node in the Lstack,
    //process will occur
    while(curr != nullptr) {

      //prints the data of the current node
      cout << curr -> GetData() << endl;
      //Current node will lastly iterate to the next node
      curr = curr -> GetNext();
   
    }
    
  }
  
}

template <class T>
T Lstack<T>::Top() {
  return m_head -> GetData();
}

template <class T>
bool Lstack<T>::IsEmpty() {

  //if the size is 0, will return true
  if(m_size == 0)
    return true;

  //if size is greater than 0
  return false;
}

template <class T>
int Lstack<T>::GetSize() {
  return m_size;
}

template <class T>
int Lstack<T>::Find(T& data) {

  //used as a counter to find the data in the Lstack
  int index = 0;

  //The current node that will iterate through the Lstack
  Node<T> *curr = m_head;

  //Loop will continue until current node reaches null
  while(curr != nullptr) {

    //if the data of current node matches the data passed in,
    // the index will be returned
    if(curr -> GetData() == data) {
      return index;

    //if data has not been found, current node will iterate
    //and index will be incremented
    } else {

      curr = curr -> GetNext();
      index++;

    }

  }

  //returns -1 if data was never matched
  return -1;
}

template <class T>
void Lstack<T>::Clear() {

  //while there is still nodes in the Lstack, function
  //will continue to pop the top node off the stack until size reaches 0
  while(m_size > 0)
    Pop();
  
}

template <class T>
T Lstack<T>::At(int x) {

  int index = 0; //used as a counter for iteration
  Node<T> *curr = m_head; //our current node to iterate through Lstack
  T data; //used to store the data to return
  
  while(curr != nullptr) {

    //if index counter matches passed in index, then
    //the NodeAtX will be set equal to the data of the current node
    if(index == x)
      data = curr -> GetData();
      
    //current node will iterate to the next node in the stack
    curr = curr -> GetNext();
    index++; //counter is incremented

  }

  //returns the data at the passed in index
  return data;
  
}


#endif
