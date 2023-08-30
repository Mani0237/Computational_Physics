// Problem 3.2 pg - 74

#include <iostream>
#include <cmath>
#include "bisection.h"

using namespace std;

double g(double h){
    double rho = 0.2;
    double r = 0.5;
    return pow(h,3) - 3*r*pow(h,2) + 4*rho*pow(r,3);
}

int main(){
    
    double h ;
    double r = 0.5 ; 
    double h1 = -10 ;
    double h2 = 4 ;
    double tol = 1e-6;
    int max_iter = 10000;
    double root = bisection(h1, h2 , g, tol, max_iter);
    printf("Root: %f \n", root);
    double n_theory = log(abs(h1-h2)/tol)/log(2);
    cout << "Theoretical iterations required: " << n_theory << endl;
    return 0;
}