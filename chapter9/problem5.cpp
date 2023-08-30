// ex - 9.5 pg - 316
// This program solves for Lorents attractor
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){

    double x = 0, y = 1.0, z = 0, t = 0;
    double sigma = 10.0;
    double r = 28.0;
    double b = 8.0/3.0;
    double dt = 0.001;
    int iterations = 100000;

    ofstream myfile;
    string filename = "problem5_result.txt"; 
    myfile.open(filename);

    for(int i = 0; i < iterations-1; i++){

        myfile << t << "\t" << x << "\t" << y << "\t" << z << endl;
        
        t = t + dt;
        x = x + dt * sigma * (y - x);
        y = y + dt * ( r * x - y - x * z);
        z = z + dt * ( x * y - b * z); 
    }
    myfile.close();

    return 0;
}