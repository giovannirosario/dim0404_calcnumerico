#include <iostream>
#include <math.h>
#include <iomanip>

#define PI 3.14159265

double f (double x) {
	return x * cos(x);
}

int main () {
	for (double x = 2; x >= 1; x -= 0.01)
	{
		std::cout << std::fixed << std::setprecision(20) << f(x) << std::endl;
	}
}