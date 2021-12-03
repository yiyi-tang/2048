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

void MoveLeft()
{
    for (int i = 0; i < 4; i++)  //一共有4行
    {
        for (int k = 0, j = 1; j < 4; j++)   //每一行都是有4列（个数字）
        {
            if (Bound[i][j] > 0)   //在一行中，只判k只有遇到的第一个非0的个数字  （j>0）
            {
                if(Bound[i][k] == Bound[i][j]) //情况一:k == j  &&  j >0
                {
                    Score +=  Bound[i][k++] *= 2;
                    Bound[i][j] = 0;
 
                    RandNum_nFalge = 1;
                }
                else if (Bound[i][k] == 0)     //情况二:k == 0  && j>0
                {
                    Bound[i][k] = Bound[i][j];
                    Bound[i][j] = 0;
                    RandNum_nFalge = 1;
                }
                else                           //情况三:k != j &&j >0
                {
                    Bound[i][++k] = Bound[i][j];
                    if (k != j)
                    {
                        Bound[i][j] = 0;
                        RandNum_nFalge = 1;
                    }
 
                }
 
            }
        }
    }
}
 
//右移动
void MoveRight()
{
    for (int i = 0; i < 4; i++)  //一共有4行
    {
        for (int k = 3, j = 2; j >= 0; j--)   //每一行都是有4列（个数字）
        {
            if (Bound[i][j] > 0)   //在一行中，只判k只有遇到的第一个非0的个数字  （j>0）
            {
                if (Bound[i][k] == Bound[i][j]) //情况一:k == j  &&  j >0
                {
                    Score += Bound[i][k--] *= 2;
                    Bound[i][j] = 0;
 
                    RandNum_nFalge = 1;
                }
                else if (Bound[i][k] == 0)     //情况二:k == 0  && j>0
                {
                    Bound[i][k] = Bound[i][j];
                    Bound[i][j] = 0;
                    RandNum_nFalge = 1;
                }
                else                           //情况三:k != j &&j >0
                {
                    Bound[i][--k] = Bound[i][j];
                    if (k != j)
                    {
                        Bound[i][j] = 0;
                        RandNum_nFalge = 1;
                    }
 
                }
 
            }
        }
    }
}
 
 
//上移动
void MoveUp()
{
    for (int i = 0; i < 4; i++)  //一共有4列
    {
        for (int k = 0, j = 1; j < 4; j++)   //每一列都是有4个数
        {
            if (Bound[j][i] > 0)   //这个里面j为时刻变化的 数组行， i为每一轮变化一次的数组的列（这里面注意体会s数组的i和j的循环和数组里面的区别）
            {
                if (Bound[j][i] == Bound[k][i]) //情况一:k == j  &&  j >0
                {
                    Score += Bound[k++][i] *= 2;
                    Bound[j][i] = 0;
                    RandNum_nFalge = 1;
                }
                else if (Bound[k][i] == 0)     //情况二:k == 0  && j>0
                {
                    Bound[k][i] = Bound[j][i];
                    Bound[j][i] = 0;
                    RandNum_nFalge = 1;
                }
                else                           //情况三:k != j &&j >0
                {
                    Bound[++k][i] = Bound[j][i];
                    if (k != j)
                    {
                        Bound[j][i] = 0;
                        RandNum_nFalge = 1;
                    }
 
                }
 
            }
        }
    }
}
 
 
//下移动
void MoveDown()
{
    for (int i = 0; i < 4; i++)  //一共有4列
    {
        for (int k = 3, j = 2; j >= 0; j--)   //每一列都是有4个数
        {
            if (Bound[j][i] > 0)   //这个里面j为时刻变化的 数组行， i为每一轮变化一次的数组的列（这里面注意体会s数组的i和j的循环和数组里面的区别）
            {
                if (Bound[j][i] == Bound[k][i]) //情况一:k == j  &&  j >0
                {
                    Score += Bound[k--][i] *= 2;
                    Bound[j][i] = 0;
                    RandNum_nFalge = 1;
                }
                else if (Bound[k][i] == 0)     //情况二:k == 0  && j>0
                {
                    Bound[k][i] = Bound[j][i];
                    Bound[j][i] = 0;
                    RandNum_nFalge = 1;
                }
                else                           //情况三:k != j &&j >0
                {
                    Bound[--k][i] = Bound[j][i];
                    if (k != j)
                    {
                        Bound[j][i] = 0;
                        RandNum_nFalge = 1;
                    }
 
                }
 
            }
        }
    }
}
 
