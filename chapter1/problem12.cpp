// Exercise problem 2.1 pg- 64

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double f( double v, double b, double m, double g){
    return   g - v*v*b/m;
}

int main(){
    
    double t = 0;
    double dt = 0.001;
    const double g = 9.8 ; //ms^2 
    double b, m, v;
    double k1, k2, k3, k4;
    cout << "Enter the value of b: " << endl; 
    cin >> b ; 
    cout << "Enter the mass: " << endl; 
    cin >> m ;   
    v = 0;
    double v_old ;
    ofstream myfile;
    myfile.open("problem12b.txt");
    myfile << t << '\t' << v << endl;

    while(t <= 35){
      
        k1 = dt*f( v, b, m, g);
        k2 = dt*f( v + dt/2, b, m, g);
        k3 = dt*f( v + k2/2, b, m, g);
        k4 = dt*f( v + k3/2, b, m, g);
        v_old = v;
        v = v + k1/6 + k2/3 + k3/3 + k4/6 ;
       
        t = t + dt;
        myfile << t << '\t' << v << endl;
        if (t >= 15) {b = 500;}
    }
    myfile.close();

    return 0;
}