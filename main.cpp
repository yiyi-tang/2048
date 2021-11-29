/*
Data Structure for storing infomation in the 16 tiles: a 4*4 int array.
Main functions to implemented:
1. void printTiles(int tiles[][], int score); //Print the interface of the game.
2. void random(int tiles[][]); //Generate one random tile of 2 or 4 in the blank space.
3. void slide(int tiles[][], int &score); //Read user input and slide the tiles.
4. int merge(int tiles[][]); //Merge two or more tiles if possible and return the incresed score.
5. bool fail(int tiles[][]); //Check if the game should end (when there's no legal moves)
*/

//main.cpp
#include <iostream>
//#include ".h"
//#include ".o"
using namespace std;

int main(){
  int tiles[4][4];
  int score = 0;
  /*
  Some personalised functions here.
  Print the instructions as well.
  */
  random(tiles);
  random(tiles);
  printTiles(tiles, score);
  While(!fail(tiles)){
    slide(tiles, &score);
    printTiles(tiles, score);
    random(tiles);
    printTiles(tiles, score);
  }
//Saving the file and etc.
}
