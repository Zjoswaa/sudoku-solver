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

    // Finds first empty (0) place on the board
    // Returns true if found and gives row and col the coordinates of this place
    // Else returns false
    bool getEmptyPlace(int &row, int &col);

    // Checks if num is in row
    bool numIsInRow(int row, int num);

    // Checks if num is in col
    bool numIsInCol(int col, int num);

    // Checks if num is in box that contains (row, col)
    bool numIsInBox(int row, int col, int num);

    // Checks if place is a valid place for num
    bool validPlace(int row, int col, int num);

    // Sqrt of int
    int sqrt(int num);

public:
    // Constructor
    Solver();

    // Print the board
    void printBoard();

    // Read sudoku from file
    // Returns true if succesful
    // False if any errors occur
    bool readSudoku(string fileName);

    // Solves the sudoku
    // Returns true if succeeded
    // Else returns false
    bool solveSudoku();
};

#endif //SUDOKU_SOLVER_SOLVER_H
