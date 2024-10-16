#ifndef AVDMID_NQUEENSOLVER_H
#define AVDMID_NQUEENSOLVER_H

#include <vector>

class NQueenSolver {
protected:
    int boardSize;
    std::vector<int> queenPositions;
public:
    NQueenSolver();

    void setQueenSize(const int size);

    virtual bool canPlaceQueen(int currentRow, int currentCol) const;

    virtual void solve(int currentRow);

    void displayResult() const;

    virtual void measureSolveTime(int currentRow);
};

#endif //AVDMID_NQUEENSOLVER_H
