// Exercise problem 2.1 pg- 64

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double f(double T, double v, double m, double g, double k){
    return  T/m - g - k*v*v/m;
}

int main(){
    
    double t = 0;
    double dt = 0.1;
    const double g = 9.8 ; //ms^2 
    double k, T, m, v;
    double k1, k2, k3, k4;
    cout << "Enter the value of K: " << endl; 
    cin >> k ; 
    cout << "Enter the mass: " << endl; 
    cin >> m ;   
    cout << "Enter the Thrust: " << endl; 
    cin >> T ;
    t = 0;
    v = 0;
    ofstream myfile;
    myfile.open("problem11.txt");
    myfile << t << '\t' << v << endl;

    while(t <= 25){
        k1 = dt*f(T, v, m, g, k);
        k2 = dt*f(T, v + dt/2, m, g, k);
        k3 = dt*f(T, v + k2/2, m, g, k);
        k4 = dt*f(T, v + k3/2, m, g, k);

        v = v + k1/6 + k2/3 + k3/3 + k4/6 ;
        t = t + dt;
        myfile << t << '\t' << v << endl;

    }
    myfile.close();

    return 0;
}