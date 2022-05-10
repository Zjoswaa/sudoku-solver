#ifndef SUDOKU_SOLVER_MAIN_H
#define SUDOKU_SOLVER_MAIN_H

#include <iostream>
using namespace std;

// Menu for user input
int menu();

// Checks if s has a numerical value
// If it is, it gives num this value and returns true
// Else it returns false
bool isNumber(string s);

// Converts s to an int and returns it
int stringToInt(string s);

// Sqrt of int
int sqrt(int);

#endif //SUDOKU_SOLVER_MAIN_H
