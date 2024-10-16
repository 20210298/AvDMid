#include "NQueenSolver.h"
#include <iostream>

using namespace std;

NQueenSolver::NQueenSolver () : boardSize(0) {}

void NQueenSolver::setQueenSize(const int size) {
    boardSize = size;
    queenPositions.resize(size, -1);
}

bool NQueenSolver::canPlaceQueen(int currentRow, int currentCol) const {
    for (int prevRow = 0; prevRow < currentRow; ++prevRow) {
        int prevCol = queenPositions[prevRow];
        if (prevCol == currentCol || abs(prevRow - currentRow) == abs(prevCol - currentCol))
            return false;
    }
    return true;
}

void NQueenSolver::solve(int currentRow) {
    if (currentRow == boardSize) {
        displayResult();
        return;
    }
    for (int currentCol = 0; currentCol < boardSize; ++currentCol) {
        if (canPlaceQueen(currentRow, currentCol)) {
            queenPositions[currentRow] = currentCol;
            solve(currentRow + 1);
            queenPositions[currentRow] = -1;
        }
    }
}

void NQueenSolver::displayResult() const {
    for (int row = 0; row < boardSize; ++row) {
        cout << "Row " << row + 1 << " - " << "Col " <<  (queenPositions[row] + 1) << " | ";
        for (int col = 0; col < boardSize; ++col) {
            cout << (queenPositions[row] == col ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void NQueenSolver::measureSolveTime(int currentRow) {
    if (currentRow == boardSize) {
        return;
    }
    for (int currentCol = 0; currentCol < boardSize; ++currentCol) {
        if (canPlaceQueen(currentRow, currentCol)) {
            queenPositions[currentRow] = currentCol;
            measureSolveTime(currentRow + 1);
            queenPositions[currentRow] = -1;
        }
    }
}