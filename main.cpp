#include <iostream>
#include <vector>
#include <string>

using namespace std;

class nQueen {
    vector<int> board;
protected:
    int boardSize;
public:
    nQueen() : boardSize(0), board(0) {}

    void setQueenSize(const int size) {
        boardSize = size;
        board.resize(size, -1);
    }

    virtual bool canPlaceQueen(int currentRow, int currentCol) {
        for (int prevRow = 0; prevRow < currentRow; ++prevRow) {
            int prevCol = board[prevRow];
            if (prevCol == currentCol || abs(prevRow - currentRow) == abs(prevCol - currentCol))
                return false;
        }
        return true;
    };

    virtual void solve(int currentRow = 0) {
        if (currentRow == boardSize) {
            showResult();
            return;
        }
        for (int currentCol = 0; currentCol < boardSize; ++currentCol) {
            if (canPlaceQueen(currentRow, currentCol)) {
                board[currentRow] = currentCol;
                solve(currentRow + 1);
                board[currentRow] = -1;
            }
        }
    };

    virtual void showResult() {
        for (int row = 0; row < boardSize; ++row) {
            int col = board[row];
            cout << "Row " << row + 1 << " - " << "Col " << col + 1 << " | ";
            for (col = 0; col < boardSize; ++col) {
                if (board[row] == col) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    };
};

class nQueenByBitMask : public nQueen {
    int columnMask;
    int diagonalMask;
    int antiDiagonalMask;
public:
    nQueenByBitMask() : nQueen(), columnMask(0), diagonalMask(0), antiDiagonalMask(0) {}

    void solve(int row = 0) override {
        if (row == boardSize) {
            showResult();
            return;
        }
        for (int col = 0; col < boardSize; ++col) {
            if (canPlaceQueen(row, col)) {
                placeQueen(row, col);
                solve(row + 1);
                removeQueen(row, col);
            }
        }
    }

    bool canPlaceQueen(int currentRow, int currentCol) override {
        return !(columnMask & (1 << currentCol)) &&
               !(diagonalMask & (1 << (currentRow - currentCol + boardSize - 1))) &&
               !(antiDiagonalMask & (1 << (currentRow + currentCol)));
    }

    void placeQueen(int currentRow, int currentCol);

    void removeQueen(int currentRow, int currentCol);

    void showResult() override;
};

int main() {
    int nQueenSize;

    while (true) {
        cout << "Enter ChessBoardSize (at least 4): ";
        cin >> nQueenSize;
        cout << endl;

        try {
            if (nQueenSize < 4) {
                throw string("Try Again");
            }
            nQueen q;
            q.setQueenSize(nQueenSize);
            q.solve();
            break;
        } catch (const string &exMsg) {
            cout << exMsg << endl;
        }
    }
}
