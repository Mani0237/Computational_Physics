// Exercise Problem 2.6 pg- 66

#include <iostream>
#include <cmath>

using namespace std;

double fvx(double alpha, double v_abs, double vx, double g){
    return - alpha * vx * v_abs;
}

double fx(double vx){
    return vx;
}

double range(double alpha, double v0, double theta, double g){
    double vx = v0 * cos(theta);
    double vy = v0 * sin(theta);
    double v_abs = sqrt(vx*vx + vy*vy);
    double x = 0, y = 0;
    double dt = 0.01;
    while(y >= 0){
        x = x + vx*dt;
        y = y + vy*dt;
        double v = sqrt(vx*vx + vy*vy);
        double ax = fvx(alpha, v, vx, g) / v;
        vx = vx + ax*dt;
        vy = vy - g*dt;
    }
    return x;
}

double solve(double alpha, double v0, double R, double tol, double g){
    double a = 0, b = M_PI/2;
    while(abs(b-a) > tol){
        double theta = (a+b)/2;
        double x = range(alpha, v0, theta, g);
        if(x < R)
            a = theta;
        else
            b = theta;
    }
    return (a+b)/2;
}

int main(){
     
    const double g = 9.8; // m/s^2
    double alpha = 3.89e-5; // D/m
    double v0 = 650; // m/s
    double R = 42500; // m
    double tol = 1e-6;

    double theta = solve(alpha, v0, R, tol, g);
    double vx = v0 * cos(theta);
    double vy = v0 * sin(theta);
    double v_abs = sqrt(vx*vx + vy*vy);

    cout << "Launch angle: " << theta*180/M_PI << " degrees" << endl;
    cout << "Initial velocity: " << v_abs << " m/s" << endl;
    cout << "Range: " << range(alpha, v0, theta, g) << " m" << endl;

    return 0;
}
