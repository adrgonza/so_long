# So Long

Welcome to So Long! This project involves creating a simple 2D game using the MinilibX library. The goal is to design a game where the player navigates a character through a map, collects items, avoids obstacles, and reaches the goal. By completing this project, you'll gain experience in graphics programming, game design, and handling user input in C programming.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Game Description](#game-description)
4. [Building](#building)
5. [Contributing](#contributing)
6. [Credits](#credits)

## Introduction

In So Long, you'll create a simple 2D game where the player controls a character through a map. The game window will display the map, character, items, and obstacles. The player's goal is to navigate the character through the map, collect items, avoid obstacles, and reach the goal to win the game. You'll use the MinilibX library to handle graphics and user input.

## Usage

To play So Long, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/adrgonza/so_long.git
    ```

2. Compile the game:

    ```bash
    make
    ```

3. Run the game:

    ```bash
    ./so_long map_file
    ```

Replace `map_file` with the path to the map file you want to use. Map files should follow a specific format (explained below).

## Game Description

So Long is a simple 2D game where the player controls a character represented by a sprite. The game window displays a map consisting of tiles, where each tile represents a different element such as the character, items, obstacles, or the goal. The player navigates the character using arrow keys or other specified controls. The goal is to collect all items, avoid obstacles, and reach the goal to win the game.

### Map Format

The map file should follow a specific format:

- Each character represents a different element:
  - '1': Wall
  - '0': Empty space
  - 'P': Player character
  - 'E': Exit or goal
  - 'C': Collectible item
- The map should have at least one player character ('P') and one exit ('E').
- The map should be rectangular, with each row having the same number of characters.

Example map file:

1111111111
10000C00E1
1P00000001
1111111111


## Building

To build the So Long game, simply run:

```bash
make
```
This will compile all source files and create the so_long executable.

## Contributing
Contributions are welcome! If you find any bugs or have suggestions for improvement, please open an issue or submit a pull request on GitHub.

## Credits
This project was created by adrgonza for the so_long project at 42Madrid.
