#include <iostream>
using namespace std;

//first initialize our chessboard
int num[row][column];
for (int i=0; i<4; ++i){
  for (int j=0; j<4; ++j) num[i][j]=0;}
  
  
product_number();
product_number();

//print updated chessboard
void print_chessboard()
{
	cout << "=====================" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "|" << setw(4) << chessboard[i][j];
		}
		cout << "|" << endl;
	}

	cout << "=====================" << endl;
}


