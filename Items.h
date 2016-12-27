#include <iostream>
#include <string.h>

class Items{
 public:
  Items();
  ~Items();
  void initItems(int i1, int i2, int i3, int i4, int i5);
  void showItems();
  int item1;
  int item2;
  int item3;
  int item4;
  int item5;
  char item1name[100];
  char item2name[100];
  char item3name[100];
  char item4name[100];
  char item5name[100];
};
