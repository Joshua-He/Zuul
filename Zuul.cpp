#include <iostream>
#include <string.h>
#include <vector>
#include "Room.h"
// #include "Items.h"

using namespace std;

void setupAllRooms(vector<Room*> &roomList);

//This program lets the player go through the rooms (15 in total) while picking up and dropping items
//The winning condition is to take the "Money" item (from the bank) to the store.
int main(){
  vector<Room*> roomList;
  int inWhile = 1;
  char currentRoom[100] = "1-20";
  char newRoom[100];
  Room* r;
  char direction[100];
  Items playeritems;
  // set up the 15 rooms 
  setupAllRooms(roomList);
  cout << "Welcome to Zuul. The winning condition is to take the Money from the bank to the store. The losing condition is to take the money to the dead end. When moving between rooms, type \"NORTH\", \"SOUTH\", \"EAST\", or \"WEST\"." << endl;
  
  while (inWhile == 1){
    for (int i =0; i<15; i++){
      if (strcmp(currentRoom, roomList[i]->name) == 0){
	  r = roomList[i];
	}	
    }
    
    r->showRoom();
    playeritems.pickupItem(r->itemList);
    playeritems.dropItem(r->itemList);
    //Passes in value of inWhile by reference in order to quit, it will set inWhile to 0 if the user types quit
    r->findExit(newRoom, inWhile);
    strcpy(currentRoom, newRoom);
    //wINNING CONDITION
    if (playeritems.item1 == 1 && strcmp(currentRoom, "Store") == 0){
      cout << "You have won! Congratulations you have won! The game will quit now" << endl;
      inWhile = 0;
    }
    //Losing condition
    if (playeritems.item1 == 1 && strcmp(currentRoom, "Dead End") == 0){
      cout << "You lost! Sorry!" << endl;
      inWhile = 0;
    }

  }
}

//-------------------------------------
// This function sets up all rooms and items
//-------------------------------------
void setupAllRooms(vector<Room*> &roomList) {
  Room* r;
  r = new Room((char*)"1-20", (char*)"Description: This is the cool room.", (char*)"", (char*)"", (char*)"Transit Room", (char*)"Dead End");
  r->itemList.initItems(0, 0, 0, 0, 1);
  roomList.push_back(r);
  r = new Room((char*)"Dead End", (char*)"Description: Turn back now.", (char*)"", (char*)"", (char*)"1-20", (char*)"");
  r->itemList.initItems(0, 0, 0, 1, 0);
  roomList.push_back(r);
  r = new Room((char*)"Transit Room", (char*)"Description: A room with many paths to take", (char*)"Room 980 Ti", (char*)"Room 1080 Ti", (char*)"Room Vega", (char*)"1-20");
  roomList.push_back(r);
  r = new Room((char*)"Room Vega", (char*)"Description: A room with the unreleased RX 490.", (char*)"", (char*)"", (char*)"Rose Room", (char*)"Transit Room");
  r->itemList.initItems(0, 0, 1, 0, 0);
  roomList.push_back(r);
  r = new Room((char*)"Rose Room", (char*)"Description: The background is a rose color; in the center there is a bouquet of roses", (char*)"Scarlet Room", (char*)"Crimson Room", (char*)"Bank", (char*)"Room Vega");
  roomList.push_back(r);
  r = new Room((char*)"Crimson Room", (char*)"Description: It is a crimson colored room", (char*)"Rose Room", (char*)"", (char*)"", (char*)"");
  roomList.push_back(r);
  r = new Room((char*)"Scarlet Room", (char*)"Description: It is a scarlet colored room", (char*)"", (char*)"Rose Room", (char*)"", (char*)"");
  r->itemList.initItems(0, 1, 0, 0, 0);
  roomList.push_back(r);
  r = new Room((char*)"Bank", (char*)"Description: It's a bank with money. (Hint: Take the money to the store)", (char*)"", (char*)"", (char*)"", (char*)"Rose Room");
  r->itemList.initItems(1, 0, 0, 0, 0);
  roomList.push_back(r);
  r = new Room((char*)"Room 980 Ti", (char*)"Description: A room with 2 980 Tis", (char*)"", (char*)"Transit Room", (char*)"", (char*)"");
  roomList.push_back(r);
  r = new Room((char*)"Room 73b205", (char*)"Description: The color reminds you of color #73b205", (char*)"", (char*)"Room 980 Ti", (char*)"", (char*)"Room 8ac91c");
  roomList.push_back(r);
  r = new Room((char*)"Room 8ac91c", (char*)"Description: The color reminds you of color #8ac91c", (char*)"", (char*)"", (char*)"Room 73b205", (char*)"");
  roomList.push_back(r);
  r = new Room((char*)"Room 1080 Ti", (char*)"Description: A room with a 1080 Ti. Or is it a faulty Titan XP?", (char*)"Transit Room", (char*)"Room PSCH", (char*)"", (char*)"");
  roomList.push_back(r);
  r = new Room((char*)"Room PSCH", (char*)"Description: The room is painted a pistachio green color", (char*)"Room 1080 Ti", (char*)"Store", (char*)"", (char*)"Room CHRTS");
  roomList.push_back(r);
  r = new Room((char*)"Store", (char*)"Description: A store where you can buy GPUs", (char*)"Room PSCH", (char*)"", (char*)"", (char*)"");
  roomList.push_back(r);
  r = new Room((char*)"Room CHRTS", (char*)"Description: The room is painted a chartreuse color.", (char*)"", (char*)"", (char*)"Room PSCH", (char*)"");
  roomList.push_back(r);
  
}
