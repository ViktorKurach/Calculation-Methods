#include "tasks.h"

void pretty_print (double A[N][N], double B[N]) {
	int i, j;
	for (i = 0; i < N; ++i) {
		printf("[");
		for (j = 0; j < N; ++j) printf(" % 7.2f ", A[i][j]);
		printf(" ][ x%d ]   [ % 7.2f ]\n", i+1, B[i]);
	}
	printf("\n");
}

void Gaussian_elimination (double A[N][N], double B[N], double X[N]) {
	double workA[N][N], workB[N];
	int i, j;
	printf("===== GAUSSIAN ELIMINATION (SCHEME OF SIMPLE DIVISION) =====\n\n");
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) workA[i][j] = A[i][j];
		workB[i] = B[i];
	}
	printf("Original linear system:\n\n");
	pretty_print(workA, workB);
	if (direct_elimination(workA, workB) == 1) {
		printf("Division by zero. Try to swap any two lines\n");
		return;
	}
	printf("Equivalent system:\n\n");
	pretty_print(workA, workB);
	backward_substitution(workA, workB, X);
	for (i = 0; i < N; ++i)
		printf("x%d = %.2f\n", i+1, X[i]);
	printf("\n");
}

void simple_iteration (double A[N][N], double B[N], double X[N]) {
	int i;
	printf("===== METHOD OF SIMPLE ITERATION =====\n\n");
	printf("Linear system adapted for iteration:\n\n");
	pretty_print(A, B);
	simple_iteration_method(A, B, X);
	for (i = 0; i < N; ++i)
		printf("x%d = %.2f\n", i+1, X[i]);
	printf("\n");
}