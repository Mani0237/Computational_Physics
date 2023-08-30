// ex 9.1 pg-302
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){

    double N0[5] = {0.2, 0.5, 0.7, 1.2, 1.7};
    int k = 1;
    double r = 0.5;
    double t;
    double dt = 0.001;
    double t_max = 15.0;
    int steps = t_max/dt;
    double N[steps];

    for(int i = 0; i<5; i++){
        N[0] = N0[i];
        t = 0.0;
        ofstream myfile;
        string filename = "result_" + to_string(N[0]) + ".txt";
        myfile.open(filename);

        for(int j = 0; j < steps - 1; j++){
            myfile << t << "\t" << N[j] << endl;
            N[j+1] = N[j] + dt * r * N[j] * (1 - N[j]/k); 
            t = t + dt;
        }

        myfile.close();
    }

    return 0;

}