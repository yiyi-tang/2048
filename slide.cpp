//slide.cpp

#include <iostream>
#include <string>
//#include "slide.h"
using namespace std;

//Merge two or more tiles if possible and return the incresed score.

int merge(int tiles[4][4]){
  return 0;
}

//Read user input and slide the tiles.
void slide(int tiles[4][4], int &score){
  char input;
  cin >> input;
  switch (input){
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
      for (int i = 0; i < 4; i++) {
        int count = 0;
        for (int j = 0; j < 4; j++) {
          if (tiles[i][j] != 0) {
            tiles[i][count] = tiles[i][j];
            count++;
          }
        }
        for (int j = count; j < 4; j++) {
          tiles[i][j] = 0;
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
      for (int i = 0; i < 4; i++) {
        int count = 3;
        for (int j = 3; j >= 0; j--) {
          if (tiles[i][j] != 0) {
            tiles[i][count] = tiles[i][j];
            count--;
          }
        }
        for (int j = count; j >= 0; j--) {
          tiles[i][j] = 0;
        }
      }
      break;
    default:
        cout << "Invalid input." << endl;
  }
  return;
}


int main(){
  int tiles[4][4] = {
    1,0,0,0,2,2,0,0,4,4,4,4,0,0,0,0
  };
  int score = 0;
  while(true){
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (tiles[i][j] == 0) {
          cout << ' ' << "\t";
        }
        else
          cout << tiles[i][j] << "\t";
      }
      cout << endl;
    }
    slide(tiles, score);
  }
}
