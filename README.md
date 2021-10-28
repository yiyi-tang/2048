# COMP2113 Group Project - Group 72

## Group Members
Tang Yiyi 3035830636  
Zhou Yantong 3035770965


## 2048 
### Rules
[Part of the following information is cited from the Wikipedia Page: https://en.wikipedia.org/wiki/Hangman_(game)]  
2048 is played on a plain 4×4 grid, with numbered tiles that slide when a player moves them using the four arrow keys. Every turn, a new tile randomly appears in an empty spot on the board with a value of either 2 or 4. If two tiles of the same number collide while moving, they will merge into a tile with the total value of the two tiles that collided. 

The game is won when a tile with a value of 2048 appears on the board. However, when the player has no legal moves (there are no empty spaces and no adjacent tiles with the same value), the game ends.


### Features 
1. **Random tiles.** The game randomly generates 2 or 4 at a random empty grid every turn. (Related requirement: #1)
2. **Printed status.** After each move of the player, the program will output the new status of the 4\*4 tiles for reference. This is achieved by a 2D array storing the number at every tiles. (Related requirement: #2)
3. **The score board.** A scoreboard on the upper-right keeps track of the user's score. The user's score starts at zero, and is increased whenever two tiles combine, by the value of the new tile. In our game, an int variables is used to keep trace of the score of the players. (Related requirement: #2)
4. **Saving & Loading.** During the game, the players can pause and save the current status of  2048 tiles at any time. This will automatically create a save point, from which the players can choose to resume the next time they start the game. (Related requirement: #4)
5. (Dynamic memory management?)

All of the features mentioned above will be achieved by separate functions stored in independent source files. (Related requirement: #5)

