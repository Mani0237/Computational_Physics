// Problem 4.6 pg 142
#include <iostream> 
#include <cmath> 
#include "thomas_solver_function.h"

using namespace std;
int main(){
    
    int n;  // number of variables or equations
    cout << "Enter the value of n " << endl;
    cin >> n;

    // Allocating memory for Ax = B  
    double A[MAX_SIZE][MAX_SIZE];   // coefficient matrix
    double x[MAX_SIZE];             // solutions of linear system x1, x2, x3
    double B[MAX_SIZE];            // Contains elements of B  
    
    //STEP 1: Read the inputs
    cout << "Enter the elements rowise " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j] ;
        }
        cin >> B[i] ;
        cout << endl; 
    } 

    // Step 2: Perform Gaussian jordan
    tridiagonal_solver(A, B, x, n);

    // Step 3: Print solution
    cout << "Solution:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = " << x[i] << endl;
    } 
    
    return 0;
}