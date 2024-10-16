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

//int main() {
//    int nQueenSize;
//    getInput(nQueenSize);
//
//    solveNQueens(nQueenSize);
//
//}

// -------------Test -------------

#include <vector>
#include <chrono>

using namespace chrono;

void measure(NQueenSolver &solver, int size) {
    vector<long long> times;
    for (int i = 0; i < 1; ++i) {
        auto start = high_resolution_clock::now();  // 시작 시간

        solver.setQueenSize(size);
        solver.measureSolveTime(0);


        auto end = high_resolution_clock::now();  // 종료 시간
        auto duration = duration_cast<nanoseconds>(end - start).count();  // 실행 시간을 나노초로 계산
        times.push_back(duration);  // 실행 시간을 벡터에 추가
    }

    // 평균 실행 시간 계산
    long long total = 0;
    for (long long time: times) {
        total += time;
    }
    long long average = total / times.size();  // 평균 계산

    cout << "Average execution time: " << average << " nanoseconds" << endl;  // 결과 출력
}

int main() {
    int nQueenSize;
    getInput(nQueenSize);

    NQueenSolver q;
    cout << "Basic Solve" << endl;
    measure(q, nQueenSize);

    NQueenSolverByBitMask p;
    cout << "Solved with BitMasking" << endl;
    measure(p, nQueenSize);
}
