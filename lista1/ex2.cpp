#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>

#define PRECISION 0.05


struct coord
{
	double x;
	double y;
};


double dev_f (double x) {
	return cos(x) - (x * sin(x));
}

void print_pts(std::vector<coord> pts) {
	for(auto i : pts) {
		std::cout << i.x << " " << i.y << std::endl;
	}
}


int main () {


	std::vector <coord> pts;
	coord aux;
	aux.x = 0;
	aux.y = 1;
	pts.push_back(aux);

	double y = 1;

	for (double x = -PRECISION; x > -10; x -= PRECISION)
	{
		y -= dev_f(x + PRECISION) * PRECISION;
		aux.x = x;
		aux.y = y;

		pts.insert(pts.begin(), aux);

	}

	y = 1;

	for (double x = PRECISION; x < 10; x += PRECISION)
	{
		y += dev_f(x - PRECISION) * PRECISION;
		aux.x = x;
		aux.y = y;

		pts.push_back(aux);

	}

	print_pts(pts);
	

}