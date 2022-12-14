/*
File: lab12.cpp
*/

#include "ArcaneEquipment.h"

int main() {
    //Default Constructor Called
    ArcaneEquipment arcane1;

    arcane1.Insert("Vanishing Journey Symbol"); //Adds Vanishing Journey Symbol to arcane1
    arcane1.Insert("Chu Chu Island Symbol");    //Adds Chu Chu Island Symbol to arcane1
    arcane1.Insert("Lachelein Symbol");         //Adds Lachelein Symbol to arcane1
    arcane1.Insert("Arcana Symbol");            //Adds Arcana Symbol to arcane1
    arcane1.Insert("Morass Symbol");            //Adds Morass Journey Symbol to arcane1
    arcane1.Insert("Esfara Symbol");            //Adds Esfara Journey Symbol to arcane1

    cout << "\nArcane Equipment List 1:\n"
         << arcane1 << endl;

    cout << "Arcane Equipment List 1 COPY (copy constructor) with 2 items deleted\n"
         << endl;
    ArcaneEquipment arcane1Copy(arcane1); //Calls the ArcaneEquipment copy constructor
    arcane1Copy.DeleteLast(); //Deletes item
    arcane1Copy.DeleteLast(); //Deletes item
    cout << arcane1Copy; //Calls overloaded << operator, outputs the m_items list

    //Test 1. arcane1 and arcane1Copy must have different memory addresses
    //        AND  # of items in m_items(Deep Copy)
    if ((&arcane1 != &arcane1Copy) && arcane1.GetNumItems() != arcane1Copy.GetNumItems()) {
      cout << "Copy constructor test PASSED" << endl;
    }else {
      cout << "Copy constructor test FAILED" << endl;
    }

    ArcaneEquipment arcane2; //Creates new container
    arcane2.Insert("Arcane Umbra Mage Gloves");   //Adds Arcane Umbra Mage Gloves to arcane2
    arcane2.Insert("Arcane Umbra Mage Shoulder"); //Adds Arcane Umbra Mage Shoulder to arcane2
    arcane2.Insert("Arcane Umbra Fan");           //Adds Arcane Umbra Fan to arcane2

    cout << "\nArcane Equipment List 2:\n"
         << arcane2 << endl;

    cout << "Arcane Equipment List 2 COPY (overloaded assignment operator) with 3 items inserted\n"
         << endl;

    ArcaneEquipment arcane2Copy;
    arcane2Copy = arcane2; //Calls the overloaded assignment operator on arcane2Copy, setting it to arcane2
    arcane2Copy.Insert("Arcane Umbra Knight Hat");
    arcane2Copy.Insert("Arcane Umbra Knight Shoes");
    arcane2Copy.Insert("Arcane Umbra Knight Cape");
    cout << arcane2Copy << endl;

    //Test 2. arcane2 and arcane2Copy must have different memory addresses and # of items (Deep Copy)
    if ((&arcane2 != &arcane2Copy) && arcane2.GetNumItems() != arcane2Copy.GetNumItems()) {
      cout << "Overloaded Assignment Operator test PASSED" << endl; 
    }else{
      cout << "Overloaded Assignment Operator test FAILED" << endl;
    }

    cout << "Do not forget to run this in Valgrind!" << endl;
}
