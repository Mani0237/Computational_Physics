// Problem 3.1 pg - 73

#include <iostream>
#include <cmath>

using namespace std;

double cube_root(double x, double R){
    return (1/3.0)*(x + R/x);
}

double square_root(double x, double R){
    return 0.5*(x + R/x);
}

double err(double x, double x0){
    return abs(x-x0);
}

int main(){
    
    double R;            // number whose root is to be calculated
    cout << "Enter the number whose root is to be calculated" << endl;
    cin >> R; 
    double x = R;
    double x0 = 2;
    int n = 0;           // step number
    double tol = 1e-6;   // tolerance level
    double error = err(x,x0);

    while(error > tol){
          x = cube_root(x0, R);
          n = n+1;
          error = err(x, x0);
          x0 = x; 
          printf("Iteration: %d || Root: %f || Error: %f\n", n, x, error);
    }


    return 0;
}
