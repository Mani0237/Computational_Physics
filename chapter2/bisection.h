#ifndef BISECTION_H
#define BISECTION_H

#include <iostream>
#include <cmath>
#include "bisection.h"
using namespace std;

double bisection(double a, double b, double (*f)(double), double tol, int max_iter){
    
    double fa = f(a);
    double fb = f(b);
    double c = (a+b)/2;
    double fc = f(c);
    int iter = 0;
    if(fa*fb>=0){
        cout << "No root in given interval" << endl;
        return 404;
    }
    while(fabs(fc)>tol && iter < max_iter){
          if(fa*fc<0){
            b = c;
            fb = f(c);
          }
          else{
            a = c;
            fa = f(a);
          }
          c = (a+b)/2;
          fc = f(c);
          iter++; 
          cout << "Iteration: " << iter << "   Root: " << c << endl;
          
    }      
    cout << "Required precision is reached in " << iter << " iterations" << endl;
    return c; 
}

#endif