#include <iostream>
#include <fstream>
#include "constants.h"
#include "main.h"
#include "solver.h"

using namespace std;

Solver::Solver() {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = 0;
        }
    }
}

void Solver::printBoard() {
    cout << endl;
    for (int x = 0; x < boardSize; x++) {
        for (int y = 0; y < boardSize; y++) {
            cout << board[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool Solver::readSudoku(string fileName) {
    ifstream inputFile(fileName);
    string input;

    // Check if file exists
    if (!inputFile.is_open()) {
        cout << "Cant open " << fileName << endl;
        return false;
    }

    for (int x = 0; x < boardSize; x++) {
        for (int y = 0; y < boardSize; y++) {
            if (inputFile.eof()) {
                input = "0";
            } else {
                inputFile >> input;
            }

            // Check if character in file is a number and 1 <=  character <= boardSize
            if (!isNumber(input) || stringToInt(input) < 0 || stringToInt(input) > boardSize) {
                cout << "Invalid char: \'" << input << "\' in " << fileName << endl;
                return false;
            }
            board[x][y] = stringToInt(input);
        }
    }
    return true;
}

bool Solver::solveSudoku() {
    int row;
    int col;
    // When no empty places remain, sudoku is solved
    if (!getEmptyPlace(row, col)) {
        return true;
    }
    for (int i = 1; i <= boardSize; i++) {
        if (validPlace(row, col, i)) {
            board[row][col] = i;
            // Check other places using recursion
            if (solveSudoku()) {
                return true;
            }
            // Else if this board results in unsolvable sudoku, make the spot 0
            board[row][col] = 0;
        }
    }
    return false;
}

bool Solver::getEmptyPlace(int &row, int &col) {
    for (row = 0; row < boardSize; row++) {
        for (col = 0; col < boardSize; col++) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool Solver::numIsInRow(int row, int num) {
    for (int i = 0; i < boardSize; i++) {
        if (board[row][i] == num) {
            return true;
        }
    }
    return false;
}

bool Solver::numIsInCol(int col, int num) {
    for (int i = 0; i < boardSize; i++) {
        if (board[i][col] == num) {
            return true;
        }
    }
    return false;
}

bool Solver::numIsInBox(int row, int col, int num) {
    for (int i = 0; i < sqrt(boardSize); i++) {
        for (int j = 0; j < sqrt(boardSize); j++) {
            if (board[(row - (row % sqrt(boardSize))) + i][(col - (col % sqrt(boardSize))) + j] == num) {
                return true;
            }
        }
    }
    return false;
}

bool Solver::validPlace(int row, int col, int num) {
    return !numIsInRow(row, num) && !numIsInCol(col, num) && !numIsInBox(row, col, num);
}

int Solver::sqrt(int num) {
    int toReturn = 0;
    while (true) {
        if (toReturn * toReturn == num) {
            return toReturn;
        }
        toReturn++;
    }
}