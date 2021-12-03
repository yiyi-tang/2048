#include "fail.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;


//Check if the game should end (when there's no legal moves).
//Taking the two-dimentional array as input, if the chessboard is not full, return false


bool fail(int chessboard[4][4]){
	
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (chessboard[i][j] == 0)
				return false;
		}
	}

	//Taking the two-dimentional array as input, if there is still something we can combine in the direction of line,  return false
 
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){
			if (chessboard[i][j] == chessboard[i][j+1])
				return false;
		}
	}

	//Taking the two-dimentional array as input, if there is still something we can combine in the direction of column,  return false
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){
			if (chessboard[j][i] == chessboard[j+1][i])
				return false;
		}
	}
  cout << "GAME OVER!" << endl;
	return true;
}
