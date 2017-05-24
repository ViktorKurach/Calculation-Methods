#include <stdio.h>
#include <math.h>
#include "methods.h"

/* Function that is being analysed */
double func (double x) {
	return exp(x) - 3*cos(2*x) + 2*x + 1;
}

/* The first derivative */
double first_deriv (double x) {
	return exp(x) + 6*sin(2*x) + 2;
}

/* The second derivative */
double second_deriv (double x) {
	return exp(x) + 12*cos(2*x);
}

void task1 (double a, double b) {
	double eps = 0.01, x, prev_x = a;
	int n;
	printf("[%1.2f; %1.2f]:\n\n", a, b);
	printf("eps\tRoot\t\tAccuracy rating\n");
	while (eps >= 1e-14) {
		x = iterative_method(func, first_deriv, a, b, eps, &n);
		printf("%.0e\t% e\t%e\n", eps, x, fabs(x - prev_x));
		prev_x = x;
		eps *= 1e-3;
	}
	printf("\n");
}

void task2 (double a, double b) {
	double eps = 0.01, x, prev_x = a;
	int n;
	printf("[%1.2f; %1.2f]:\n\n", a, b);
	printf("eps\tRoot\t\tAccuracy rating\n");
	while (eps >= 1e-14) {
		x = Newton_method(func, first_deriv, second_deriv, a, b, eps, &n);
		printf("%.0e\t% e\t%e\n", eps, x, fabs(x - prev_x));
		prev_x = x;
		eps *= 1e-3;
	}
	printf("\n");
}

void task3 (double a, double b) {
	double eps = 0.01;
	int n_iter, n_newton;
	printf("[%1.2f; %1.2f]:\n\n", a, b);
	printf("eps\tIterative\tNewton's\n");
	while (eps >= 1e-14) {
		iterative_method(func, first_deriv, a, b, eps, &n_iter);
		Newton_method(func, first_deriv, second_deriv, a, b, eps, &n_newton);
		printf("%.0e\t%d\t\t%d\n", eps, n_iter, n_newton);
		eps *= 1e-3;
	}
}