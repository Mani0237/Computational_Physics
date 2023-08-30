#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double f(double L, double N){
    return -L*N;
}

int main(){
    
    double t = 0;
    double N = 0.5;
    double N1, Np, Nc;
    double L = 0.1;
    double dt = 0.1;

    ofstream myfile;
    myfile.open("problem6.txt");

    while(t <= 100){
        N = N + dt*f(L,N);
        t = t + dt;
        myfile << t << '\t' << N << endl;
    }
    myfile.close();

    return 0;
}