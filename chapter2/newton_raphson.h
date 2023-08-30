#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

#include <iostream>
#include <cmath>
using namespace std;

double newton_raphson(double a, double (*f)(double), double (*df)(double), double tol, int max_iter) {
    double fx = f(a);
    double x = a; 
    double x_new; // initial estimate
    int iter = 0;
    
    while (fabs(fx)>tol && iter < max_iter) {
        x_new = x - f(x)/df(x);
        x = x_new;
        fx = f(x_new); 
        iter++;
        cout << "Iteration: " << iter << "   Root: " << x << endl;
    }
    
    return x;
}



#endif