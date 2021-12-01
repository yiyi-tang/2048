
#include <fstream>
#include <iostream>  
using namespace std;  


void loadGame(int chessboard[4][4], int &score){
  //open the file and read our previous 4*4 array
    ifstream OpenFile("memory.txt");  
　　if (OpenFile.fail())   
     {  
       cout<<"No such a record. PLease start a new game. "<<endl;  
       exit(0);  
     }  
    
    for (int i=0; i<4; i++)
    {
      for (int j=0; j<4; j++)        
         OpenFile>>chessboard[i][j];  
    }
    OpenFile.close();  

 }

 
