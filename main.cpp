#include <iostream>
#include "constants.h"
#include "main.h"
#include "solver.h"

using namespace std;

int main() {
    // First test if a valid board size is set
    try {
        sqrt(boardSize);
    } catch (invalid_argument &e) {
        cout << e.what();
        return 0;
    }

    Solver s;
    s.printBoard();

    int input = menu();
    string fileName;

    while (input != 0) {
        switch (input) {
            case 1:
                cout << "File name: ";
                cin >> fileName;
                if (s.readSudoku(fileName)) {
                    s.printBoard();
                }
                break;
            case 2:
                if (s.solveSudoku()) {
                    cout << "Solved sudoku" << endl;
                    s.printBoard();
                    break;
                }
                cout << "Couldn't solve sudoku" << endl;
                s.printBoard();
                break;
        }
        input = menu();
    }
    return 0;
}

int menu() {
    string input;

    cout << "0: Exit" << endl;
    cout << "1: Read sudoku from file" << endl;
    cout << "2: Solve sudoku" << endl;
    cout << "Input: ";

    cin >> input;
    while (!isNumber(input) || stringToInt(input) < 0 || stringToInt(input) > 2) {
        cout << "Invalid input" << endl;
        cout << "Input: ";
        cin >> input;
    }

    return stringToInt(input);
}

bool isNumber(string s) {
    for (long unsigned int i = 0; i < s.size(); i++) {
        if (s.at(i) < '0' || s.at(i) > '9') {
            return false;
        }
    }
    return true;
}

int stringToInt(string s) {
    int toReturn = 0;
    for (long unsigned int i = 0; i < s.size(); i++) {
        toReturn *= 10;
        toReturn += (s.at(i) - 48);
    }
    return toReturn;
}

int sqrt(int num) {
    int toReturn = 0;
    while (true) {
        if (toReturn * toReturn == num) {
            return toReturn;
        }
        if (toReturn > num) {
            throw invalid_argument("Invalid board size, needs to have a int square root (1, 2, 9, 16, 25 etc.)");
        }
        toReturn++;
    }
}

