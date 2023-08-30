// Example 7.3 pg - 243
// This time the problem is being solved using
// Legendre polynomial

#include <iostream>
#include <cmath>
#include <fstream>
#include "legendre.h"

using namespace std;

double phi_calculation(double theta, double a, double R){
    int n = 0;
    int k;
    double sum = 0.0, sum2 = 0.0;
    double error = 1.0;
    
    while(abs(error)>1e-4){
        if(n%2==0)
            {k = n/2;}
        else
            {k = (n-1)/2;}

        sum2 = sum2 + Pnx(k, n, cos(theta))*pow((a/R),n);
        error = sum2 - sum;
        n = n + 1;
        sum = sum2; 
    }

    return sum2;
}

int main(){

    // defining all the parameters
    double a = 0.5;
    double e = 8.854e-12;
    double q = 1e-6;
    double k = 1/(4* M_PI * e);
    double dx = 0.1, dy = 0.1;
    double x0 = -15, y0 = -15;
    int Nx = abs(2*x0)/dx, Ny = abs(2*y0)/dy;
    
    // allocating memory to arrays
    double x[Nx], y[Ny], r[Nx][Ny];
    double theta, theta1, phi[Nx][Ny], phi_L;

    for(int i = 0; i < Nx; i++){
        x[i] = x0 + i*dx;
        y[i] = y0 + i*dy;
    }

    ofstream myfile, myfile1;
    myfile.open("Output.txt");
    myfile1.open("Output1.txt");

    for(int i = 0; i < Nx; i++){
        for(int j = 0; j < Ny; j++){
            r[i][j] = sqrt( pow(x[i],2) + pow(y[j],2)); 
            if(r[i][j] > a + 1.50){
                theta = atan(y[j]/x[i])*180/M_PI;
                
                if(x[i]>0.0 & y[j]>0.0){        // I Quadrant
                    theta1 = theta;
                }
                else if(x[i]<0.0 & y[j]>0.0 ){  // II Quadrant
                    theta1 = theta + 180;
                }
                else if(x[i]<0.0 & y[j]<0.0 ){  // III Quadrant
                    theta1 = theta + 180;
                }
                else{                           // IV Quadrant 
                    theta1 = theta + 360;
                }                                

                theta = theta1*M_PI/180;

                phi[i][j] = k*q/(sqrt(pow(r[i][j],2) + pow(a,2) - 2*a*r[i][j]*cos(theta))) ;
                myfile << x[i] << "\t" << y[j] << "\t" << phi[i][j] << endl;

                double radius = r[i][j];
                phi_L = k*(q/radius)*phi_calculation(theta, a, radius);
                myfile1 << x[i] << "\t" << y[j] << "\t" << phi_L << endl;

            }
        }
    }

    myfile.close();
    myfile1.close();

    return 0;

}