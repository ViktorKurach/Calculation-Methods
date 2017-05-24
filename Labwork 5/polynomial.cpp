#include "main.h"

double Legendre (double x, double n) {
	double Pnplus1, Pn = x, Pnminus1 = 1;
	double i = 1;
	if (n == 0) return 1;
	while (i < n) {
		Pnplus1 = ((2 * i + 1) / (i + 1))*x*Pn - (i / (i + 1))*Pnminus1;
		Pnminus1 = Pn;
		Pn = Pnplus1;
		i += 1;
	}
	return Pn;
}

double* get_polynomial_coeffs (function<double(double)> func, double a, double b, double eps, int m) {
	double** A = new double*[m+1];
	for (int i = 0; i < m+1; ++i)
		A[i] = new double[m+1];
	double* B = new double[m+1];
	for (int i = 0; i < m+1; ++i) {
		for (int j = 0; j < m+1; ++j)
			A[i][j] = integrate([&](double x) {return Legendre(x, i) * Legendre(x, j); }, a, b, eps);
		B[i] = integrate([&](double x) {return Legendre(x, i) * func(x); }, a, b, eps);
	}
	return solve_linear_system(A, B, m+1);
}

double calculate_polynomial (double* coeffs, double x, int m) {
	double res = 0;
	for (int i = 0; i < m+1; ++i)
		res += coeffs[i]*Legendre(x, i);
	return res;
}