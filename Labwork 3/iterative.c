#include "tasks.h"

double mnorm_vect (double arr[N]) {
	double res = fabs(arr[0]);
	int i;
	for (i = 0; i < N; ++i)
		if (fabs(arr[i]) > res) res = fabs(arr[i]);
	return res;
}

double mnorm_matr (double A[N][N]) {
	double sums[N];
	int i, j;
	for (i = 0; i < N; ++i) {
		sums[i] = 0;
		for (j = 0; j < N; ++j) sums[i] += fabs(A[i][j]);
	}
	return mnorm_vect(sums);
}

void simple_iteration_method (double A[N][N], double B[N], double X[N]) {
	double alpha[N][N], beta[N];
	double oldX[N], Xdiffer[N];
	double pivot, q, eps = 0.01;
	int i, j;
	for (i = 0; i < N; ++i) {
		pivot = A[i][i];
		for (j = 0; j < N; ++j) {
			if (i == j) alpha[i][j] = 0;
			else alpha[i][j] = A[i][j] / pivot;
		}
		beta[i] = B[i] / pivot;
	}
	for (i = 0; i < N; ++i) X[i] = beta[i];
	do {
		for (i = 0; i < N; ++i) oldX[i] = X[i];
		for (i = 0; i < N; ++i) {
			X[i] = beta[i];
			for (j = 0; j < N; ++j) X[i] = X[i] - alpha[i][j] * oldX[j];
		}
		for (i = 0; i < N; ++i) Xdiffer[i] = X[i] - oldX[i];
		q = mnorm_matr(alpha);
	} while (mnorm_vect(Xdiffer) > (1.0-q)/q*eps);
}