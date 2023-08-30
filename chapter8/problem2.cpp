// Example 8.2 pg- 282

#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>

using namespace std;

/*=====================================================
-------------------------------------------------------
>>  The following code solves Poisson's equation
    using method of successive relaxation i.e, 
    V(i,j) = V(i,j) + w * R(i,j)
>>  For the current problem w is taken to be 0.25
>>  Vxx + Vyy = - rho is the problem with rho = 1
>>  L-infinite norm is calculated for calculating error
-------------------------------------------------------

Variables: N - number of grid points along x and y
           h - grid spacing 
           V - two dimensional array to store updated potential
           R - Residual of solution in each step
           w - weight factor for residual    
           k - number of iterations 
           rho - charge density function in our case
           tol - tolerance level of error 
========================================================*/

int main(){

    // allocating memory and declaring variables
    int N = 40;
    double h = 0.025;
    double V[N][N];
    double R[N][N];
    double rho[N][N];
    double w = 0.2; 
    int k = 0;
    double tol = 1e-6;
    double error = 1.0;

    //Initializing solution
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            V[i][j] = 0;
            R[i][j] = 0;
            
            if(i < N/2){
                rho[i][j] = 1.0;
            }
            else{
                rho[i][j] = -1.0;
            }    
        }
    }

    ofstream myfile1;
    myfile1.open("Lnorm.txt");

    auto start = chrono::high_resolution_clock::now();
    while(error>tol){
        printf("Iteration %d done \n", k+1);
        
        double maxError = 0;    

        for(int i = 1; i<N-1; i++){
            for(int j = 1; j<N-1; j++){
                
                R[i][j] = V[i+1][j] + V[i-1][j] + V[i][j+1] + V[i][j-1] - 4*V[i][j] + rho[i][j]*pow(w,2) ;
                
                double diff = abs(R[i][j]);
                if (diff > maxError) {
                    maxError = diff;
                }
            }
        }
        
        error = maxError;

        for(int i = 1; i < N-1; i++){
            for(int j = 1; j < N-1; j++){
                V[i][j] = V[i][j] + w * R[i][j];
            }
        }

        k = k + 1;
        myfile1 << k << "\t" << error << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::duration<double> >(end - start).count();

    myfile1.close();

    ofstream myfile;
    myfile.open("Poisson.txt");

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            myfile << i << "\t" << j << "\t" << V[i][j] << endl;
        }
    }    

    myfile.close();

    cout << "Elapsed time: " << duration << " seconds" << endl;

    return 0;
}