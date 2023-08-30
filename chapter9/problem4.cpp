// ex - 9.4 pg - 313
// This program solves for van der Pol Oscillator
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){

    double X[6] = {5.0, 3.0, 1.0, -1.0, -3.0, -5.0};
    double V[6] = {5.0, 5.0, 5.0, 5.0, 5.0, 5.0};
    double t = 0.0;
    double x, v;
    double dt = 0.01;
    
    for(int j = 0; j<6; j++){
        x = X[j];
        v = V[j];
        t = 0.0;

        ofstream myfile;
        string filename = "problem4_result_" + to_string(j) + ".txt"; 
        myfile.open(filename);
    
        for(int i = 0; i<1500; i++){
    
            myfile << t << "\t" << x << "\t" << v << endl;
            
            t = t + dt;
            x = x + dt * v;
            v = v - dt * ( (pow(x, 2) - 4.0) * v + x);
        }
        myfile.close();
    }
    return 0;
}