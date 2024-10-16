#ifndef AVDMID_NQUEENSOLVERBYBITMASK_H
#define AVDMID_NQUEENSOLVERBYBITMASK_H

#include "NQueenSolver.h"

class NQueenSolverByBitMask : public NQueenSolver {
private:
    int columnMask;
    int diagonalMask;
    int antiDiagonalMask;
public:
    NQueenSolverByBitMask();

    bool canPlaceQueen(int currentRow, int currentCol) const override;

    void solve(int row) override;

    void placeQueen(int row, int col);

    void removeQueen(int row, int col);
};

#endif //AVDMID_NQUEENSOLVERBYBITMASK_H
