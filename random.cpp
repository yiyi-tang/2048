void product_number()
{
  //for random position
	int x, y;
	srand((unsigned)time(NULL));
	do
	{
		x = rand() % Size;
		y = rand() % Size;
	} while (chessboard[x][y] != 0);
	
	//for random 4 or 2
	if (elimination_level == 0 || elimination_level == 1)
		chessboard[x][y] = 2;
	else
		chessboard[x][y] = 4;
