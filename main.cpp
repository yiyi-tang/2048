/*
Data Structure for storing infomation in the 16 tiles: a 4*4 int array.
Main functions to implemented:
1. void printTiles(int tiles[4][4], int score); //Print the interface of the game.
2. void random(int tiles[4][4]); //Generate one random tile of 2 or 4 in the blank space.
3. void slide(int tiles[4][4], int &score); //Read user's input of direction, slide the tiles, and update the score. Supported by:
  (i)   void move(int tiles[4][4], char direction); //Move the tiles according to the direction.
  (ii)  int merge(int tiles[4][4], char direction); //Merge two or more tiles according to the direction, if possible.
4. bool fail(int tiles[4][4]); //Check if the game should end (when there's no legal moves)
5. void loadGame(int tiles[4][4], int &score) and void saveGame(int tiles[4][4], int &score);
//For loading and saving game status.
*/

//main.cpp
#include <iostream>
#include <ifstream>
#include <ofstream>
#include <string>
//#include ".h"
using namespace std;

int pause = 0;
int exit = 0;
int main(){
  int tiles[4][4];
  int score = 0;
  string intro = "Please select an option to continue:\n1: How to play?\n2: Start a new game.\n3: Load saved game.\n"
  cout << "Welcome to 2048!" << endl;
  cout << intro;
  char choice;
  while (cin >> choice){
    if (choice == '1'){
      ifstream fin;
      string line;
      fin.open("rules.txt");
      if ( fin.fail() ){
        cout << "Error in file opening!" << endl;
      }
      while ( getline(fin, line) ){
        cout << line << endl;
      }
    }
    else if (choice == '2')
      break;
    else if (choice == '3'){
      loadGame(tiles, &score);
      break;
    }
    else{
      cout << "Invalid choice. Please input again." << endl;
    }
    cout << intro;
  }
  while (!exit){
    random(tiles);
    random(tiles);
    printTiles(tiles, score);
    while(!fail(tiles)){
      slide(tiles, &score);
      printTiles(tiles, &score);
      random(tiles);
      printTiles(tiles, &score);
    }

    char answer;
    cout << "Do you want to exit the game? (Y/N)" << endl;
    cin >> answer;
    if (answer == 'Y')
      break;
    else{
      cout << "Game resumes." << endl;
      printTiles(tiles, score);
    }
  }
//Saving the file and etc.
}
