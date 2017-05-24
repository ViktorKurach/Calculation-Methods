#include <stdio.h>
#include <math.h>

#define A 0
#define B 36.0
#define EPS 1e-3

typedef double (*p_func)(double);

double f (double x) {
	return x * (2*cos(x/2) - x/2 * sin(x/2));
}

double F (double x) {
	return x * x * cos(x/2);
}

double get_Simpson_step (double a, double b, double eps) {
	double h, M4 = 43.56363; // calculated using AdvancedGraph
	int n;
	h = pow(180*eps/((b-a)*M4), 0.25);
	n = (int)(b-a)/h;
	if (n % 2 == 1) {
		++n;
		h = (b-a)/n;
	}
	return h;
}

double Simpsons_rule (p_func f, double a, double b, double h) {
	double x = a, sigma1 = 0, sigma2 = 0;
	int i, n = (b-a)/h;
	if (n % 2 == 1) ++n;
	x = a;
	for (i = 1; i < n; ++i) {
		x += h;
		if (i % 2 == 1) sigma1 += f(x);
		else sigma2 += f(x);
	}
	return h/3 * (f(a) + f(b) + 4*sigma1 + 2*sigma2);
}

double refined_calculation (p_func f, double a, double b, double eps, int r, double* h) {
	double old_integral, new_integral;
	int n = (b-a) / pow(eps, 1.0/r);
	if (n % 2 == 1) ++n;
	new_integral = Simpsons_rule(f, a, b, (b-a)/n);
	do {
		old_integral = new_integral;
		n *= 2;
		new_integral = Simpsons_rule(f, a, b, (b-a)/n);
	} while (fabs(new_integral-old_integral) > 3*eps);
	(*h) = (b-a)/n;
	return new_integral;
}

double task1 () {
	double h = get_Simpson_step(A, B, EPS);
	double exact = F(B) - F(A);
	double Simpson = Simpsons_rule(f, A, B, h);
	double delta = fabs(exact - Simpson);
	printf("===== TASK 1 =====\n\n");
	printf("Defined error, eps: %.0e\n", EPS);
	printf("Integration step: %f\n", h);
	printf("Exact integral value: %.10f\n", exact);
	printf("Got error, delta: %e\n\n", delta);
	return delta;
}

void task2 (double delta) {
	double h = 0;
	double Runge = refined_calculation(f, A, B, EPS, 4, &h);
	double error = fabs(F(B) - F(A) - Runge);
	printf("===== TASK 2 =====\n\n");
	printf("Defined error, delta: %e\n", delta);
	printf("Integration step: %f\n", h);
	printf("Got error: %e\n\n", error);
}

void main () {
	task2(task1());
	getchar();
}