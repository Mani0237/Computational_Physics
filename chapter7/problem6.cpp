// Example 7.8 pg 254

#include <iostream>
#include <cmath>
#include <fstream>
#include "Bessel.h"

using namespace std; 

/*============================================================
-------------------------------------------------------------
> This code calculates the Intensity distribution pattern for
  Fraunhofer diffraction due to circular aperture.
> Bessels function is called from "Bessel.h" with n = 1.
-------------------------------------------------------------

INPUTS: n      - type of Bessel function used (here n = 1)
        l      - the wavelength of light used (in cm)
        a      - radius of circular aperture (in cm)
        theta  - angular position on screen (degree)
        dtheta - increment in theta (degree)
        theta1 - angle in radians
        I      - Intensity ratio at theta
        k      - wave number
        x      - parameter for Bessel function (k*a*sin(theta))
==============================================================*/

int main(){

    int n = 1;
    double a = 0.005;
    double l = 5.893e-5;
    double theta = 0.0;
    double theta1 = 0.0;
    double dtheta = 0.0001;
    double I = 1;
    double k = (2 * M_PI) / l ; 
    double x = 0;
    double x_max = 10; 

    ofstream myfile;
    myfile.open("intensity.txt");

    while(x <= x_max){
       
        theta1 = theta*M_PI/180;
        x = k*a*sin(theta1);
        I = pow((2*Bessel(n,x)/x), 2);
        
        // Writing data in file
        myfile << x << "\t" << I << endl; 

        // increasing the theta
        theta = theta + dtheta;

    }
    
    myfile.close();

    return 0;
}