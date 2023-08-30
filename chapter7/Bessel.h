/*=====================================================================
> The following code calculates the Bessel function 
> To call the function you can use 
    Bessel(n, x)
            where n : an integer >= 0 (order of bessel function)
                  x : point at which Bessel function is to be calculated
=======================================================================*/

#ifndef BESSEL_H
#define BESSEL_H

#include <cmath>

/*----------------------------------------------------
INPUTS: 
         n    - integer value from main program
         x    - double value from main code
         s    - number of terms in summation. Increases by 1 in each iteration
         sum  - stores value of Bessel function for s terms
         tol  - tolerance to stop the summation
         diff - another parameter to control loop termination   

OUTPUT:  B - stores the value of Bessel function at particular x

------------------------------------------------------*/

double Bessel(int n, double x){
    double B = 0;
    double s = 0; 
    double sum = 0;
    double diff = 1;
    double tol = 0.000001;

    while(abs(diff) > tol){
        B = B + (pow(-1, s) / (tgamma(n+s+1)*tgamma(s+1))) * pow((x/2),(n+2*s));
        diff = sum - B;
        s = s + 1;
        sum = B; 
    }

    return B;
}

#endif