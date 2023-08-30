#ifndef SIMPSON_H
#define SIMPSON_H

#include <cmath>
#include <iostream>

/* ----------------------------------------
!  The following code implements numerical integration using Simpson 1/3 rule
!   INPUTS : f(x)    - the function which is to be integrated
             n       - number of elements to be used for integration
             l_lim   - the lower limit of integration
             u_lim   - the upper limit of integration
             y_exact - exact value of the Integration. This is for calculating error. (OPTIONAL)

    OUTPUTS : VAlue of integral is printed along with the error          
--------------------------------------------*/

void simpson(double f(double), int n, double l_lim, double u_lim, double y_exact){
        
    double x[n+1], y[n+1];
    double h = (l_lim - u_lim)/n;
    double y_simp = 0;

    y[0] = f(l_lim);
    y[n] = f(u_lim);
    y_simp = y[0] + y[n];

    for(int i = 1; i<n; i++){
        x[i] = l_lim + i*h;
        if(i % 2 == 0){
            y[i] = 2*f(x[i]);
        }
        else{
            y[i] = 4*f(x[i]);
        }
        y_simp = y_simp + y[i];
    }    
    double result = (1.0/3.0) * h * y_simp;
    double error = abs(result - y_exact);

    printf("N = %d \t I = %f \t Error = %f \n", n, result, error); 

}

#endif 