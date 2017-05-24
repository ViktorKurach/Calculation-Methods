#include "main.h"

double sqr (double x) {
	return x*x;
}

double ln (double x) {
	if (x <= 0) return 0;
	return log(x);
}

double F (double x) {
	return 0.001*exp(x+3)*sin(x) - ln(x)*sin(x/3);
}

double G (double t) {
	return F(t*L);
}