#ifndef GJACOBI_H
#define GJACOBI_H

/*
Gauss Seidel is exactly same as Gauss Jacobi
except a very minute change
the sum is done using updated values of x i.e, x_new
*/

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

const int MAX_SIZE = 20;

void gauss_seidel(double A[][MAX_SIZE], double B[], double x[], int n, int max_iter, double tol) {

    //STEP1: Set initial guess
    double x_new[n];
    for(int i=0; i<n; i++){
        x[i] = 0;
        x_new[i] = 0;
    }
    
    //STEP2: Initialize count and error for 
          // defining break condition
    int count = 0; 
    double error = 1;
    
    //STEP3: Run while loop till convergence
    while(error > tol && count<max_iter){     // While loop runs till max iterations are crossed
                                                // or required accuracy is reached    
        for(int i=0; i<n; i++){            
            double sum = 0;                     // Initialising sum for each row
                
                for(int j=0; j<n; j++){
        
                    if(j!=i){
                        sum = sum + A[i][j]*x_new[j];  
                    }
                
                }
            x_new[i] = (B[i] - sum)/A[i][i];
        
        }

        // Checking for convergence
        double error = 0;

        for(int i = 0; i < n; i++){
            error = error + abs(x[i] - x_new[i]);
        }

        // Check if the required accuracy is achieved
        if(error <= tol){
            cout << "Convergence Reached" << endl;
            printf("Iterations taken: %d \n", count);
            return;
        }

        // updating the solution
        for(int k=0; k<n; k++){
            x[k] = x_new[k];
        }

        // increasing the counter of iterations
        count++;

    }

cout << "Failed to converge within the maximum number of iterations!" << endl;

}

#endif
