#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath> 
#include <math.h>

#define IT_MAX 100
#define PRECISION 5

double f(double t) {
    double s0 = 300;
    double g = 32.17;
    double k = 0.1;
    double m = 0.25;
    double e = 2.71828182846;
    
    return s0 - (((m*g)/k)*t) + ( ((pow(m,2)*g)/(pow(k,2))) * (1 - pow(e,((-k*t)/m))));
}

double bisection(double a, double b, int &it_count) {
    double c = (a+b)/2;
    it_count++;
    if (it_count >= IT_MAX) return c;
    double f_c = round(f(c) * pow(10,PRECISION)) / pow(10,PRECISION);
    
    if(f_c == 0) {
        return c;
    } else {
        if(f(a)*f(c) < 0) {
            bisection(a,c,it_count);
        } else {
            bisection(c,b,it_count);
        }
    }
}


int main () {
    int it_count = 0;
    std::cout << std::fixed << std::setprecision(PRECISION) << bisection(0,20,it_count) << std::endl;
}