#include <iostream>
#include <string.h>
#include <vector>
#include "Room.h"
// #include "Items.h"

using namespace std;

void setupAllRooms(vector<Room*> &roomList);

int main(){
  vector<Room*> roomList;
  int inWhile = 1;
  char currentRoom[100] = "1-20";
  char newRoom[100];
  Room* r;
  char direction[100];
  // set up the 15 rooms 
  setupAllRooms(roomList);

  while (inWhile == 1){
    for (int i =0; i<15; i++){
      if (strcmp(currentRoom, roomList[i]->name) == 0){
	  r = roomList[i];
	}
	
    }
      r->showRoom();
      r->findExit(newRoom);
      strcpy(currentRoom, newRoom);
      
  }
}

//-------------------------------------
// This function sets up all rooms and items
//-------------------------------------
void setupAllRooms(vector<Room*> &roomList) {
  Room* r;
  r = new Room((char*)"1-20", (char*)"This is the cool room.", (char*)"", (char*)"", (char*)"Transit Room", (char*)"Dead End");
  r->itemList.initItems(0, 0, 0, 0, 1);
  roomList.push_back(r);
  r = new Room((char*)"Dead End", (char*)"Turn back now.", (char*)"", (char*)"", (char*)"1-20", (char*)"");
  r->itemList.initItems(0, 0, 0, 1, 0);
  roomList.push_back(r);
  r = new Room((char*)"Transit Room", (char*)"A room with many paths to take", (char*)"Room 980 Ti", (char*)"Room 1080 Ti", (char*)"Room Vega", (char*)"1-20");
  roomList.push_back(r);
  r = new Room((char*)"Room Vega", (char*)"A room with the unreleased RX 490.", (char*)"", (char*)"", (char*)"Rose Room", (char*)"Transit Room");
  r->itemList.initItems(0, 0, 1, 0, 0);
  roomList.push_back(r);
  r = new Room((char*)"Rose Room", (char*)"The background is a rose color; in the center there is a bouquet of roses", (char*)"Scarlet Room", (char*)"Crimson Room", (char*)"Bank", (char*)"Room Vega");
  roomList.push_back(r);
  r = new Room((char*)"Crimson Room", (char*)"It is a crimson colored room", (char*)"Rose Room", (char*)"", (char*)"", (char*)"");
  roomList.push_back(r);
  r = new Room((char*)"Scarlet Room", (char*)"It is a scarlet colored room", (char*)"", (char*)"Rose Room", (char*)"", (char*)"");
  r->itemList.initItems(0, 1, 0, 0, 0);
  roomList.push_back(r);
  r = new Room((char*)"Bank", (char*)"It's a bank with money. (Hint: Take the money to the store)", (char*)"", (char*)"", (char*)"", (char*)"Rose Room");
  r->itemList.initItems(1, 0, 0, 0, 0);
  roomList.push_back(r);
  r = new Room((char*)"Room 980 Ti", (char*)"A room with 2 980 Tis", (char*)"", (char*)"Transit Room", (char*)"", (char*)"");
  roomList.push_back(r);
  r = new Room((char*)"Room 73b205", (char*)"The color reminds you of color #73b205", (char*)"", (char*)"Room 980 Ti", (char*)"", (char*)"Room 8ac91c");
  roomList.push_back(r);
  r = new Room((char*)"Room 8ac91c", (char*)"The color reminds you of color #8ac91c", (char*)"", (char*)"", (char*)"Room 73b205", (char*)"");
  roomList.push_back(r);
  r = new Room((char*)"Room 1080 Ti", (char*)"A room with a 1080 Ti. Or is it a faulty Titan XP?", (char*)"Transit Room", (char*)"", (char*)"", (char*)"");
  roomList.push_back(r);
  r = new Room((char*)"Room PSCH", (char*)"The room is painted a pistachio green color", (char*)"Room 1080 Ti", (char*)"Store", (char*)"", (char*)"Room CHRTS");
  roomList.push_back(r);
  r = new Room((char*)"Store", (char*)"A store where you can buy GPUs", (char*)"Room PSCH", (char*)"", (char*)"", (char*)"");
  roomList.push_back(r);
  r = new Room((char*)"Room CHRTS", (char*)"The room is painted a chartreuse color.", (char*)"", (char*)"", (char*)"Room PSCH", (char*)"");
  roomList.push_back(r);
  
}
