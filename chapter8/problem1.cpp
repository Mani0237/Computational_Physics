// Example 8.1 pg - 270

#include <iostream>
#include <cmath>
#include <fstream> 

using namespace std;

/*==============================================================================
>> The following code solves Poisson's equation for 
   given boundry conditions. 
>> The potential at boundries is zero and in central
   part it is 100.
>> L-infinite norm is used for convergence   

INPUTS:  V[i][j]   - Two dimensional grid containing the potential at any point 
         x and y   - any point in the domain                 
         Nx and Ny - Number of grid points along x and y respectively
         h         - grid spacing along x and y
         x_max     - length of domain
         y_max     - width of domain
         V_new     - updated value of V
         error     - difference between updated V and previous V
         tol       - tolerance level to exit while loop 
         count     - number of iterations to obtain convergence
================================================================================*/


int main(){

    double x_max = 10;
    double y_max = 10;
    double x = 0, y = 0;
    double h = 0.2 ;
    int Nx = x_max/h;
    int Ny = y_max/h;
    double V[Nx][Ny];
    double V_new[Nx][Ny];
    double error = 1;
    double tol = 1e-6;
    int count = 1;

    // Initializing the array
    for(int i = 0; i < Nx; i++ ){
        for(int j = 0; j < Ny; j++){
            x = (i+1)*h;
            y = (j+1)*h;
            if(x>=4 && x<=7 && y>=4 && y<=7){
                V[i][j] = 100;
                V_new[i][j] = 100;
            }
            else{
                V[i][j] = 0;
                V_new[i][j] = 0;
            }

        }
    }

    while(error > tol){
        double maxError = 0.0;
        for (int i = 1; i < Nx - 1; i++) {
            for (int j = 1; j < Ny - 1; j++) {
                x = (i + 1) * h;
                y = (j + 1) * h;
                if (!(x >= 4 && x <= 7 && y >= 4 && y <= 7)) {
                    V_new[i][j] = 0.25 * (V[i + 1][j] + V[i - 1][j] + V[i][j + 1] + V[i][j - 1]);
                    double diff = abs(V_new[i][j] - V[i][j]);
                    if (diff > maxError) {
                        maxError = diff;
                    }
                }
            }
        }

        error = maxError;

        for(int i = 1; i<Nx-1; i++){
            for(int j = 1; j<Ny-1; j++){
                V[i][j] = V_new[i][j];  
            }
        }

        count++;
    }

    ofstream myfile;
    myfile.open("Laplance.txt");
    for(int i = 0; i<Nx; i++){
       for(int j = 0; j<Ny; j++){
            x = (i+1)*h;
            y = (j+1)*h;
            myfile << x << "\t" << y << "\t" << V[i][j] << endl; 
        }
    }
    myfile.close();
    

    cout << "Iterations = " << count << endl;
    return 0;
}