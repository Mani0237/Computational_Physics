// Problem 3.5 pg - 93 

#include <iostream>
#include <cmath>
#include "secant_method.h"
#include "regula_falsi.h"

using namespace std;

// This program solves van der Walls' eq using secant method


double g(double V){
    const double a = 0.00874; 
    const double b = 0.0023;
    double T = 273;            // T is temperature
    double p = 1;              // p is pressure 
    double R = 0.00368652;     // gas constant 
    return p*pow(V,3) - (p*b + R*T)*pow(V,2) + a*V - a*b;
}

int main(){
    
    double h1 = 0.5;         // Initial Guess 1
    double h2 = 1.5;           // Initial Guess 2
    double tol = 1e-6;       // Tolerance
    int max_iter = 10000;
    double root_s = secant_method(h1, h2, g, tol, max_iter);
    printf("Root using Secant method: %f \n", root_s);
    cout << endl; 
    double root_f = regula_falsi(h1, h2, g, tol, max_iter);
    printf("Root using regula falsi method: %f \n", root_f);
    return 0;
}