#ifndef SUDOKU_SOLVER_SOLVER_H
#define SUDOKU_SOLVER_SOLVER_H

#include <iostream>
#include "constants.h"

using namespace std;

class Solver {
private:
    int board[boardSize][boardSize];
    // (0 0) (1 0) (2 0)
    // (0 1) (1 1) (2 1)
    // (0 2) (1 2) (2 2)

public:
    // Constructor
    Solver();

    // Print the board
    void printBoard();

    // Read sudoku from file
    // Returns true if succesful
    // False if any errors occur
    bool readSudoku(string fileName);
};

#endif //SUDOKU_SOLVER_SOLVER_H
