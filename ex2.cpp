#include <iostream>
#include <math.h>
#include <iomanip>

#define PRECISION 0.5

double dev_f (double x) {
	return cos(x) - (x * sin(x));
}

int main () {
	std::cout << "0 1" << std::endl;
	double y = 1;

	for (double x = PRECISION; x < 10; x += PRECISION)
	{
		y += dev_f(x - PRECISION) * PRECISION;
		std::cout << x << " " << y << std::endl;

	}

	y = 1;

	for (double x = -PRECISION; x > -10; x -= PRECISION)
	{
		y -= dev_f(x + PRECISION) * PRECISION;
		std::cout << x << " " << y << std::endl;

	}

}