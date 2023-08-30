// Exercise problem 2.3 || Pg - 65

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double f( double z){
    double rho0 = 1.276;
    double z0 = 8.0;
    double rho = rho0*exp(z/z0);
    const double g = 9.8;
    return -g*rho;
}

int main(){
    
    double z = 8.0; //km
    double dz = 0.001; 
    double rho, rho0;
    double P = 1e5; //Pa
    double k1, k2, k3, k4;
    ofstream myfile;
    myfile.open("problem13b.txt");
    myfile << z << '\t' << P << endl;
    while(z <= 16){
      
        k1 = dz*f( z);
        k2 = dz*f( z + dz/2);
        k3 = dz*f( z + k2/2);
        k4 = dz*f( z + k3/2);
    
        P = P + k1/6 + k2/3 + k3/3 + k4/6 ;
        z = z + dz;

        myfile << z << '\t' << P << endl;
    }
    myfile.close();

    return 0;
}