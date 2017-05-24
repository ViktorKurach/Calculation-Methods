#include <iostream>
#include <fstream>
#include <functional>
using namespace std;

#define A 0
#define B 10
#define N 100

double F (double x);
double* solve_linear_system (double** a, double* b, int n);
double* calculate_A (function<double(double)> func, double a, double b, int n);
double* calculate_B (function<double(double)> func, double a, double b, int n,
					 double* vectC, double* vectD);
double* calculate_C (function<double(double)> func, double a, double b, int n);
double* calculate_D (function<double(double)> func, double a, double b, int n,
					 double* vectC);
double calculate_spline (double x, double a, double b, int n,
						 double* vectA, double* vectB, double* vectC, double* vectD);