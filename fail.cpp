bool fail(int chessboard[4][4])
{
	//if the chessboard is not full
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (chessboard[i][j] == 0)
				return false;
		}
	}
	
	//if there is still something we can combine
	//lines
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){
			if (chessboard[i][j] == chessboard[i][j+1])
				return false;
		}
	}
	
	
	//columns
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){
			if (chessboard[j][i] == chessboard[j+1][i])
				return false;
		}
	}
	
	return true;
}
