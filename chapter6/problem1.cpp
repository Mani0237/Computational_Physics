//********************************************************

// Example 6.2 pg 221 
// The code implements numerical integration 
// using trapexoidal method 

/*

*/

//********************************************************
// not correct answer yet
#include <iostream> 
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "trapezoid.h"

using namespace std;

// Trapezoid method is not working for the following function
double f(double x){
    double func;
    double rho = 1.0 / (3.14 * (0.1 * 0.2));
    func = 2.0 * rho * sqrt( 0.01 * (1.0 - ( (x * x) / 0.04)) ) * (x * x) ;
    return func;
}

double g(double x){
    return x*x + 1;
}

int main(){
    
    int n, n_max;
    double u = 1;
    double l = 0;
    double y_exact = 1.333; 
    int N[] = {8, 16, 32, 64} ;
    n_max = sizeof(N)/sizeof(N[0]) ;
    
    for(int i = 0; i < n_max; i++){
        n = N[i];
        trapezoid(g, n, l, u, y_exact);
    }

    return 0;

}