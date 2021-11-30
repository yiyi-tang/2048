#include <stdio.h>
 
int main ()
{
  
 //open the file and read our previous 4*4 array
   FILE *fp;
   int c;
 
   fp = fopen("memory.txt","r");
   while(1)
   {
      c = fgetc(fp);
      if( feof(fp) )
      {
          break ;
      }
     
      for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
          chessboard[i][j]=c;}
      }
        
       
   }
   fclose(fp);
   return(0);
}

