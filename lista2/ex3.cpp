#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath> 
#include <math.h>

#define IT_MAX 100
#define PRECISION 5

double x1 = 20;
double x2 = 30;


double f(double h) {
    return (pow(h,4) - (16*pow(h,3)) + (pow((8-h),2) * (pow(30,2) - pow(20,2))));
}   

double g(double h) {
    return (pow(h,4) - (16*pow(h,3)) + (pow((8-h),2) * (pow(20,2) - pow(30,2))));
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
    std::cout << std::fixed << std::setprecision(PRECISION) << bisection(0,10,it_count) << std::endl;

    it_count = 0;
    std::cout << std::fixed << std::setprecision(PRECISION) << bisection(6,20,it_count) << std::endl;

    it_count = 0;
    std::cout << std::fixed << std::setprecision(PRECISION) << bisection(0,50,it_count) << std::endl;

    it_count = 0;
    std::cout << std::fixed << std::setprecision(PRECISION) << bisection(0,-50,it_count) << std::endl;



}