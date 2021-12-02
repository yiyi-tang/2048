#include "node.h"
#include "equal.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

//Compare if the tiles after move are the same to the previous one.
bool equal(int tile[4][4], Node * head[4][4]){
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tile[i][j] != head[i][j]->info)
        return false;
    }
  }
  return true;
}
