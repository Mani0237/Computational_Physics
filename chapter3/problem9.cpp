// This code finds inverse of a matrix using 
// the gauss Jordan Method 

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <time.h>
#include "gauss_jordan_inverse.h"

using namespace std;

int main(){

    int n;  // number of variables or equations
    cout << "Enter the value of n " << endl;
    cin >> n;

    // Allocating memory for Ax = B  
    double A[MAX_SIZE][MAX_SIZE];   // Matrix whose inverse is to be found 
    double b[MAX_SIZE][MAX_SIZE];            // Matrix B is the final inverse 
    

    //STEP 1: Read the inputs
    cout << "Enter the elements rowise " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j] ;
        }
    } 
    cout << endl; 

    clock_t start = clock();

    //STEP 2: Call the function
    gauss_jordan_inverse(A, b, n);

    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Elapsed time: " << elapsed_time << " seconds" << endl;

    // Step 3: Print solution
    cout << "----------------------------------------\n";
    cout << "Inverse of the matrix:\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << setw(12) << b[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "----------------------------------------\n";

    return 0;

}