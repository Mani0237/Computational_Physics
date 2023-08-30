// Example 7.2 pg - 240

/*-------------------------------------------------------
> The following code calculates Pn(x) for x = -1 to +1 
  for a given n value

> For calculating factorial of n, tgamma(n+1) is used.

> The code calculates the result and the output (x, Pn(x))
  is written in file "legendre_ni.txt"  
--------------------------------------------------------*/

#include <iostream>
#include <cmath> 
#include <fstream>
#include <chrono>

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
    
    ofstream myfile;
    string filename = "legendre_n" + to_string(n) + ".txt"; 
    myfile.open(filename);

    for(int i = 0; i<=m; i++){
        x = x0 + i * dx;
        P = Pnx(K, n, x);
        myfile << x << "\t" << P << endl; 
    }

    myfile.close();

}

int main(){

    int ni[] = {1, 2, 3, 4, 5}; 
    int m = 1000;
    int n_max = sizeof(ni) / sizeof(ni[0]); 
    int n; 

    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i<n_max; i++ ){
        n = ni[i];
        Pn(n, m);
    }
    
    auto end = chrono::high_resolution_clock::now();
    double duration = chrono::duration<double>(end-start).count();
    cout << "Time taken = " << duration << "sec" << endl;

    return 0;

}

