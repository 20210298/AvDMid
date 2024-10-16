#ifndef AVDMID_NQUEENSOLVERBYBITMASK_H
#define AVDMID_NQUEENSOLVERBYBITMASK_H

#include "NQueenSolver.h"

class NQueenSolverByBitMask : public NQueenSolver {
private:
    long long columnMask;
    long long diagonalMask;
    long long antiDiagonalMask;
public:
    NQueenSolverByBitMask();

    bool canPlaceQueen(int currentRow, int currentCol) const override;

    void solve(int currentRow) override;

    void placeQueen(int currentRow, int currentCol);

    void removeQueen(int currentRow, int currentCol);

    void measureSolveTime(int currentRow) override;
};

#endif //AVDMID_NQUEENSOLVERBYBITMASK_H
