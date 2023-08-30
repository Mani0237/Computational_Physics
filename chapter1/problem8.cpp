#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double fv(double t, double x, double v){
    double a = 0.50;
    return (- a*v - x);
}

double fx(double t, double v){
    return v;
}

int main(){
    
    double t = 0;
    double x = 1;
    double v = 1;
    double dt = 0.1;
    double k1, k2, k3, k4;
    double kx1, kx2, kx3, kx4;
    ofstream myfile;
    myfile.open("problem805.txt");
    myfile << t << '\t' << x << '\t' << v << endl;

    while(t <= 100){
        k1 = dt*fv(t, x, v);
        k2 = dt*fv(t + dt/2, x, v + k1/2);
        k3 = dt*fv(t + dt/2, x, v + k2/2);
        k4 = dt*fv(t + dt, x, v + k3);
        v = v + k1/6 + k2/3 + k3/3 + k4/6 ;

        kx1 = dt*fx(t, v);
        kx2 = dt*fx(t + dt/2, v + kx1/2);
        kx3 = dt*fx(t + dt/2, v + kx2/2);
        kx4 = dt*fx(t + dt, v + kx3);
        x = x + kx1/6 + kx2/3 + kx3/3 + kx4/6 ;
        t = t + dt;
        myfile << t << '\t' << x << '\t' << v << endl;
    }
    myfile.close();

    return 0;
}