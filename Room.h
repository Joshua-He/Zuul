#include <iostream>
#include "Items.h"

class Room{
 public:
  Room(char* roomName, char* roomDescription, char* roomeast, char* roomwest, char* roomnorth, char* roomsouth);
  ~Room();
  char name[100];
  char description[100];
  char east[100];
  char west[100];
  char north[100];
  char south[100];
  Items itemList;
  void showRoom();
  void findExit(char* newRoom);
};

