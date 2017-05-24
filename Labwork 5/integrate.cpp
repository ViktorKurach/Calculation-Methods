#include "main.h"

double trapezium (function<double(double)> func, double a, double b, int n) {
	double sum = 0, y = a, h = (b-a)/n;
	for (int i = 1; i < n; ++i) {
		y += h;
		sum += func(y);
	}
	sum += func(a)/2 + func(b)/2;
	return h*sum;
}

double integrate (function<double(double)> func, double a, double b, double eps) {
	int n = (int)(1 / sqrt(eps));
	double In = trapezium(func, a, b, n);
	double I2n = trapezium(func, a, b, 2*n);
	while (fabs(In-I2n) > 3*eps) {
		n *= 2;
		In = trapezium(func, a, b, n);
		I2n = trapezium(func, a, b, 2*n);
	}
	return I2n;

}