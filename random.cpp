#include "random.h"
#include <stdlib.h>
#include <time.h>

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
