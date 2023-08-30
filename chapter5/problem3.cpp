// problem 5.3 pg - 196 
// This code uses semi lagrange interpolation

#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include "lagrange_interpolation.h"

using namespace std;

int main(){

    double T[] = {0, 10, 15, 30, 50, 60, 80 };   // Temperature
    double eta[] = {0.001793, 0.001308, 0.001142, 0.000800, 0.000547, 0.000467, 0.000355};   // Viscosity
    int n = sizeof(T)/sizeof(T[0]);     // size of array
    double Ti = 20;   // Temperature at which viscosity is to be calculated using interpolation
    double eta_i;  // interpolated viscosity

    eta_i = lagrange_interpolate(T, eta, n, Ti); 
    cout << "Viscosity at T = " << Ti << " is = " << eta_i << endl;
    return 0;

}