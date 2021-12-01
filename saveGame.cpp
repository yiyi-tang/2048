#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void saveGame(int chessboard[4][4], int score){
	//open a txt file and save our two-dimentional array
	ofstream outfile;
	outfile.open("memory.txt");
	for (int i = 0; i < 4; i++){
		for (int j=0; j<4; j++){
			outfile << chessboard[i][j] << "\n";
		}
	}
	outfile << score << "\n";
	outfile.close();
	return;
}
