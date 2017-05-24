#pragma once

#include <stdio.h>
#include <math.h>

#define N 4

void pretty_print (double A[N][N], double B[N]);

int direct_elimination (double A[N][N], double B[N]);
void backward_substitution (double A[N][N], double B[N], double X[N]);
void Gaussian_elimination (double A[N][N], double B[N], double X[N]);

void simple_iteration_method(double A[N][N], double B[N], double X[N]);
void simple_iteration (double A[N][N], double B[N], double X[N]);