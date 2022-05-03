#include <iostream>
#include <fstream>
#include "main.h"
#include "solver.h"
#include "constants.h"

using namespace std;

Solver::Solver() {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = 0;
        }
    }
}

void Solver::printBoard() {
    for (int x = 0; x < boardSize; x++) {
        for (int y = 0; y < boardSize; y++) {
            cout << board[x][y] << " ";
        }
        cout << endl;
    }
}

bool Solver::readSudoku(string fileName) {
    ifstream inputFile(fileName);
    string input;
    int charCounter = 0;

    // Check if file exists
    if (!inputFile.is_open()) {
        cout << "Cant open " << fileName << endl;
        return false;
    }

    for (int x = 0; x < boardSize; x++) {
        for (int y = 0; y < boardSize; y++) {
            inputFile >> input;

            // Check if too many characters in input file
            charCounter++;
            if (charCounter > boardSize * boardSize) {
                cout << "Too many characters (max " << boardSize * boardSize << ") in " << fileName << endl;
                return false;
            }

            // Check if too few characters in input file
            if (inputFile.eof() && charCounter <= boardSize * boardSize) {
                cout << "Too few characters (max " << boardSize * boardSize << ") in " << fileName << endl;
                return false;
            }

            // Check if character in file is a number and 1 <=  character <= boardSize
            if (!isNumber(input) || stringToInt(input) < 1 || stringToInt(input) > boardSize) {
                cout << "Invalid char: \'" << input << "\' in " << fileName << endl;
                return false;
            }
            board[x][y] = stringToInt(input);
        }
    }
    return true;
}
