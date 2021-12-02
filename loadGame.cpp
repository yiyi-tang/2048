
#include <fstream>
#include <iostream>  
using namespace std;  


void loadGame(int chessboard[4][4], int &score){
	//open the file and read our previous 4*4 array
	ifstream OpenFile;
	OpenFIle.open("memory.txt");  
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
