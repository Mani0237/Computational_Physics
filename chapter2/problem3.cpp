// Problem 3.3 pg - 82

#include <iostream>
#include <cmath>
#include "bisection.h"

using namespace std;

double g(double h){
    double rho = 0.2;
    double r = 0.5;
    return pow(h,3) - 3*r*pow(h,2) + 4*rho*pow(r,3);
     //return h*h -1 ;
}

int main(){
    
    double h ;
    double r = 0.5 ; 
    double h1 = -0.5 ;
    double h2 = 2 ;
    double tol = 1e-6;
    int max_iter = 10000;
    double root_b = bisection(h1, h2 , g, tol, max_iter);
    printf("Root using Bisection method: %f \n", root_b);
    //double root_f = regula_falsi(h1, h2 , g, tol, max_iter);
    //printf("Root using Regula Falsi method: %f \n", root_f);
    //double n_theory = log(abs(h1-h2)/tol)/log(2);
    //cout << "Theoretical iterations required: " << n_theory << endl;
    return 0;
}