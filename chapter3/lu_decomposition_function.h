#ifndef LU_DECOMPOSITION_H
#define LU_DECOMPOSITION_H

#include <cmath>
#include <iostream>
using namespace std;

// The number of equation to be solved is n
// The coefficient matrix = A[i][j] with i,j = 1,2,3,...n
// The lower triangular matrix = L[i][j] with i,j = 1,2,3,...n
// The upper triangular matrix = U[i][j] with i,j = 1,2,3,...n
// B[i] with i = 1,2,3...n are the constants of the equations
// x[i] with i = 1,2,3,..n are the solutions of the system

const int MAX_SIZE = 10;

void LU_decomposition(double A[][MAX_SIZE], double B[], double x[], int n) {
    //STEP 1: Taking the inputs (done in main file)
    //STEP 2: Pivoting the elements and elimination
    for (int k = 0; k < n; k++) {
        int max = k;
        for (int i = k + 1; i < n; i++) {
            if (abs(A[i][k]) > abs(A[max][k]))
                max = i;
        }

        // Swap rows if required
        if (max != k) {
            for (int j = k; j < n; j++) {
                swap(A[k][j], A[max][j]);
            }
            swap(B[k], B[max]);
        }

        // Divide the pivot row by pivot element
        double pivot = A[k][k];
        for (int j = k; j < n; j++) {
            A[k][j] = A[k][j]/pivot;
        }
        B[k] = B[k] / pivot;

        // Eliminate
        for (int i = 0; i < n; i++) {
            if (i != k) {
                double factor = A[i][k];
                for (int j = k; j < n; j++) {
                    A[i][j] = A[i][j] - factor * A[k][j];
                }
                B[i] = B[i] - factor * B[k];
            }
        }
    }

    // Step 3: Solution
    for (int i = 0; i < n; i++) {
        x[i] = B[i];
    }
}

#endif
