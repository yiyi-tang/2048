#include "slide.h"

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

//Read user input and slide the tiles.
void slide(int tiles[4][4], char direction){
  switch (direction){
    case 'w':
    case 'W':
    // Moving upward
      for (int i = 0; i < 4; i++) {
        int count = 0;
        for (int j = 0; j < 4; j++) {
          if (tiles[j][i] != 0) {
            tiles[count][i] = tiles[j][i];
            count++;
          }
        }
        for (int j = count; j < 4; j++) {
          tiles[j][i] = 0;
        }
      }
      break;

    case 'a':
    case 'A':
    // Moving leftward
      for (int j = 0; j < 4; j++) {
        int count = 0;
        for (int i = 0; i < 4; i++) {
          if (tiles[j][i] != 0) {
            tiles[j][count] = tiles[j][i];
            count++;
          }
        }
        for (int i = count; i < 4; i++) {
          tiles[j][i] = 0;
        }
      }
      break;

    case 's':
    case 'S':
    // Moving downward
      for (int i = 0; i < 4; i++) {
        int count = 3;
        for (int j = 3; j >= 0; j--) {
          if (tiles[j][i] != 0) {
            tiles[count][i] = tiles[j][i];
            count--;
          }
        }
        for (int j = count; j >= 0; j--) {
          tiles[j][i] = 0;
        }
      }
      break;

    case 'd':
    case 'D':
    // Moving rightward
      for (int j = 0; j < 4; j++) {
        int count = 3;
        for (int i = 3; i >= 0; i--) {
          if (tiles[j][i] != 0) {
            tiles[j][count] = tiles[j][i];
            count--;
          }
        }
        for (int i = count; i >= 0; i--) {
          tiles[j][i] = 0;
        }
      }
      break;
  }
  return;
}
