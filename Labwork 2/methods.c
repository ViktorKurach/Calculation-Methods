#include <math.h>
#include "methods.h"

double fi (int deriv_sign, p_func func, double x, double lambda) {
	/* For iterative method */
	return x - lambda * deriv_sign * func(x);
}

double iterative_method (p_func func, p_func first_deriv, double a, double b, double eps, int* n) {
	double m1, M1, lambda, q, x, prev_x = a;
	int i = 0, deriv_sign = 1;
	double f1A = first_deriv(a), f1B = first_deriv(b);
	if (f1A < 0 && f1B < 0) {
		f1A = -f1A;
		f1B = -f1B;
		deriv_sign = -1;
	}
	m1 = (f1A <= f1B) ? f1A : f1B;
	M1 = (f1A == m1) ? f1B : f1A;
	lambda = 1.0 / M1;
	q = 1 - m1/M1;
	while (1) {
		if (i > 0) prev_x = x;
		x = fi(deriv_sign, func, prev_x, lambda);
		++i;
		if (fabs(x - prev_x) <= eps*(1-q)/q) break;
	}
	(*n) = i;
	return x;
}

double Newton_method (p_func func, p_func first_deriv, p_func second_deriv,
					  double a, double b, double eps, int* n) {
	double f1A, f1B, m1, x, prev_x;
	int i = 0;
	if (func(a)*second_deriv(a) > 0) prev_x = a;
	if (func(b)*second_deriv(b) > 0) prev_x = b;
	f1A = first_deriv(a);
	f1B = first_deriv(b);
	m1 = (f1A < f1B) ? f1A : f1B;
	while (1) {
		if (i > 0) prev_x = x;
		x = prev_x - func(prev_x)/first_deriv(prev_x);
		++i;
		if (fabs(func(x))/m1 <= eps) break;
	}
	(*n) = i;
	return x;
}