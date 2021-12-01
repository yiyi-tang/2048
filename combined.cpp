/*
Data Structure for storing infomation in the 16 tiles: a 4*4 int array.
Main functions to implemented:
1. void printTiles(int tiles[4][4], int score); //Print the interface of the game.
2. void random(int tiles[4][4]); //Generate one random tile of 2 or 4 in the blank space.
3. void store(Node * head[4][4], Node * & scores, int tiles[4][4], int score)；
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
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

//For constructing the linked list to store the tiles on each move.
struct Node{
  int info;
  Node * next;
};
bool fileError = false;
//Print updated chessboard of a new turn.
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

//Generate one random tile of 2 or 4 in the blank space.
void random(int chessboard[4][4]){
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

//Compare if the tiles after move are the same to the previous one.
bool equal(int tile[4][4], Node * head[4][4]){
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tile[i][j] != head[i][j]->info)
        return false;
    }
  }
  return true;
}

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

//Check if the game should end (when there's no legal moves).
bool fail(int chessboard[4][4]){
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
  cout << "GAME OVER!" << endl;
	return true;
}

//Load the saved game status from the file.
void loadGame(int chessboard[4][4], int &score){
	//open a txt file and save our two-dimentional array
	ifstream infile;
	infile.open("memory.txt");
  if ( infile.fail() ){
    cout << "Error in file opening! Please select other options."<< endl;
    fileError = true;
    return;
  }
  fileError = false;
	for (int i = 0; i < 4; i++){
		for (int j=0; j<4; j++){
			infile >> chessboard[i][j];
		}
	}
	infile >> score;
	infile.close();
  cout << "Game retrived from previous record." << endl;
	return;
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
    cin >> replay;
    if (newplay == 'Y' || newplay == 'y'){
      int tiles[4][4] = {0};
      int score = 0;
      random(tiles);
      random(tiles);
    }
    else{
      loadGame(tiles, score);
    }
  }
  cout << "Bye!" << endl;
}
