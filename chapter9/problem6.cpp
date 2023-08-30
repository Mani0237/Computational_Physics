// Ex - 9.6 pg - 323
#include <iostream> 
#include <cmath>
#include <fstream>

using namespace std;

int main(){

    double x ;
    double r = 0.0;

    ofstream myfile;
    myfile.open("result6.txt");

    while(r < 4.0){
        x = 0.5;
        for(int i = 0; i < 200; i++){
            if(i > 50){
                myfile << r << "\t" << x << endl;
            }
            x = r * x * (1 - x);
        }
        r = r + 0.004;
    }

    myfile.close();

    return 0;
}