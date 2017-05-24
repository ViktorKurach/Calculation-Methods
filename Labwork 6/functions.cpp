#include "main.h"

double ln (double x) {
	if (x <= 0) return 0;
	return log(x);
}

double F (double x) {
	return 0.001*exp(x+3)*sin(x) - ln(x)*sin(x/3);
}