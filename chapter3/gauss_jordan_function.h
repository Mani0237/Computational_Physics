#ifndef GJORDAN_H
#define GJORDAN_H

#include <cmath>
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void gauss_jordan(double A[][MAX_SIZE], double B[], double x[], int n) {
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
