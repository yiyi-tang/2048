#include "merge.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

//Merge two or more tiles if possible and return the incresed score.
int merge(int tiles[4][4], char direction){
  int score = 0;
  switch (direction){
    case 'w':
    case 'W':
    // Merging upward
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
          if (tiles[j][i] == tiles[j+1][i]) {
            tiles[j][i] = tiles[j][i]*2;
            score += tiles[j][i];
            tiles[j+1][i] = 0;
          }
        }
      }
      break;

    case 'a':
    case 'A':
    // Merging leftward
    for (int j = 0; j < 4; j++) {
      for (int i = 0; i < 3; i++) {
        if (tiles[j][i] == tiles[j][i+1]) {
          tiles[j][i] = tiles[j][i]*2;
          score += tiles[j][i];
          tiles[j][i+1] = 0;
        }
      }
    }
      break;

    case 's':
    case 'S':
    // Merging downward
      for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
          if (tiles[j][i] == tiles[j-1][i]) {
            tiles[j][i] = tiles[j][i]*2;
            score += tiles[j][i];
            tiles[j-1][i] = 0;
          }
        }
      }
      break;

    case 'd':
    case 'D':
    // Merging rightward
      for (int j = 0; j < 4; j++) {
        for (int i = 3; i > 0; i--) {
          if (tiles[j][i] == tiles[j][i-1]) {
            tiles[j][i] = tiles[j][i]*2;
            score += tiles[j][i];
            tiles[j][i-1] = 0;
          }
        }
      }
      break;
  }
  return score;
}
#include "merge.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

//Merge two or more tiles if possible and return the incresed score.
int merge(int tiles[4][4], char direction){
  int score = 0;
  switch (direction){
    case 'w':
    case 'W':
    // Merging upward
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
          if (tiles[j][i] == tiles[j+1][i]) {
            tiles[j][i] = tiles[j][i]*2;
            score += tiles[j][i];
            tiles[j+1][i] = 0;
          }
        }
      }
      break;

    case 'a':
    case 'A':
    // Merging leftward
    for (int j = 0; j < 4; j++) {
      for (int i = 0; i < 3; i++) {
        if (tiles[j][i] == tiles[j][i+1]) {
          tiles[j][i] = tiles[j][i]*2;
          score += tiles[j][i];
          tiles[j][i+1] = 0;
        }
      }
    }
      break;

    case 's':
    case 'S':
    // Merging downward
      for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
          if (tiles[j][i] == tiles[j-1][i]) {
            tiles[j][i] = tiles[j][i]*2;
            score += tiles[j][i];
            tiles[j-1][i] = 0;
          }
        }
      }
      break;

    case 'd':
    case 'D':
    // Merging rightward
      for (int j = 0; j < 4; j++) {
        for (int i = 3; i > 0; i--) {
          if (tiles[j][i] == tiles[j][i-1]) {
            tiles[j][i] = tiles[j][i]*2;
            score += tiles[j][i];
            tiles[j][i-1] = 0;
          }
        }
      }
      break;
  }
  return score;
}
