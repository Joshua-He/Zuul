#include <iostream>
#include "Items.h"
#include <string.h>
#ifndef ITEMS_H
#define ITEMS_H
using namespace std;

//Constructor, sets up item names and initializes to 0
Items::Items(){
  strcpy(item1name, "Money");
  strcpy(item2name, "Book");
  strcpy(item3name, "laptop");
  strcpy(item4name, "Pencil");
  strcpy(item5name, "Paper");
  item1 = 0;
  item2 = 0;
  item3 = 0;
  item4 = 0;
  item5 = 0;
}
//deconstructor
Items::~Items(){

}

//set up items
void Items::initItems(int i1, int i2, int i3, int i4, int i5)
{
  item1 = i1;
  item2 = i2;
  item3 = i3;
  item4 = i4;
  item5 = i5;
}
//Shows which items are in each room
void Items::showItems(){
  cout << "The items in this room are: ";
  if (item1 == 1){
    cout << item1name << ", ";
  }
  if (item2 == 1){
    cout << item2name << ", ";
  }
  if (item3 == 1){
    cout << item3name << ", ";
  }
  if (item4 == 1){
    cout << item4name << ", ";
  }
  if (item5 == 1){
    cout << item5name << endl;
  }
  cout << endl;
}

#endif
