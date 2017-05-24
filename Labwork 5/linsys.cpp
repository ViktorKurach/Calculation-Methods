#include "main.h"

void pivoting_forward (double** a, double* b, int n) {
	double r;
	for (int k = 0; k < n-1; ++k) {
		for (int j = k+1; j < n; ++j) {
			r = a[j][k]/a[k][k];
			for (int i = k; i < n; ++i)
				a[j][i] = a[j][i] - r*a[k][i];
			b[j] = b[j] - r*b[k];
		}
	}
}

double* pivoting_backward (double** a, double* b, int n) {
	double* x = new double[n];
	double r, g;
	for (int k = n-1; k >= 0; --k) {
		r = 0;
		for (int j = k+1; j < n; ++j) {
			g = a[k][j] * x[j];
			r = r + g;
		}
		x[k] = (b[k] - r) / a[k][k];
	}
	return x;
}

double* solve_linear_system (double** a, double* b, int n) {
	pivoting_forward(a, b, n);
	return pivoting_backward(a, b, n);
}