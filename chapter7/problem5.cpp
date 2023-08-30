// Example 7.5 pg - 250

#include <iostream>
#include <cmath>
#include <fstream>

#include "Bessel.h"

using namespace std;

int main(){

    int ni[] = {0, 1, 2, 3, 4};
    int n;
    double xi = 0;
    double xf = 20;
    double dx = 0.01;
    int N = (xf- xi)/dx; 
    int nmax = sizeof(ni)/sizeof(ni[0]);

    for(int i = 0; i<nmax; i++){
        n = ni[i];
        ofstream myfile;
        string filename = "Bessel_n" + to_string(n) + ".txt";
        myfile.open(filename);
        
        #pragma omp parallel for num_threads(1)
        for(int j = 0; j<=N; j++){
            myfile << j*dx << "\t" << Bessel(n, j*dx) << endl; 
        }

        myfile.close();
    }

    return 0;
}