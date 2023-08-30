#ifndef JACOBI_INVERSE_H
#define JACOBI_INVERSE_H

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 20;

void gauss_jordan_inverse(double A[][MAX_SIZE], double b[][MAX_SIZE], int n) {
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) {
                b[i][j] = 1.0;
            }
            else {
                b[i][j] = 0.0;
            }
        }
    }

    for (int k=0; k<n; k++) {
        // Partial pivoting
        int i_max = k;
        double max_value = fabs(A[k][k]);

        for (int i=k+1; i<n; i++) {
            if (fabs(A[i][k]) > max_value) {
                i_max = i;
                max_value = fabs(A[i][k]);
            }
        }

        // Swap rows k and i_max
        if (i_max != k) {
            for (int j=k; j<n; j++) {
                std::swap(A[k][j], A[i_max][j]);
            }
            for (int j=0; j<n; j++) {
                std::swap(b[k][j], b[i_max][j]);
            }
        }

        // Divide the pivot row by the pivot element
        double pivot = A[k][k];
        for (int j=k; j<n; j++) {
            A[k][j] /= pivot;
        }
        for (int j=0; j<n; j++) {
            b[k][j] /= pivot;
        }

        // Eliminate the pivot column from all other rows
        for (int i=0; i<n; i++) {
            if (i != k) {
                double factor = A[i][k];
                for (int j=k; j<n; j++) {
                    A[i][j] -= factor * A[k][j];
                }
                for (int j=0; j<n; j++) {
                    b[i][j] -= factor * b[k][j];
                }
            }
        }
    }

}


#endif