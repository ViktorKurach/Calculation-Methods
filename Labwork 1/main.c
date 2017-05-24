#include <stdio.h>
#include <math.h>

#define A (-0.8)
#define B 6.9

double my_sinh1 (double x, double eps, double Uk, int *k, double *Rn) {
	double Un = ((*k) == 0) ? x : (x*x/(2*(*k)*(2*(*k)+1))) * Uk;
	(*Rn) = Un/3;
	if ((*Rn) < eps) return Un;
	++(*k);
	return Un + my_sinh1(x, eps, Un, k, Rn);
}

double my_sinh2 (double x, int n, double Uk, int *k, double *Rn) {
	double Un = ((*k) == 0) ? x : (x*x/(2*(*k)*(2*(*k)+1))) * Uk;
	(*Rn) = Un/3;
	if ((*k) == n) return Un;
	++(*k);
	return Un + my_sinh2(x, n, Un, k, Rn);
}

void test (double x) {
	double Rn = 0; int k = 0;
	printf("Test: %e = ", sinh(x) - my_sinh1(x, 1e-8, 0, &k, &Rn));
	Rn = k = 0;
	printf("%e\n\n", sinh(x) - my_sinh2(x, 9, 0, &k, &Rn));
}

void task1 () {
	double f, Rn = 0; int k = 0;
	double x = (B+A)/2, eps = 0.01;
	printf("===== TASK 1 =====\n\n", x);
	printf("Eps\tN\tAbs. Error\tRemainder Term\n\n");
	while (eps >= 1e-14) {
		f = my_sinh1(x, eps, 0, &k, &Rn);
		printf("%.0e\t%d\t% e\t%e\n", eps, k, sinh(x) - f, Rn);
		eps *= 1e-3; Rn = k = 0;
	}
	printf("\n");
}

void task2 () {
	double f, Rn = 0.0; int i, k = 0;
	double h = (B-A)/10, x = A;
	printf("===== TASK 2 =====\n\n");
	printf("X[i]\tAbs. Error\tRemainder Term\n\n");
	for (i = 0; i <= 10; ++i) {
		x = A + h*i;
		f = my_sinh2(x, 9, 0, &k, &Rn);
		printf("% .2f\t% e\t% e\n", x, sinh(x) - f, Rn);
		Rn = 0.0; k = 0;
	}
	printf("\n");
}

void main () {
	test(3.05);
	task1();
	task2();
	getchar();
}