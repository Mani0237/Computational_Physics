#ifndef REGULA_FALSI_H
#define REGULA_FALSI_H

#include <iostream>
#include <cmath>
#include "regula_falsi.h"
using namespace std;

double regula_falsi(double a, double b, double (*f)(double), double tol, int max_iter) {
    double fa = f(a);
    double fb = f(b);
    double x = (a * fb - b * fa) / (fb - fa); // initial estimate
    double fx = f(x);
    double x_new, fx_new;
    int iter = 0;
    
    if (fa * fb >= 0) {
        cout << "No root in given interval" << endl;
        return 404;
    }
    
    while (fabs(fx)>tol && iter < max_iter) {
        x_new = (a * fb - b * fa) / (fb - fa); // calculate new estimate using secant line
        fx_new = f(x_new);
        
        if (fabs(fx_new) < tol) {
            // root found with sufficient accuracy
            x = x_new;
            fx = fx_new;
            break;
        }
        
        if (fa * fx_new < 0) {
            // root is between a and x_new
            b = x_new;
            fb = fx_new;
        } else {
            // root is between x_new and b
            a = x_new;
            fa = fx_new;
        }
        
        x = x_new;
        fx = fx_new;
        iter++;
        cout << "Iteration: " << iter << "   Root: " << x << endl;
    }
    
    return x;
}

#endif