#ifndef F_INTERPOLATE_H
#define F_INTERPOLATE_H

// In this code there is no need of calculating the 
// factorials as divided difference is being used

#include <iostream>
#include <cmath>

double forward_newton_interp(double x[], double y[], int n, double xi) {
    double div_diff[n][n];

    // calculate divided differences table
    for (int i = 0; i < n; i++) {
        div_diff[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            div_diff[i][j] = (div_diff[i+1][j-1] - div_diff[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    // perform interpolation
    double result = div_diff[0][0];
    double term = 1.0;
    for (int j = 1; j < n; j++) {
        term *= (xi - x[j-1]);
        result += div_diff[0][j] * term;
    }
    return result;
    
}


#endif 