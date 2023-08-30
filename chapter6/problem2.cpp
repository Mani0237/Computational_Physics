// Example 6.3 pg - 225 

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Defining the function whose integral is to be calculated
double f(double phi, double phi_max ){
    double L = 1.0;
    double g = 9.8;
    double phi_M = phi_max*M_PI/180;
    return 4 * sqrt(L / g) * (1 / ( sqrt( 1 - pow(sin(phi_M / 2), 2) * pow(sin(phi), 2) ) ) ) ;

}

// Defining the exact integral value
double y_exact(int phi_max){
    double L = 1.0;
    double g = 9.8;
    double phi_M = phi_max*M_PI/180;
    return 2 * M_PI * sqrt(L/g) * ( 1 + 0.25*pow(sin(phi_M/2), 2) + (9/64)*pow(sin(phi_M/2),4));
}

// function for Simpson 1/3 rule 
void simpson(double f(double, double), int n, double l_lim, double u_lim, int phi_max, double y_exact(int)){

    // Allocating values and size    
    double x[n+1], y[n+1];
    double h = (u_lim - l_lim)/n;
    double y_simp = 0;

    // Defining integral value for first and last element
    y[0] = f(l_lim, phi_max);       
    y[n] = f(u_lim, phi_max);
    y_simp = y[0] + y[n];

    // Filling integral values for all intermediate elements
    for(int i = 1; i<n; i++){
        x[i] = l_lim + i*h;
        if(i % 2 == 0){
            y[i] = 2*f(x[i], phi_max);
        }
        else{
            y[i] = 4*f(x[i], phi_max);
        }
        y_simp = y_simp + y[i];
    }    

    // Applying formula for Simson rule and calculating error
    double result = (1.0/3.0) * h * y_simp;
    double error = abs(result - y_exact(phi_max));

    // Formating the output 
    cout << left << setw(9) << phi_max
         << left << setw(15) << result
         << left << setw(15) << y_exact(phi_max)
         << left << setw(15) << error << endl;

}

// Main function 
int main(){
 
    int n = 20 ; 
    double l = 0.0;
    double u = M_PI / 2 ; 
    int phi_max = 5;
    
    cout << "---------------------------------------------------"  << endl;  
    cout << left << setw(9) << "Phi_M"
         << left << setw(15) << "Numerical T"
         << left << setw(15) << "Exact T"
         << left << setw(15) << "Error" << endl;
    cout << "---------------------------------------------------"  << endl;   

    while(phi_max <= 50){
       simpson(f, n, l, u, phi_max, y_exact); 
       phi_max = phi_max + 5; 
    }

    cout << "---------------------------------------------------"  << endl;  

    return 0; 

}