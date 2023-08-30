// Exercise problem 2.4 || Pg - 66

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double f( double Q, double t){
    double V = 20.0;
    double R = 1e6;
    double C = 1e-6;
    if (t>10) {V=0;}
    return V/R -Q/(R*C);
}

int main(){
    
    double Q = 0.0; //km
    double dt = 0.001; 
    double t;
    double k1, k2, k3, k4;
    ofstream myfile;
    myfile.open("problem14.txt");
    myfile << t << '\t' << Q << endl;
    while(t <= 20){
      
        k1 = dt*f( Q , t) ;
        k2 = dt*f( Q + k1/2, t + dt/2);
        k3 = dt*f( Q + k2/2, t + dt/2);
        k4 = dt*f( Q + k3/2, t + dt);
    
        Q = Q + k1/6 + k2/3 + k3/3 + k4/6 ;
        t = t + dt;

        myfile << t << '\t' << Q << endl;
    }
    myfile.close();

    return 0;
}