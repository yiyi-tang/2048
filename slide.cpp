//slide.cpp

#include <iostream>
#include <string>
//#include "slide.h"
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
            score += tiles[j][i]*2;
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
          score += tiles[j][i]*2;
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
            score += tiles[j][i]*2;
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
            score += tiles[j][i]*2;
            tiles[j][i-1] = 0;
          }
        }
      }
      break;
    default:
        cout << "Invalid input." << endl;
  }
  return score;
}

//Read user input and slide the tiles.
void move(int tiles[4][4], char direction){
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
    default:
        cout << "Invalid input." << endl;
  }
  return;
}


void slide(int tiles[4][4], int &score){
  char input;
  cin >> input;
  move(tiles, input);
  score += merge(tiles, input);
  move(tiles, input);
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
    cout << "Score: " << score << endl;
    slide(tiles, score);
  }
}
