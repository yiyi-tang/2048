#include<stdio.h>
#include <string>

void save(int chessboard[4][4])
{
    FILE *mem;
 
  //open a file to restore the information
    if((mem = fopen("memory.txt","w+")) == NULL){
        fprintf(stderr,"Can't open memory.txt!\n");
        exit(1);
    }

    //save our two-dimentional array
    for (int i=0; i<4; ++i) {
      for (int j=0; j<4; ++j) {
        fwrite(int,sizeof(int),1,mem);
  
   fclose(mem);
  
   return(0);

}

      
