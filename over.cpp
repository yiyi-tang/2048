bool over()
{
	product_number();
	//if the chessboard is full
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{if (chessboard[i][j] == 0)
				return true;}
	}
	
	//if there is still something we can combine
	//1st line
	for (int i = 0, j = 0; j <3; j++){
		if (chessboard[i][j] == chessboard[i][j+1])
			return true;
	}
	
	
	//last line
	for (int i =3, j = 0; j < 3; j++){
		if (chessboard[i][j] == chessboard[i][j+1])
			return true;
	}
	
	
	//first column
	for (int i = 0, j = 0; j < 3; j++){
		if (chessboard[j][i] == chessboard[j+1][i])
			return true;
	}
	
	
	//last column
	for (int i =3, j = 0; j < 3; j++){
		if (chessboard[j][i] == chessboard[j+1][i])
			return true;
	}
	
	
	//the central elements
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 3; j++){
			if (chessboard[i][j] == chessboard[i][j + 1] || chessboard[i][j] == chessboard[i][j - 1] || chessboard[i][j] == chessboard[i + 1][j] || chessboard[i][j] == chessboard[i - 1][j])
				return true;}
	return false;
	}
}
//咱有成功判定了不
