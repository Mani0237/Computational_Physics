// example 8.3 pg-286

#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>

using namespace std;

/*=====================================================================
-----------------------------------------------------------------------
>>  This code implements FTCS scheme to solve the heat equation.
    This is a 'EXPLICIT' method so it won't always be stable.
>>  The grid is discretized into Nx points in space and Nt in time.
>>  Courant number C =  K*dt/(dx*dx) is chosen to follow CFL condition
    i.e C <= 0.5
-----------------------------------------------------------------------    

VARIABLES:  L - length of rod
            t_max - time till which evolution of solution is studied
            k - Heat constant
            dt - time steps
            dx - grid spacing
            Nx - total spatial points
            Nt - total time steps
            T - array to store Temperature values
            C - Courant number
-----------------------------------------------------------------------

- The solution is initialized with boundry conditions
- FTCS discretization is implemented to calculate solution from solution
  of previous time step.
- The data obtained at the end of all iterations is stored in a file
  named "Heat.txt"  
_______________________________________________________________________
======================================================================*/



int main(){

    double L = 1;
    double t_max = 20;
    double k = 0.004;
    double dt = 0.01;
    double dx = 0.01;
    int Nx = L / dx;
    int Nt = t_max / dt;
    double T[Nt][Nx];
    double C = k*dt/(dx*dx);

    if(C>=0.50){
        cout << "Not Stable. Change dt and dx" << endl;
    }

    for(int i = 0; i<Nt; i++){
        for(int j = 0; j<Nx; j++){
            if(j==0 || j==Nx-1){
                T[i][j] = 100.0;
            }
            else{
                T[i][j] = 27.0;
            }
        }
    }

    for(int i = 0; i<Nt-1; i++){
        for(int j = 1; j<Nx-1; j++){
            T[i+1][j] = T[i][j] + C*( T[i][j+1] - 2*T[i][j] + T[i][j-1]);
        }
    }

    ofstream myfile;
    myfile.open("Heat.txt");

    for(int i = 0; i<Nx; i++){
        myfile <<  i*dx << " ";
        if(i == Nx-1){
            myfile << "\n" ;
        }
    }

    for(int j = 0; j<Nt; j++){
        for(int i = 0; i<Nx; i++){
            myfile << T[j][i] << " ";
        }
        myfile << endl;
    }    
    myfile.close();

    return 0;

}