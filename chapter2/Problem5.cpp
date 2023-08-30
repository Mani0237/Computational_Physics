// Problem 3.4 pg - 88

#include <iostream>
#include <cmath>
#include "newton_raphson.h"
//#include "bisection.h"
//#include "regula_falsi.h"
using namespace std;

// This program solves Kepler's problem using Newton Raphson


double g(double h){
    const double T = 365.2564;
    double t = 27;            // t is some smaller interval
    double M = 2*M_PI*t/T ;   // T is Time period of earth 
                              // M is mean anomaly (angle)
    double e = 0.016710219;   // eccentricity 
    return M - h + e*sin(h);
}

// This function calculates analytical derivative
double dg(double h){
        const double T = 365.2564;
        double t = 27;            // t is some smaller interval
        double M = 2*M_PI*t/T ;   // T is Time period of earth 
                                // M is mean anomaly (angle)
        double e = 0.016710219;   // eccentricity 
    return -1 + e*cos(h); 
}

int main(){
    const double T = 365.2564;
    double h ;
    double t = 27;  
    double e = 0.016710219;  

    double h1 = M_PI*t/T;  // Initial Guess 
    double tol = 1e-6;       // Tolerance
    int max_iter = 10000;
    double root_n = newton_raphson(h1, g, dg, tol, max_iter);
    printf("Root using Newton Raphson method: %f \n", root_n);
    double a = 1.0 ; // semi major axis in AU
    double x = a*cos(root_n);
    double y = a*sqrt(1-e*e)*sin(root_n);
    printf("Position on Feb 1: (x,y) = (%f, %f) \n", x, y );
    return 0;

}