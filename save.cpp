#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void save(int chessboard[4][4])
{
 
    //open a txt file and save our two-dimentional array
    ofstream outfile;
	outfile.open("memory.txt", ios::in);

   for (int i = 0; i < 4; i++)
   {
      for (int j=0; j<4; j++) {
	outfile << chessboard[i][j] << "  ";}
        
    }

	outfile.close();//关闭文件，保存文件。
    return 0;
}

        






