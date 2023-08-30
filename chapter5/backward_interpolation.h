#ifndef B_INTERPOLATE_H
#define B_INTERPOLATE_H

double backward_newton_interp(double x[], double y[], int n, double xi) {
    double div_diff[n][n];

    // calculate divided differences table
    for (int i = 0; i < n; i++) {
        div_diff[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            div_diff[i][j] = (div_diff[i][j-1] - div_diff[i-1][j-1]) / (x[i] - x[i-j]);
        }
    }

    // perform interpolation
    double result = div_diff[n-1][0];
    double term = 1.0;
    for (int j = 1; j < n; j++) {
        term *= (xi - x[n-j]);
        result += div_diff[n-1][j] * term;
    }
    return result;
    
}
#endif 