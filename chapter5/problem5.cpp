//*************************************************

// Exerxise 5.1 pg-209
// This program is to implement newton's
// forward interpolation 

// Fi is the load in Kg
// dl is elongation in cm
// Young's modulus is to be calculated for
// l = 100.2 cm and diameter = 0.35cm 
// The result is to be calculated in SI units

//*************************************************

#include <iostream>
#include "forward_interpolation.h"

using namespace std;

int main() {

    double F[] = {0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0};     // Load
    double dl[] = {0, 0.013, 0.027, 0.045, 0.060, 0.075, 0.089};
    int n = sizeof(F) / sizeof(F[0]);
    double Fi = 0.35;
    double interp_val = forward_newton_interp(F, dl, n, Fi);
    cout << "Interpolated value at F = " << Fi << " is " << interp_val << endl;
    
    double l = 0.1002;   // length in metre
    double d = 0.35e-2;  // diameter in metre
    double Y;            // Young's modulus
    double Stress = 4 * Fi / (M_PI*pow(d,2));
    double Strain = interp_val / l ;
    Y = Stress / Strain ; 
    cout << "Young's modulus in SI units is  = " << Y << endl;

    return 0;

}
