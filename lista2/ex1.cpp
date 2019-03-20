#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath> 
#include <math.h>

#define IT_MAX 100
#define PRECISION 5

double f(double x) {
    return (pow(x,3) - (1.7 * pow(x,2)) - (12.78*x) - 10.08);
}

double f_1(double x) {
    return (3*pow(x,2) - 3.4*x - 12.78);
}

double g(double x) {
    return (pow(x,3) - (1.7 * pow(x,2)) - (12.78*x) - 10.08) + x;
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

double fixedPoint(double p0, int &it_count) {
    double p = g(p0);
    std::cout << p << std::endl;
    
    it_count++;
    if (it_count >= IT_MAX) return p;

    if (std::abs(p-p0) < 1/pow(10,PRECISION)) {
        return p;
    } else {
        fixedPoint(p, it_count);
    }
}

double newton(double p0, int &it_count) {
    double p = p0 - (f(p0) / f_1(p0));

    it_count++;
    if (it_count >= IT_MAX) return p;

    if (std::abs(p-p0) < 1/pow(10,PRECISION)) {
        return p;
    } else {
        newton(p, it_count);
    }

}

int main () {
    int it_count = 0;
    std::cout << std::fixed << std::setprecision(PRECISION) << bisection(-4,-1.57,it_count);
    std::cout << " took " << it_count << " iterations" << std::endl;

    it_count = 0;
    std::cout << std::fixed << std::setprecision(PRECISION) << bisection(-1.57,2.7,it_count);
    std::cout << " took " << it_count << " iterations" << std::endl;

    it_count = 0;
    std::cout << std::fixed << std::setprecision(PRECISION) << bisection(2.7,5,it_count);
    std::cout << " took " << it_count << " iterations" << std::endl;

    it_count = 0;
    std::cout << std::fixed << std::setprecision(PRECISION) << newton(-1.57,it_count);
    std::cout << " took " << it_count << " iterations" << std::endl;

     it_count = 0;
    std::cout << std::fixed << std::setprecision(PRECISION) << newton(2.7,it_count);
    std::cout << " took " << it_count << " iterations" << std::endl;

     it_count = 0;
    std::cout << std::fixed << std::setprecision(PRECISION) << newton(-1.2,it_count);
    std::cout << " took " << it_count << " iterations" << std::endl;
}