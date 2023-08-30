// ex- 9.2 pg-307
#include <iostream>
#include <fstream>

using namespace std;
const int maxEntries = 1000; 

void opening_file(string filename, double (&X)[22][maxEntries], double (&Y)[22][maxEntries], int &numEntries){
    
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Failed to open the file." << endl;
    }

    double x, y;

    while (inputFile >> x >> y) {
        if (numEntries >= maxEntries) {
            cout << "Maximum number of entries exceeded." << endl;
            break;
        }

        X[numEntries][0] = x;
        Y[numEntries][0] = y;
        numEntries++;
    }
    inputFile.close(); 

}

int main(){

    double t_max = 10.0;
    double dt = 0.01;
    int steps = t_max/dt;
    double t[steps];
    double X[22][maxEntries];
    double Y[22][maxEntries];
    int numEntries = 0;
    t[0] = 0; 

    opening_file("inputs.txt", X, Y, numEntries);

    for(int i = 0; i < numEntries; i++){

        for(int j = 0; j < steps - 1 ; j++){
            // Updating the solution trajectories
            X[i][j+1] = X[i][j] + dt * X[i][j] * (3 - X[i][j] - 2*Y[i][j]);
            Y[i][j+1] = Y[i][j] + dt * Y[i][j] * (2 - X[i][j] - Y[i][j]);
            
            // Updating the time
            t[j+1] = t[j] + dt;
        }
    
    }

    ofstream myfile;
    myfile.open("output_problem2.txt");

    for(int i = 0; i < numEntries; i++){
        for(int j = 0; j < steps - 1 ; j++){
             // Writing data in a file
             myfile << t[j] << "\t" << X[i][j] << "\t" << Y[i][j] << endl;
            
        }
    
    }

    myfile.close();

    return 0;

}