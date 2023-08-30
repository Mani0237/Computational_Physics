#ifndef TRIDIAGONAL_SOLVER_H
#define TRIDIAGONAL_SOLVER_H

#include <cmath>
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void tridiagonal_solver(double A[][MAX_SIZE], double B[], double x[], int n) {
    // Forward elimination
    for (int i = 1; i < n; i++) {
        double m = A[i][i-1] / A[i-1][i-1];
        A[i][i] = A[i][i] - m * A[i-1][i];
        B[i] = B[i] - m * B[i-1];
    }

    // Backward substitution
    x[n-1] = B[n-1] / A[n-1][n-1];
    for (int i = n-2; i >= 0; i--) {
        x[i] = (B[i] - A[i][i+1] * x[i+1]) / A[i][i];
    }
}

#endif
