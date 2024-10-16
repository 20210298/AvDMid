#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MIN_BOARD_SIZE = 4;

class NQueenSolver {
protected:
    int boardSize;
    vector<int> queenPositions;
public:
    NQueenSolver () : boardSize(0) {}

    void setQueenSize(const int size) {
        boardSize = size;
        queenPositions.resize(size, -1);
    }

    virtual bool canPlaceQueen(int currentRow, int currentCol) const {
        for (int prevRow = 0; prevRow < currentRow; ++prevRow) {
            int prevCol = queenPositions[prevRow];
            if (prevCol == currentCol || abs(prevRow - currentRow) == abs(prevCol - currentCol))
                return false;
        }
        return true;
    };

    virtual void solve(int currentRow = 0) {
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
    };

    void displayResult() const {
        for (int row = 0; row < boardSize; ++row) {
            cout << "Row " << row + 1 << " - " << "Col " <<  (queenPositions[row] + 1) << " | ";
            for (int col = 0; col < boardSize; ++col) {
                cout << (queenPositions[row] == col ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
    };
};

class NQueenByBitMask : public NQueenSolver  {
    int columnMask;
    int diagonalMask;
    int antiDiagonalMask;
public:
    NQueenByBitMask() : NQueenSolver (), columnMask(0), diagonalMask(0), antiDiagonalMask(0) {}

    bool canPlaceQueen(int currentRow, int currentCol) const override {
        return !(columnMask & (1 << currentCol)) &&
               !(diagonalMask & (1 << (currentRow - currentCol + boardSize - 1))) &&
               !(antiDiagonalMask & (1 << (currentRow + currentCol)));
    }

    void solve(int row = 0) override {
        if (row == boardSize) {
            displayResult();
            return;
        }
        for (int col = 0; col < boardSize; ++col) {
            if (canPlaceQueen(row, col)) {
                queenPositions[row] = col;
                placeQueen(row, col);

                solve(row + 1);

                removeQueen(row, col);
                queenPositions[row] = -1;
            }
        }
    }

    void placeQueen(int row, int col) {
        columnMask |= (1 << col);
        diagonalMask |= (1 << (row - col + boardSize - 1));
        antiDiagonalMask |= (1 << (row + col));
    }

    void removeQueen(int row, int col) {
        columnMask &= ~(1 << col);
        diagonalMask &= ~(1 << (row - col + boardSize - 1));
        antiDiagonalMask &= ~(1 << (row + col));
    }
};

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
    q.solve();

    NQueenByBitMask qBit;
    qBit.setQueenSize(nQueenSize);
    qBit.solve();
}

int main() {
    int nQueenSize;
    getInput(nQueenSize);

    solveNQueens(nQueenSize);
}
