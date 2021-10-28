# COMP2113 Group Project - Group 72

## Group Members
Tang Yiyi 3035830636  
Zhou Yantong 3035770965


## 2048 
### Descriptions and rules
[Part of the following information is cited from the Wikipedia Page: https://en.wikipedia.org/wiki/Hangman_(game)]  
2048 is played on a plain 4×4 grid, with numbered tiles that slide when a player moves them using the four arrow keys. Every turn, a new tile randomly appears in an empty spot on the board with a value of either 2 or 4.Tiles slide as far as possible in the chosen direction until they are stopped by either another tile or the edge of the grid. If two tiles of the same number collide while moving, they will merge into a tile with the total value of the two tiles that collided. The resulting tile cannot merge with another tile again in the same move. Higher-scoring tiles emit a soft glow; the highest possible tile is 131,072.

If a move causes three consecutive tiles of the same value to slide together, only the two tiles farthest along the direction of motion will combine. If all four spaces in a row or column are filled with tiles of the same value, a move parallel to that row/column will combine the first two and last two. A scoreboard on the upper-right keeps track of the user's score. The user's score starts at zero, and is increased whenever two tiles combine, by the value of the new tile.

The game is won when a tile with a value of 2048 appears on the board. Players can continue beyond that to reach higher scores.When the player has no legal moves (there are no empty spaces and no adjacent tiles with the same value), the game ends.


### Features 
1.randomness. The game randomly generates 2 or 4 at a random empty grid.
2.Usage of data strucures for storing status. For example, we use int variables to keep trace of the score of the players. Besides, 2D array will be used for storing the number at each position of the chessboard after each click. 
