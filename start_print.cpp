#include <iostream>
#include <

//first initialize our chessboard
int num[row][column];
for (int i=0; i<4; ++i){
  for (int j=0; j<4; ++j) num[i][j]=0;}
  
  
//print updated chessboard
void print_chessboard(){
	for (int i = 0; i < 4; ++i)
	{
		cout << "---------------------------------"<< endl;
		for (int j = 0; j < 4; ++j)
		{
			if (game[i][j] == 0)
			{
				cout <<"|   \t";
			}
			else 
			{
				cout <<"|   " << game[i][j] << "\t";
			}
		}
		cout << "|" << endl;
	}
	cout << "---------------------------------"<< endl;

  }
  
  
  
  
  
}


int main(){
  
  return 0;
}
