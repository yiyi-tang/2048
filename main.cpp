/*
Data Structure for storing infomation in the 16 tiles: a 4*4 int array.
Main functions to implemented:
1. void printTiles(int tiles[4][4], int score); //Print the interface of the game.
2. void random(int tiles[4][4]); //Generate one random tile of 2 or 4 in the blank space.
3. void store(Node * head[4][4], Node * & scores, int tiles[4][4], int score);
4. About the user's input at each move:
  (i)   void slide(int tiles[4][4], char direction); //Move the tiles according to the direction.
      - bool equal(int tile[4][4], Node * head[4][4]);
  (ii)  int merge(int tiles[4][4], char direction); //Merge two or more tiles according to the direction, if possible.
  (iii)	void undo(Node * head[4][4], Node * & scores, int tiles[4][4], int &score);
5. bool fail(int tiles[4][4]); //Check if the game should end (when there's no legal moves)
6.
  (i)   void loadGame(int tiles[4][4], int &score);
  (ii)  void saveGame(int tiles[4][4], int score);//For loading and saving game status.
7. void deleteList(Node * & head)；
*/

//main.cpp
#include "node.h"
#include "printTiles.h"
#include "random.h"
#include "store.h"
#include "slide.h"
#include "equal.h"
#include "merge.h"
#include "undo.h"
#include "fail.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

bool fileError = false;

//Load the saved game status from the file.
void loadGame(int chessboard[4][4], int &score){
	//open the file and read our previous 4*4 array
	ifstream OpenFile;
	OpenFile.open("memory.txt");
	if (OpenFile.fail()){
		cout<<"Error in file opening! PLease start a new game. "<<endl;
		fileError = true;
		return;
	}
  fileError = false;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			OpenFile >> chessboard[i][j];
		}
	}
  OpenFile >> score;
	OpenFile.close();
	cout << "Game retrived from previous record." << endl;
	return;
}

bool win(int tiles[4][4]){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (tiles[i][j] >= 2048) {
				return true;
			}
		}
	}
	return false;
}


//Save the game status to a file.
void saveGame(int chessboard[4][4], int score){
	//open a txt file and save our two-dimentional array
	ofstream outfile;
	outfile.open("memory.txt");
  if ( outfile.fail() ){
    cout << "Error in file opening!"<< endl;
    return;
  }
  fileError = false;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			outfile << chessboard[i][j] << "\n";
		}
	}
	outfile << score << "\n";
	outfile.close();
  cout << "Game Saved." << endl;
	return;
}

//Release the memory for storing each moves when a game ends.
void deleteList(Node * & head){
  while (head != NULL) {
    Node * temp = head;
    head = head->next;
    delete temp;
  }
}

int main(){
  bool exit = 0;
  int tiles[4][4] = {0};
  int score = 0;
	int firstWin = 0;
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
    else if (choice == '2'){
      random(tiles);
      random(tiles);
      break;
    }
    else if (choice == '3'){
      loadGame(tiles, score);
      if (fileError) {
        continue;
      }
      break;
    }
    else if (choice == '4'){
      exit = 1;
      break;
    }
    else{
      cout << "Invalid choice. Please input again." << endl;
    }
    cout << intro;
  }
  while (!exit){
    Node * head[4][4] = {NULL};
    Node * scores = NULL;
    printTiles(tiles, score);
    store(head, scores, tiles, score);
    while(!fail(tiles)){
      char input;
      cin >> input;
      if (input == 'U' || input == 'u') {
        undo(head, scores, tiles, score);
				if ((!win(tiles)) && firstWin == 1) {
					firstWin = 0;
				}
      }
      else if (input == 'w' || input == 'W' || input == 'a' || input == 'A' || input == 's' || input == 'S' || input == 'd' || input == 'D'){
        slide(tiles, input);
        score += merge(tiles, input);
        slide(tiles, input);
        if (scores != NULL && equal(tiles, head)) {
          cout << "Invalid direction to move. Please input again." << endl;
          continue;
        }
        random(tiles);
        store(head, scores, tiles, score);
        printTiles(tiles, score);
				if (win(tiles) && firstWin == 0) {
					firstWin = 1;
					cout << "You win! Continue to play? (Y/*)" << endl;
					char continuing;
					cin >> continuing;
					if (continuing != 'Y' && continuing != 'y') {
						break;
					}
				}
				printTiles(tiles, score);
        continue;
      }
      else{
        cout << "Game paused. Do you want to exit the game? (Y/*)" << endl;
        char quit;
        cin >> quit;
        if (quit == 'Y' || quit == 'y'){
          cout << "Do you want to save the game? (Y/*)" << endl;
          char save;
          cin >> save;
          if (save == 'Y' || save == 'y'){
            saveGame(tiles, score);
          }
          break;
        }
        else{
        cout << "Game resumes." << endl;
        printTiles(tiles, score);
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        deleteList(head[i][j]);
      }
    }
    deleteList(scores);
    char replay;
    cout << "Game ends. Play again? (Y/*)" << endl;
    cin >> replay;
    if (replay != 'Y' && replay != 'y')
      break;
    cout << "Start a new game? (Y/*)" << endl;
    char newplay;
    cin >> newplay;
    if (newplay == 'Y' || newplay == 'y'){
			for (int i = 0; i < 4; i++){
				for (int j = 0; j < 4; j++){
					tiles[i][j] = 0;
				}
			}
      score = 0;
			firstWin = 0;
      random(tiles);
      random(tiles);
    }
    else{
      loadGame(tiles, score);
			if (win(tiles)) {
				firstWin = 1;
			}
    }
  }
  cout << "Bye!" << endl;
}
