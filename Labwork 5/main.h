#pragma once

#include <math.h>
#include <functional>
#include <fstream>
#include <iostream>
using namespace std;

#define L 10		// [A; B] = [0; L]
#define EPS 1e-6	// integration error

double sqr (double x);
double ln (double x);
double F (double x);
double G (double t);

double integrate (function<double(double)> func, double a, double b, double eps);
double* solve_linear_system (double** a, double* b, int n);
double Legendre (double x, double n);
double* get_polynomial_coeffs (function<double(double)> func, double a, double b, double eps, int m);
double calculate_polynomial (double* coeffs, double x, int m);