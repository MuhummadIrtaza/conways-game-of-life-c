# Conway's Game of Life in C

This repository contains an implementation of Conway's Game of Life written in C. The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.

## Features

- Random initialization of the grid with cells in either dead or alive state.
- Automatic updating of the grid based on Conway's rules.
- Simple and portable implementation suitable for Unix-like environments.

## Requirements

To run the program, you need:

- A C compiler (e.g., GCC)
- A Unix-like environment (e.g., Linux or macOS)

## Usage

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/MuhammadIrtaza/game-of-life-c.git
    ```

2. Navigate to the repository directory:

    ```bash
    cd game-of-life-c
    ```

3. Compile the program:

    ```bash
    gcc -o game_of_life game_of_life.c
    ```

4. Run the program:

    ```bash
    ./game_of_life
    ```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
