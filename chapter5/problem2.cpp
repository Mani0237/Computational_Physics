// problem 5.2 pg- 192

#include <iostream>
#include "backward_interpolation.h"
using namespace std;

int main() {

    double x[] = {110, 130, 160, 190};
    double y[] = {1.08, 0.81, 0.55, 0.48};
    int n = sizeof(x) / sizeof(x[0]);
    double xi = 140;
    double interp_val = backward_newton_interp(x, y, n, xi);
    cout << "Interpolated value at x = " << xi << " is " << interp_val << endl;
    return 0;

}
