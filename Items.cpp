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
  strcpy(item3name, "Laptop");
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


//Shows which items are in each room or which items the player has
void Items::showItems(char* location){
  
  cout << "The items in " << location << " are: ";
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
    cout << item5name;
  }
  cout << endl;
}

//pickup item function
void Items::pickupItem(Items &destination){
  char location[100];
  strcpy(location, "the room");
  
  int whileOn = 1;
  while (whileOn == 1){
  if (destination.item1 + destination.item2 + destination.item3 + destination.item4 + destination.item5 == 0){
    return;
  }
  cout << "Do you want to pickup an item? (Type \"PICKUP\" or \"NO\"): ";
  destination.showItems(location);
  char input[100];
  cin >> input;
  if (strcmp(input, "PICKUP") == 0){
    cout << "What item do you want to pickup? (Type the word with only the first letter capitalized" << endl;
    char input2[100];
    cin >> input2;
    //If the player inputs the item name and the item is in the room, the player takes the item from the room
     if (strcmp(input2, "Money") == 0 && destination.item1 > 0){
      item1 = 1;
      destination.item1 = 0;
    }
    if (strcmp(input2, "Book") == 0 && destination.item2 >0){
      item2 = 1;
      destination.item2 = 2;
    }
    if (strcmp(input2, "Laptop") == 0 && destination.item3 >0){
      item3 = 1;
      destination.item3 = 0;
    }
    if (strcmp(input2, "Pencil") == 0 && destination.item4 > 0){
      item4 = 1;
      destination.item4 = 0;
    }
    if(strcmp(input2, "Paper") == 0 && destination.item5 >0){
      item5 = 1;
      destination.item5 = 0;
    }
  }
  else if (strcmp(input, "NO") == 0){
    whileOn = 0;
  }
  }//end of while
}
  


//drop item function
void Items::dropItem(Items &destination){
  char location[100];
  strcpy(location, "your inventory");
  int whileOn = 1;
  while (whileOn == 1){
  if (item1 == 0 && item2 == 0 && item3 == 0 && item4 == 0 && item5 == 0){
    return;
  }
  char input[100];
  cout << "Do you want to drop an item? (Type \"DROP\" or \"NO\"): ";
  showItems(location);
  cin >> input;
  if (strcmp(input, "DROP") == 0){
    cout << "Which Item do you want to drop" << endl;
    char input2[100];
    cin >> input2;
    //If the player has the item, the item is taken out of the player's inventory and put into the room
    if (strcmp(input2, "Money") == 0 && item1 > 0){
      item1 = 0;
      destination.item1 = 1;
    }
    if (strcmp(input2, "Book") == 0 && item2 >0){
      item2 = 0;
      destination.item2 = 1;
    }
    if (strcmp(input2, "Laptop") == 0 && item3 >0){
      item3 = 0;
      destination.item3 = 1;
    }
    if (strcmp(input2, "Pencil") == 0 && item4 > 0){
      item4 = 0;
      destination.item4 = 1;
    }
    if(strcmp(input2, "Paper") == 0 && item5 >0){
      item5 = 0;
      destination.item5 = 1;
    }
    
  }
  else if (strcmp(input, "NO") == 0){
    whileOn = 0;
  }
  }//end while
}

#endif
