#pragma once

typedef double (*p_func)(double);

double iterative_method (p_func, p_func, double, double, double, int*);
double Newton_method (p_func, p_func, p_func, double, double, double, int*);