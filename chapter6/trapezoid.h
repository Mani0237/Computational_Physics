#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <cmath>
#include <iostream>

/* ----------------------------------------
!  The following code implements numerical integration using Trapezoid rule
!   INPUTS : f(x)    - the function which is to be integrated
             n       - number of elements to be used for integration
             l_lim   - the lower limit of integration
             u_lim   - the upper limit of integration
             y_exact - exact value of the Integration. This is for calculating error. (OPTIONAL)

    OUTPUTS : VAlue of integral is printed along with the error          
--------------------------------------------*/


void trapezoid(double f(double), int n, double l_lim, double u_lim, double y_exact){
        
    double x[n+1], y[n+1];
    double h = (u_lim - l_lim)/n;
    double y_trap = 0;

    y[0] = f(l_lim);
    y[n] = f(u_lim);
    y_trap = y[0] + y[n];

    for(int i = 1; i< n; i++){
        x[i] = l_lim + i * h;
        y[i] = 2.0 * f(x[i]);
        y_trap = y_trap + y[i];
        
    }    
    double result = 0.5 * h * y_trap;
    double error = abs(result - y_exact);

    printf("N = %d \t I = %f \t  Error = %f \n", n, result, error); 

}

#endif