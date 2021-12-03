# COMP2113 Group Project - 2048

## Group No.72
Tang Yiyi 3035830636  
Zhou Yantong 3035770965


## Rules
[Reference: https://en.wikipedia.org/wiki/2048_(video_game)]  

2048 is played on a plain 4×4 grid, with numbered tiles that slide when a player moves them using the four arrow keys (in our game, 'W' serves as a up arrow, 'A' for left, 'S' for down and 'D' for right). Every turn, a new tile randomly appears in an empty spot on the board with a value of either 2 or 4. 

At each turn, the play can perform a legal move if at least one tile will slide (not blocked by either another tile or the edge of the grid) or merge (collide with anoth tilt of the same number, fusing into a tile with the total value of the two tiles that collided) in the direction inputted. 

The game is won when a tile with a value of 2048 appears on the board. However, when the player has no legal moves (there are no empty spaces and no adjacent tiles with the same value), the game ends.


## Features 
### Random Tiles
The game randomly generates a tile of value 2 or 4 at a random empty grid every turn.

The position of tile as well as the number are both generated with the help of rand() and a random seed, which fulfills Requirement#1.

### Printed status and Score
After each move of the player, the program will output the new status of the 4\*4 tiles for reference. Plus, a scoreboard at the bottom will also be printed to keep track of the user's score.

This feature is achieved by a 2D array storing the number at every tiles, together with an integer storing the latest score. (Related requirement: #2)

### Undo
Our game offers a powerful, special feature: UNDO. The player has the option to undo at any time during the game, restoring the tiles to their previous state. In addition, please be aware that the undo function is unlimited: you can even go back to the very first status when you started the game, so long as the game is not over or been exited.

This feature is supported by an 4x4 array of linked lists for storing the status of the tiles on every turn, as well as a single linked list storing the score. We chose to store this information dynamically since we won't be able to figure out the size of the memory allocated to this function at the beginning. This  also fulfills Requirement#2 and #3.

### Save & Load
During the game, the players can pause and save the current status of 2048 tiles at any time. This will automatically create a new file in the directory, from which the players can choose to resume at next time by loading it.

As for this feature, a .txt file will be created as output or read as input for saving & loading. This fulfills Requirement#4.

**All of the features mentioned above will be achieved by separate functions and struct stored in independent source files, and will be compiled for use by Makefile. (Related requirement: #5)**

## Compilation Instructions
1. Download all the files as a .zip file.
2. Decompress the file into a folder.
3. Go to the diretory of the folder in Shell.
4. Use the command "make main" to compile the program.
5. Use the command "./main" to execute the program.
