#include "NQueenSolver.h"
#include "NQueenSolverByBitMask.h"

#include <iostream>

using namespace std;

const int MIN_BOARD_SIZE = 4;

void getInput(int &nQueenSize) {
    while (true) {
        cout << "Enter ChessBoardSize (at least 4): ";
        cin >> nQueenSize;

        if (nQueenSize >= MIN_BOARD_SIZE) {
            break;
        } else {
            cout << "Invalid size. Please try again." << endl;
        }
    }
}

void solveNQueens(int nQueenSize) {
    NQueenSolver q;
    q.setQueenSize(nQueenSize);
    q.solve(0);

    NQueenSolverByBitMask qBit;
    qBit.setQueenSize(nQueenSize);
    qBit.solve(0);
}

int main() {
    int nQueenSize;
    getInput(nQueenSize);

    solveNQueens(nQueenSize);
}
