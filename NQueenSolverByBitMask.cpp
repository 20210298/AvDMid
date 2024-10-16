#include "NQueenSolverByBitMask.h"

NQueenSolverByBitMask::NQueenSolverByBitMask() : NQueenSolver(), columnMask(0), diagonalMask(0), antiDiagonalMask(0) {}

bool NQueenSolverByBitMask::canPlaceQueen(int currentRow, int currentCol) const {
    return !(columnMask & (1 << currentCol)) &&
           !(diagonalMask & (1 << (currentRow - currentCol + boardSize - 1))) &&
           !(antiDiagonalMask & (1 << (currentRow + currentCol)));
}

void NQueenSolverByBitMask::solve(int currentRow) {
    if (currentRow == boardSize) {
        displayResult();
        return;
    }
    for (int currentCol = 0; currentCol < boardSize; ++currentCol) {
        if (canPlaceQueen(currentRow, currentCol)) {
            queenPositions[currentRow] = currentCol;
            placeQueen(currentRow, currentCol);

            solve(currentRow + 1);

            removeQueen(currentRow, currentCol);
            queenPositions[currentRow] = -1;
        }
    }
}

void NQueenSolverByBitMask::placeQueen(int currentRow, int currentCol) {
    columnMask |= (1 << currentCol);
    diagonalMask |= (1 << (currentRow - currentCol + boardSize - 1));
    antiDiagonalMask |= (1 << (currentRow + currentCol));
}

void NQueenSolverByBitMask::removeQueen(int currentRow, int currentCol) {
    columnMask &= ~(1 << currentCol);
    diagonalMask &= ~(1 << (currentRow - currentCol + boardSize - 1));
    antiDiagonalMask &= ~(1 << (currentRow + currentCol));
}

void NQueenSolverByBitMask::measureSolveTime(int currentRow) {
    if (currentRow == boardSize) {
        return;
    }
    for (int currentCol = 0; currentCol < boardSize; ++currentCol) {
        if (canPlaceQueen(currentRow, currentCol)) {
            queenPositions[currentRow] = currentCol;
            placeQueen(currentRow, currentCol);

            measureSolveTime(currentRow + 1);

            removeQueen(currentRow, currentCol);
            queenPositions[currentRow] = -1;
        }
    }
}
