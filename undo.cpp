#include "undo.h"
#include "printTiles.h"
#include "node.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

//Take the 4*4 array, score and the nodes as the input.
//No output.
//Restore the situation of the tiles to a previous move.

void undo(Node * head[4][4], Node * & scores, int tiles[4][4], int &score){
  if (scores->next != NULL) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        tiles[i][j] = head[i][j]->next->info;
        Node * p = head[i][j];
        head[i][j] = head[i][j]->next;
        delete p;
      }
    }
    score = scores->next->info;
    Node * p = scores;
    scores = scores->next;
    delete p;
    printTiles(tiles, score);
  }
  else
    cout << "Undo is not available." << endl;
}
