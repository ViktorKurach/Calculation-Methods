#include "main.h"

void main() {
	ofstream tbl("table.csv");
	cout << "f = 0.001*exp(x+3)*sin(x) - ln(x)*sin(x/3), [" << A << ", " << B << "]" << endl;
	cout << "Calculating natural cubic spline...\n" << endl;
	double* vectA = calculate_A(F, A, B, N);
	double* vectC = calculate_C(F, A, B, N);
	double* vectD = calculate_D(F, A, B, N, vectC);
	double* vectB = calculate_B(F, A, B, N, vectC, vectD);
	for (double x = A; x <= B; x += 0.01)
		tbl << x << ";" << calculate_spline(x, A, B, N, vectA, vectB, vectC, vectD) << ";" << endl;
	cout << "Spline values written to 'table.csv'" << endl;
	getchar();
}