/*
Data Structure for storing infomation in the 16 tiles: a 4*4 int array.
Main functions to implemented:
1. void printTiles(int tiles[4][4], int score); //Print the interface of the game.
2. void random(int tiles[4][4]); //Generate one random tile of 2 or 4 in the blank space.
3. bool slide(int tiles[4][4], int &score); //Read user's input of direction, slide the tiles, and update the score. Supported by:
  (i)   void move(int tiles[4][4], char direction); //Move the tiles according to the direction.
  (ii)  int merge(int tiles[4][4], char direction); //Merge two or more tiles according to the direction, if possible.
4. bool fail(int tiles[4][4]); //Check if the game should end (when there's no legal moves)
5. void loadGame(int tiles[4][4], int &score) and void saveGame(int tiles[4][4], int &score);
//For loading and saving game status.
*/

//main.cpp
#include <iostream>
#include <fstream> //!!!!!!!!!
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
//#include ".h"
using namespace std;


//slide.cpp

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
  }
  return;
}

bool slide(int tiles[4][4], int &score){
  char input;
  cin >> input;
  if (input != 'w' && input != 'W' && input != 'a' && input != 'A' && input != 's' && input != 'S' && input != 'd' && input != 'D'){
    return false;
  }
  move(tiles, input);
  score += merge(tiles, input);
  move(tiles, input);
  return true;
}

bool fail(int chessboard[4][4])
{
	//if the chessboard is not full
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (chessboard[i][j] == 0)
				return false;
		}
	}

	//if there is still something we can combine
	//lines
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){
			if (chessboard[i][j] == chessboard[i][j+1])
				return false;
		}
	}


	//columns
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){
			if (chessboard[j][i] == chessboard[j+1][i])
				return false;
		}
	}

	return true;
}

//print updated chessboard
void printTiles(int chessboard[4][4], int score){
	cout << "---------------------" << endl;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (chessboard[i][j] == 0)
				cout << "|" << setw(4) << ' ';//Print a blank space
			else
				cout << "|" << setw(4) << chessboard[i][j];
		}
		cout << "|" << endl;
    cout << "---------------------" << endl;
	}

	cout << "Current Score: " << score << endl;
}


void random(int chessboard[4][4])
{
  //for random position
	srand(time(NULL));
	int x = rand() % 4;
	int y = rand() % 4;

	while (chessboard[x][y] != 0){
		x = rand() % 4;
		y = rand() % 4;
	}

	chessboard[x][y] = 2 * (rand() % 2 + 1);
}

int main(){
  int exit = 0;
  int tiles[4][4] = {0};
  int score = 0;
  string intro = "Please select an option to continue:\n1: How to play?\n2: Start a new game.\n3: Load saved game.\n4: exit.\n"; //!!!!!
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
      //loadGame(tiles, &score);
      break;
    }
    else if (choice == '4')
      exit = 1;
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
      if (slide(tiles, score)){
        printTiles(tiles, score);
        random(tiles);
        printTiles(tiles, score);
        continue;
      }
      else{
        cout << "Game paused. Do you want to exit the game? (Y/*)" << endl;
        char resume;
        cin >> resume;
        if (resume == 'Y' || resume == 'y'){
          char save;
          cout << "Do you want to save the game? (Y/*)" << endl;
          if (save == 'Y' || save == 'y'){
              cout << "Game Saved." << endl;
            //saveGame(tiles, score);
          }
          break;
        }
        else{
        cout << "Game resumes." << endl;
        printTiles(tiles, score);
        }
      }
    }
    char replay;
    cout << "Game ends. Play again? (Y/*)" << endl;
    cin >> replay;
    if (replay != 'Y' && replay != 'y')
      break;
  }
  cout << "Bye!" << endl;
}
