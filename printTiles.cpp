#include "printTiles.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Print updated chessboard of a new turn.
void printTiles(int chessboard[4][4], int score){
	cout << "---------------------------------" << endl;
	for (int i = 0; i < 4; i++){
		cout << "|" << setw(7) << ' ' << "|" << setw(7) << ' ' << "|" << setw(7) << ' ' << "|" << setw(7) << ' ' << "|" << endl;
		for (int j = 0; j < 4; j++){
			if (chessboard[i][j] == 0)
				cout << "|" << setw(7) << ' '; //Print a blank space if the tiles has value 0
			else
				cout << "|" << setw(7) << chessboard[i][j];
		}
		cout << "|" << endl;
		cout << "|" << setw(7) << ' ' << "|" << setw(7) << ' ' << "|" << setw(7) << ' ' << "|" << setw(7) << ' ' << "|" << endl;
    cout << "---------------------------------" << endl;
	}
	cout << "Current Score: " << score << endl;
	cout << endl;
}
