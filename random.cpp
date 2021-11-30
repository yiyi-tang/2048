void product_number(int consecutive_elimination)
{
  //for random position
	int x, y;
	srand((unsigned)time(NULL));
        
	while (chessboard[x][y] != 0)
	{
	
		x = rand() % Size;
		y = rand() % Size;
	};
	
	//for random 4 or 2此处有小问题，关于连消，是否生成3
	if (consecutive_elimination == 0 || consecutive_elimination == 1)
		chessboard[x][y] = 2;
	else
		chessboard[x][y] = 4;

}
