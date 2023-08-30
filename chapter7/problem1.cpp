// Example 7.1 pg-238

/*-------------------------------------------
> The following code calculates gamma(x) of the number gamma
> This can also be done using tgamma(x) function from cmath library
---------------------------------------------*/

#include <iostream>
#include <cmath>
#include "legendre.h"

using namespace std;

double gamma(double z){
    
    double error = 1e-10;
    double product = 1.0;
    double gamma = 1.0;
    int n = 1;

    while(n < 1e10){
        gamma = product * pow( (1.0 + 1.0 / n), z) / (1 + z/n);
        if (abs(gamma - product) > error){
            product = gamma;
        }
        else{
            break;
        }
        n = n + 1;

    }

    return (1/z) * gamma ; 

}


int main(){

    double z, z1;
    cout << "Enter a number " ;
    cin >> z ;

    z1 = gamma(z);
    printf("Gamma(%f) = %f \t Error = %f \n", z, z1, abs(z1 - tgamma(z)));
    
    return 0;

}
