#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double fv(double x){
    return -x;
}

double fx(double v){
    return v;
}

int main(){
    
    double t = 0;
    double x = 0.1;
    double v = 0;
    double dt = 0.1;

    ofstream myfile;
    myfile.open("problem7.txt");

    while(t <= 100){
        v = v + dt*fv(x);
        x = x + dt*fx(v);
        t = t + dt;
        myfile << t << '\t' << x << '\t' << v << endl;
    }
    myfile.close();

    return 0;
}