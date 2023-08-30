// example 5.1 pg-188 
// This program is to implement newton's
// forward interpolation 

#include <iostream>
#include "forward_interpolation.h"

using namespace std;

int main() {

    double x[] = {0, 10, 20, 30, 40, 50, 60};
    double y[] = {0.0061, 0.0123, 0.0234, 0.0424, 0.0738, 0.1124, 0.1992};
    int n = sizeof(x) / sizeof(x[0]);
    double xi = 52;
    double interp_val = forward_newton_interp(x, y, n, xi);
    cout << "Interpolated value at x = " << xi << " is " << interp_val << endl;
    return 0;

}
