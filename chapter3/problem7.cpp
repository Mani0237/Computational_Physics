// Problem 4.7 pg- 147
// This code solves laplance equation using system of
// equation approach 

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <time.h>
#include "Gauss_jacobi.h"

using namespace std;

void print_solution(double x[], int n){
    for(int i=0; i<n; i++){
        cout << setw(10) << x[i] << endl;
    }
}


int main(){

    int n;  // number of variables or equations
    cout << "Enter the value of n " << endl;
    cin >> n;

    // Allocating memory for Ax = B  
    double A[MAX_SIZE][MAX_SIZE];   // coefficient matrix
    double x[MAX_SIZE];             // solutions of linear system x1, x2, x3
    double B[MAX_SIZE];            // Contains elements of B   
    
    int max_iter = 1e8;
    double tol = 1e-8;

    //STEP 1: Read the inputs
    cout << "Enter the elements rowise " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j] ;
        }
        cin >> B[i] ;
        cout << endl; 
    } 
    
    clock_t start = clock();

    //STEP 2: Call the function
    gauss_jacobi(A, B, x, n, max_iter, tol);

    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Elapsed time: " << elapsed_time << " seconds" << endl;

    // Step 3: Print solution
    cout << "-------------------\n";
    cout << "Solution:" << endl;
    print_solution(x, n);
    cout << "-------------------\n";

    return 0;

}