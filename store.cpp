#include "node.h"
#include "store.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

////Take the 4*4 array, score and the nodes as the input.
//No output.
//Store the situation of the tiles of every move for undo purpose.
void store(Node * head[4][4], Node * & scores, int tiles[4][4], int score){
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      Node * temp = new Node;
      temp->info = tiles[i][j];
      temp->next = head[i][j];
      head[i][j] = temp;
    }
  }
  Node * temp = new Node;
  temp->info = score;
  temp->next = scores;
  scores = temp;
}
