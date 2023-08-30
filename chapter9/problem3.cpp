// ex - 9.3 pg - 310
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){

    double X[6] = {0.5, 1.8, M_PI - 0.0001, M_PI + 0.0001, -5.0, 5.0};
    double V[6] = {0.0, 0.0, -0.0001, 0.0001, 3.0, -3.0};
    double t = 0.0;
    double x, v;
    double dt = 0.01;
    
    for(int j = 0; j<6; j++){
        x = X[j];
        v = V[j];
        t = 0.0;

        ofstream myfile;
        string filename = "problem3_result_" + to_string(j) + ".txt"; 
        myfile.open(filename);
    
        for(int i = 0; i<1500; i++){
    
            myfile << t << "\t" << x << "\t" << v << endl;
            
            t = t + dt;
            x = x + dt * v;
            v = v - dt * sin(x);
        }
        myfile.close();
    }
    return 0;
}