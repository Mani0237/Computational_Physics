/*------------------------------------------------------------------------------------------

> The following code calculates legendre polynomial for x = -1 to 1
  for a given value of n. For doing this, we need to call 
                          Pn(n, m) where 
                                  n is the order of legendre polynomial
                                  m is the number of x points   

> This code calculates value of legendre polynomial for a particular
  value of x. For doing this, we need to call
                          Pnx(K, n, x) where
                                      n is order
                                      x is point of calculation
                                      K is half of n (should be an integer, in case of odd
                                                      value of n, K = (n-1)/2 )    

-------------------------------------------------------------------------------------------*/


#ifndef LEGENDRE_H
#define LEGENDRE_H

#include <iostream>
#include <cmath> 

using namespace std;

double Pnx(int K, int n, double x){

    double sum = 0;
    for(int j = 0; j<=K; j++){
        sum  = sum + ( pow(-1, j)*tgamma(2*n - 2*j + 1)*pow(x, (n - 2*j))) / ( pow(2,n)*tgamma(j+1)*tgamma(n - j +1)*tgamma(n - 2*j + 1) );
    }

    return sum;

}

void Pn(int n, int m){
    
    int K;
    if(n % 2 == 0){
        K = n / 2;
    }
    else{
        K = (n - 1) / 2 ;
    }

    double P;
    double x0 = -1;
    double x = 0.0;
    double dx = 2.0 / m ;

    for(int i = 0; i<=m; i++){
        x = x0 + i * dx;
        P = Pnx(K, n, x);
        cout << x << "\t" << P << endl; 
    }

}

#endif 