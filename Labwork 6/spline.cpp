#include "main.h"

double* calculate_A (function<double(double)> func, double a, double b, int n) {
	double* res = new double[n];
	double h = (b - a) / n;
	for (int i = 0; i < n+1; ++i)
		res[i] = func(a+h*i);
	return res;
}

double* calculate_B (function<double(double)> func, double a, double b, int n,
					 double* vectC, double* vectD) {
	double* res = new double[n+1];
	double h = (b - a) / n;
	res[0] = h/2 * vectC[0] - h*h/6 * vectD[0];
	for (int i = 1; i < n+1; ++i)
		res[i] = h/2 * vectC[i] - h*h/6 * vectD[i] + (func(a+i*h)-func(a+(i-1)*h)) / h;
	return res;
}

double** make_matrix_for_C (double a, double b, int n);
double* make_vector_for_C (function<double(double)> func, double a, double b, int n);

double* calculate_C (function<double(double)> func, double a, double b, int n) {
	double* vectC = new double[n-2];
	double* res = new double[n];
	vectC = solve_linear_system(make_matrix_for_C(a, b, n), make_vector_for_C(func, a, b, n), n-1);
	for (int i = 0; i < n-1; ++i) res[i+1] = vectC[i];
	res[0] = 0; res[n] = 0;
	return res;
}

double* calculate_D (function<double(double)> func, double a, double b, int n,
					 double* vectC) {
	double* res = new double[n+1];
	double h = (b - a) / n;
	res[0] = 0;
	for (int i = 1; i < n+1; ++i)
		res[i] = (vectC[i] - vectC[i-1]) / h;
	return res;
}

double calculate_spline (double x, double a, double b, int n,
						 double* vectA, double* vectB, double* vectC, double* vectD) {
	double h = (b - a) / n;
	double xi = a;
	int i;
	for (i = 0; i < n; i++) {
		if (x < xi) break;
		xi += h;
	}
	double dx = (x - xi);
	return vectA[i] + vectB[i] * dx + vectC[i] * dx*dx / 2 + vectD[i] * dx*dx*dx / 6;
}

double** make_matrix_for_C (double a, double b, int n) {
	double** matrix = new double*[n-1];
	for (int i = 0; i < n-1; ++i) matrix[i] = new double[n-1];
	for (int i = 0; i < n-1; ++i)
		for (int j = 0; j < n-1; ++j)
			matrix[i][j] = 0;
	double h = (b - a) / n;
	for (int i = 0; i < n-1; ++i) {
		if (i > 0) matrix[i][i-1] = h;
		matrix[i][i] = 4*h;
		if (i < n-1) matrix[i][i+1] = h;
	}
	return matrix;
}

double* make_vector_for_C (function<double(double)> func, double a, double b, int n) {
	double* vector = new double[n-1];
	double h = (b - a) / n;
	for (int i = 0; i < n-1; ++i)
		vector[i] = 6.0/h * (func(a+(i-1)*h) - 2*func(a+i*h) + func(a+(i+1)*h));
	return vector;
}