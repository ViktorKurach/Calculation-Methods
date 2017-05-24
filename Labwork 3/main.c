#include "tasks.h"

void main () {
	double A[N][N] = {10, 2, 0, 19, 2, 24, 7, 14, 10, 14, 29, 4, 20, 13, 3, 8};
	double eqA[N][N] = {28, -9, -4, 13, 2, 24, 7, 14, 10, 14, 29, 4, 10, 2, 0, 19};
	double B[N] = {44, 114, 108, 61};
	double eqB[N] = {-9, 114, 108, 44};
	double X[N] = {0};
	Gaussian_elimination(A, B, X);
	simple_iteration(eqA, eqB, X);
}