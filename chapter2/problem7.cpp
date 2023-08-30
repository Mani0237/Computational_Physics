// Problem 3.7 pg - 98 

#include <iostream>
#include <cmath>
#include "bisection.h"
#include "secant_method.h"
using namespace std;

// This program solves angle of projection of a projectile motion


double f(double theta){
    double a = 3.89e-5;  // a = D/m  
    double g = 9.8;     // feet/sec^2
    double v0 = 650;
    double R = 20000;    // R is range  
    return (1/a)*(g/(v0*cos(theta)) + a*tan(theta))*R + (g/pow(a,2))*log(1 - R*a/(v0*cos(theta))) ;
}

int main(){
    
    double h1 = 1.2, h2 = 1.6;          // Initial Guess 
    double tol = 1e-6;                  // Tolerance
    int max_iter = 10000;
    double root = (180/M_PI) * bisection(h1, h2, f,  tol, max_iter);
    printf("Root using bisection method: %f \n", root);
    double root_s =(180/M_PI) * secant_method(h1, h2, f,  tol, max_iter);
    printf("Root using secant method: %f \n", root_s);
    return 0;
}