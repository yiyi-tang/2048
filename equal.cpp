#include "node.h"
#include "equal.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

//Compare if the tiles after move are the same to the previous one.
//we pass the previous 2 dimentional array and the current nodes as inputs.
//if the number corresponding to any same position of the 4*4 array is different, there should be a change, hence retunring false.
//if the number corresponding to every position of the 4*4 array is the same, there should be no changes, hence retunring true.
bool equal(int tile[4][4], Node * head[4][4]){
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tile[i][j] != head[i][j]->info)
        return false;
    }
  }
  return true;
}
