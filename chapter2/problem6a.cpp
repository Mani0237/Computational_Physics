// Problem 3.6 pg - 97 

#include <iostream>
#include <cmath>
#include "newton_raphson.h"

using namespace std;

// This program solves time of flight of a projectile motion


double f(double t){
   double a = 5.0;  // a = m / D 
   double g = 32.0; // feet/sec^2
   double v0 = 100; // feet/sec
   double th = 45 ;  // theta in degree
   double theta = th*M_PI/180;   // theta in radian 
   return pow(a,2) * (g + (1/a)*v0*sin(theta)) * (1 - exp(-t/a)) - a*g*t ;
}

double df(double t){
   double a = 5.0;  // a = m / D 
   double g = 32.0; // feet/sec^2
   double v0 = 100; // feet/sec
   double th = 45 ;  // theta in degree
   double theta = th*M_PI/180;   // theta in radian 
   return a * (g + a*v0*sin(theta)) * (exp(-a*t)) - a*g*t ;

}


int main(){
    
    double t0 = 2;          // Initial Guess 
    double tol = 1e-3;       // Tolerance
    int max_iter = 10000;
    double a = 5.0;  // a = m / D 
    double g = 32.0; // feet/sec^2
    double v0 = 100; // feet/sec
    double th = 45 ;  // theta in degree
    double theta = th*M_PI/180;   // theta in radian 
    double root = newton_raphson(t0, f, df, tol, max_iter);
    printf("Root using Secant method: %f \n", root);
    double R;    // R is the range
    R = v0*a*cos(theta)*(1-exp(-root/a));
    printf("The range of projectile is %f \n", R);
    return 0;
}