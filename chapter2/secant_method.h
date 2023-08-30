#ifndef SECANT_METHOD_H
#define SECANT_METHOD_H

// Algorithm for secant method
// two initial guesses (a and b) are needed
// derivative of a function is not needed
// updated solution is given as
//                             x = (x1 * f(x2) - x2 * f(x1)) / ( f(x2) - f(x1) )                   
//                             where x2 = b and x1 = a 
//
//


#include <iostream>
#include <cmath>
#include "secant_method.h"
using namespace std;

double secant_method(double a, double b, double (*f)(double), double tol, int max_iter){
    double fx1 = f(a);
    double fx2 = f(b);
    double x1 = a, x2 = b;
    double x = (x1 * fx2 - x2 * fx1) / (fx2 - fx1); 
    double fx = f(x);
    int iter = 0;
    
    while (fabs(fx)>tol && iter < max_iter) { 
        x = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        fx = f(x); 
        x1 = x2;
        x2 = x;
        iter++;
        cout << "Iteration: " << iter << "   Root: " << x << endl;

    }
    
    return x;
}



#endif