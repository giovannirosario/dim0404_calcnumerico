#include <iostream>
#include <math.h>
#include <iomanip>

double calc (int x) {
	if (x == 0) { return 2;}

	double result = 0;
	double xi = calc(x-1);
	result = xi + pow((pow(xi,2) - 2),2); 
	return result;
}

int main () {
	for (int i = 0; i < 10; ++i)
	{
		std::cout << std::fixed << std::setprecision(20) << calc(i) << std::endl;
	}
}