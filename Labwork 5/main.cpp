#include "main.h"

void main() {
	ofstream tbl("table.csv");
	cout << "f = 0.001*exp(x+3)*sin(x) - ln(x)*sin(x/3), [0, " << L << "]" << endl;
	cout << "Using Legendre's polynomial\n" << endl;
	for (int n = 10; n < 100; ++n) {
		double* coeffs = get_polynomial_coeffs(G, 0, 1, EPS, n);
		double LSD = sqrt((integrate([&](double x) {return sqr((G(x) - calculate_polynomial(coeffs, x, n)));}, 0, 1, EPS))/1);
		cout << "N = " << n << ", LSD = " << LSD << endl;
		if (LSD <= 0.01) {
			for (double x = 0; x < L + 0.01; x += 0.01) {
				tbl << x << ";" << calculate_polynomial(coeffs, x/L, n) << ";" <<endl;
			}
			break;
		}
	}
	cout << "\nLSA written to 'table.csv'" << endl;
	getchar();
}