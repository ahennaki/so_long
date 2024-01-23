# So Long

This is a basic 2D game developed in C using the MiniLibX library. The objective of the game is for the main character to collect all the collectibles on the map and then reach the exit. The game is played in a top-down view and the player can move in four directions using the W, A, S, and D keys (or ZQSD or arrow keys).

## Installation

Clone the repository or download the source code.
Make sure you have the MiniLibX library installed. You can use the version available on the school machines or install it from the source code.
Compile the source code using the provided Makefile: make

## Usage

    ./so_long map.ber

Replace map.ber with the path to your map description file.

## Map Description

The map is constructed using three components: walls, collectibles, and free space. The map can be composed of the following characters:

- 0 for an empty space,
- 1 for a wall,
- C for a collectible,
- E for the map exit,
- P for the player's starting position.

The map must contain at least one exit, one collectible, and one starting position to be valid. It must also be rectangular and surrounded by walls. If there are any duplicates or invalid configurations in the map file, the program will display an error message and exit.

## Controls

- Use the W, A, S, and D keys (or ZQSD or arrow keys) to move the main character.
- Press ESC or click the close button to quit the game.

## Features

- Smooth window management and event handling.
- Display of the current number of movements in the shell.
- Graphics rendered using the MiniLibX library.
- Error handling for invalid maps.

## Bonus Features

- Player loses when touching an enemy patrol.
- Sprite animation.
- Display of movement count directly on the screen.
  
