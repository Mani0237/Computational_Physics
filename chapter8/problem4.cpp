// NOT CORRECT SOME ISSUES ARE THERE!!!!

// example 8.4 pg-289
#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>
#include "gauss_elimination_function.h"

using namespace std;

/*=====================================================================
-----------------------------------------------------------------------
>>  This code implements a imlicit scheme to solve the heat equation.
    This method will always be stable.
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

  double L = 1.0;
  double t_max = 20;
  double k = 0.004;
  double dt = 0.01;
  double dx = 0.01;
  int Nx = L / dx;
  int Nt = t_max / dt;
  double T[MAX_SIZE];
  double T_new[MAX_SIZE];
  double A[MAX_SIZE][MAX_SIZE] = {0};
  double C = k*dt/(dx*dx);

  for(int i = 0; i< Nx; i++){
    if(i==0){
      T[i] = 100;
    }
    else if(i==Nx-1){
      T[i] = 100;
    }
    else{
      T[i] = 27;
    }  
  }

  for(int i = 0; i<Nx; i++){
    for(int j = 0; j<Nx; j++){
      if(i==0){
        A[i][i] = 1.0 + 2.0*C;
        A[i][i+1] = -C;
        A[i][Nx-1] = -C; 
      }
      else if(i == Nx-1){
        A[i][i] = 1.0 + 2.0*C;
        A[i][0] = -C;
        A[i][i-1] = -C; 
      }
      else{
        A[i][i] = 1.0 + 2.0*C;
        A[i][i+1] = -C;
        A[i][i-1] = -C;
      }
    }
  }

  for(int iter = 0; iter<40  ; iter++){
    gauss_elimination(A, T, T_new, Nx);
    for(int i = 1; i<Nx-1; i++){
      T[i] = T_new[i];
    }
  }

  for(int i = 0; i<Nx; i++){
    cout << T[i] << " ";
  }

  return 0;

}    
 