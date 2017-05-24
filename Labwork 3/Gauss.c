#include "tasks.h"

int direct_elimination (double A[N][N], double B[N]) {
	double pivot, first_multiplier, line[N+1];
	int i, j, k;
	for (k = 0; k < N; ++k) {
		pivot = A[k][k];
		if (pivot == 0) return 1;
		for (i = 0; i < N; ++i) line[i] = A[k][i] / pivot;
		line[N] = B[k] / pivot;
		for (j = 0; j < N; ++j) A[k][j] = line[j];
		B[k] = line[N];
		if (k == N-1) break;
		for (i = k+1; i < N; ++i) {
			first_multiplier = A[i][k];
			for (j = 0; j < N; ++j)
				A[i][j] = A[i][j] - line[j] * first_multiplier;
			B[i] = B[i] - line[N] * first_multiplier;
		}
	}
	return 0;
}

void backward_substitution (double A[N][N], double B[N], double X[N]) {
	int j, k;
	for (k = N-1; k >= 0; --k) {
		X[k] = B[k];
		for (j = N-1; j >= k + 1; --j)
			X[k] = X[k] - A[k][j] * X[j];
	}
}