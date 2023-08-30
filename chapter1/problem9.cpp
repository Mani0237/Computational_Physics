// Problem 2.9 page - 55

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double fvx(double alpha, double v_abs, double vx, double g){
    return  - alpha*vx*v_abs;
}

double fx(double vx){
    return vx;
}

double fvy(double alpha, double v_abs, double vy, double g){
    return -g - alpha*vy*v_abs;
}

double fy( double vy){
    return vy;
}

int main(){
    
    double t = 0;
    double dt = 0.1;
    const double g = 9.8 ; //ms^2 
    double vx, vy, x, y, v_abs;
    double kvx1, kvx2, kvx3, kvx4;
    double kx1, kx2, kx3, kx4;
    double kvy1, kvy2, kvy3, kvy4;
    double ky1, ky2, ky3, ky4;
    double theta ;
    double alpha;  // alpha = D/m
    cout << "Enter the value of angle: " << endl; 
    cin >> theta ;
    theta = (theta*(22/7))/180 ;
    double v0 = 650; 
    vx = v0*cos(theta);
    vy = v0*sin(theta); 
    v_abs = sqrt(vx*vx + vy*vy); 
    cout << "Enter the value of alpha: " << endl; 
    cin >> alpha ;   

    ofstream myfile;
    myfile.open("problem9ideal.txt");
    myfile << t << '\t' << x << '\t' << vx << '\t' << y << '\t' << vy << endl;

    while(y > -0.000001){
        kvx1 = dt*fvx(alpha, v_abs, vx, g);
        kvx2 = dt*fvx(alpha, v_abs + kvx1/2, vx, g);
        kvx3 = dt*fvx(alpha, v_abs + kvx2/2, vx, g);
        kvx4 = dt*fvx(alpha, v_abs + kvx3, vx, g);
        vx = vx + kvx1/6 + kvx2/3 + kvx3/3 + kvx4/6 ;

        kx1 = dt*fx(vx);
        kx2 = dt*fx(vx + kx1/2);
        kx3 = dt*fx(vx + kx2/2);
        kx4 = dt*fx(vx + kx3);
        x = x + kx1/6 + kx2/3 + kx3/3 + kx4/6 ;

        kvy1 = dt*fvy(alpha, v_abs, vy, g);
        kvy2 = dt*fvy(alpha, v_abs + kvy1/2, vy, g);
        kvy3 = dt*fvy(alpha, v_abs + kvy2/2, vy, g);
        kvy4 = dt*fvy(alpha, v_abs + kvy3, vy, g);
        vy = vy + kvy1/6 + kvy2/3 + kvy3/3 + kvy4/6 ;

        ky1 = dt*fy(vy);
        ky2 = dt*fy(vy + ky1/2);
        ky3 = dt*fy(vy + ky2/2);
        ky4 = dt*fy(vy + ky3);
        y = y + ky1/6 + ky2/3 + ky3/3 + ky4/6 ;

        t = t + dt;
        v_abs = sqrt(vx*vx + vy*vy);
        myfile << t << '\t' << x << '\t' << vx << '\t' << y << '\t' << vy << endl;
    }
    myfile.close();

    return 0;
}