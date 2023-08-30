#ifndef LAGRANGE_INTERPOLATION_H
#define LAGRANGE_INTERPOLATION_H

// following is the function file for lagrange interpolation
// this interpolation can be used for evenly spaced as well as unevenly spaced data points
// on the contrary Newton's interpolation can't be used for uneven spacing
// The only disadvantage is that it requires more computations in case of uneven data
// with lagrange interpolation

double lagrange_interpolate(double x[], double y[], int N, double X ){
    double p;
    double sum = 0;

    for(int i = 0; i < N; i++){
        p = y[i];
        for(int j = 0; j < N; j++){
            if(j != i)
                p = ( (X - x[j]) / (x[i]-x[j]) ) * p ;
        }
        sum = sum + p;
    }

    return sum;

}

#endif