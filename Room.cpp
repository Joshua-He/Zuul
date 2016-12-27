#include <iostream>
#include <string.h>
#include "Room.h"
//#include "Items.h"

using namespace std;

Room::Room(char* roomName, char* roomDescription, char* roomeast, char* roomwest, char* roomnorth, char* roomsouth){
  strcpy(east, roomeast);
  strcpy(west, roomwest);
  strcpy(north, roomnorth);
  strcpy(south, roomsouth);
  strcpy(name, roomName);
  strcpy(description, roomDescription);
  //  itemList = new Items(0, 0, 0, 0, 0);
  //constructor  
}
Room::~Room(){
  //deconstructor
}
void Room::showRoom(){
  //Shows which exits are available in a given room, as well as the room name and description
  cout << "The room you are in is: " << name << endl;
  cout << description << endl;
  cout << "There are exits: " << endl;
  if (north[0] != '\0'){
    cout << "NORTH, ";
  }
  if (south[0] != '\0'){
    cout << "SOUTH, ";
  }
  if (east[0] != '\0'){
    cout << "EAST, ";
  }
  if (west[0] != '\0'){
    cout << "WEST, ";
  }
  cout << endl;
  itemList.showItems();
}


void Room::findExit(char* newRoom){
  strcpy(newRoom, "");
  char direction[100];
  cout << endl << "Which exit do you want to go to?" << endl;
  cin >> direction;
  //Takes the users input and goes to a room depending on what direction they choose
  //If there is no exit then it says that exit is not available
  if (strcmp(direction, "EAST") == 0){
    if (east[0] != '\0'){
      strcpy( newRoom, east);
    }
    else{
      cout << "There is no east exit" << endl;
    }
  }
  if (strcmp(direction, "WEST") == 0){
    if (west[0] != '\0'){
      strcpy(newRoom, west);
    }
    else{
      cout << "There is no west exit" << endl;
    }
  }
  if (strcmp(direction, "NORTH") == 0){
    if (north[0] != '\0'){
      strcpy(newRoom, north);
    }
    else {
      cout << "There is no north exit" << endl;
    }
  }
  if (strcmp(direction, "SOUTH") == 0){
    if (south[0] != '\0'){
      strcpy(newRoom, south);
    }
    else {
      cout << "There is no south exit" << endl;
    }
  }
}

