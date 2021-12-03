int main(){
  bool exit = 0;
  int tiles[4][4] = {0};
  int score = 0;
	int firstWin = 0;
  string intro = "Please select an option to continue:\n1: How to play?\n2: Start a new game.\n3: Load saved game.\n4: exit.\n"; //!!!!!
  cout << "Welcome to 2048!" << endl;
  cout << intro;
  char choice;
  while (cin >> choice){
    if (choice == '1'){
      ifstream fin;
      string line;
      fin.open("rules.txt");
      if ( fin.fail() ){
        cout << "Error in file opening!" << endl;
      }
      while ( getline(fin, line) ){
        cout << line << endl;
      }
    }
    else if (choice == '2'){
      random(tiles);
      random(tiles);
      break;
    }
    else if (choice == '3'){
      loadGame(tiles, score);
			if (win(tiles)) {
				firstWin = 1;
			}
      if (fileError) {
        continue;
      }
      break;
    }
    else if (choice == '4'){
      exit = 1;
      break;
    }
    else{
      cout << "Invalid choice. Please input again." << endl;
    }
    cout << intro;
  }
  while (!exit){
    Node * head[4][4] = {NULL};
    Node * scores = NULL;
    printTiles(tiles, score);
    store(head, scores, tiles, score);
    while(!fail(tiles)){
      char input;
      cin >> input;
      if (input == 'U' || input == 'u') {
        undo(head, scores, tiles, score);
				if ((!win(tiles)) && firstWin == 1) {
					firstWin = 0;
				}
      }
      else if (input == 'w' || input == 'W' || input == 'a' || input == 'A' || input == 's' || input == 'S' || input == 'd' || input == 'D'){
        slide(tiles, input);
        score += merge(tiles, input);
        slide(tiles, input);
        if (scores != NULL && equal(tiles, head)) {
          cout << "Invalid direction to move. Please input again." << endl;
          continue;
        }
        random(tiles);
        store(head, scores, tiles, score);
        printTiles(tiles, score);
				if (win(tiles) && firstWin == 0) {
					firstWin = 1;
					cout << "You win! Continue to play? (Y/*)" << endl;
					char continuing;
					cin >> continuing;
					if (continuing != 'Y' && continuing != 'y') {
						break;
					}
					else
						printTiles(tiles, score);
				}
        continue;
      }
      else{
        cout << "Game paused. Do you want to exit the game? (Y/*)" << endl;
        char quit;
        cin >> quit;
        if (quit == 'Y' || quit == 'y'){
          cout << "Do you want to save the game? (Y/*)" << endl;
          char save;
          cin >> save;
          if (save == 'Y' || save == 'y'){
            saveGame(tiles, score);
          }
          break;
        }
        else{
        cout << "Game resumes." << endl;
        printTiles(tiles, score);
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        deleteList(head[i][j]);
      }
    }
    deleteList(scores);
    char replay;
    cout << "Game ends. Play again? (Y/*)" << endl;
    cin >> replay;
    if (replay != 'Y' && replay != 'y')
      break;
    cout << "Start a new game? (Y/*)" << endl;

    char newplay;
    cin >> newplay;
    if (newplay == 'Y' || newplay == 'y'){
			for (int i = 0; i < 4; i++){
				for (int j = 0; j < 4; j++){
					tiles[i][j] = 0;
				}
			}
      score = 0;
			firstWin = 0;
      random(tiles);
      random(tiles);
    }
    else{
      loadGame(tiles, score);
			if (win(tiles)) {
				firstWin = 1;
			}
    }
  }
  cout << "Bye!" << endl;
}
