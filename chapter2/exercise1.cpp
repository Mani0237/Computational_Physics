// Exercise 3.1 pg - 105

#include <iostream>
#include <cmath>
#include "bisection.h"
using namespace std;

double g(double h){
    //return (1/8.0)*(35*pow(h, 4) - 30*pow(h ,2) + 3);
    return cos(h) - h;
}

int main(){
    
    double h ; 
    double h1 = 1 ;
    double h2 = -0.5 ;
    double tol = 1e-8;
    int max_iter = 10000;
    double root_b = bisection(h1, h2 , g, tol, max_iter);
    printf("Root using Bisection method: %f \n", root_b);
    //double root_f = regula_falsi(h1, h2 , g, tol, max_iter);
    //printf("Root using Regula Falsi method: %f \n", root_f);
    //double n_theory = log(abs(h1-h2)/tol)/log(2);
    //cout << "Theoretical iterations required: " << n_theory << endl;
    return 0;
}