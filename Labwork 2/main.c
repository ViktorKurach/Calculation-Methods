#include <stdio.h>
#include "tasks.h"

#define A1 -2.0
#define B1 -1.75
#define A2 -1.0
#define B2 -0.81
#define A3 0
#define B3 0.25

void main () {
	printf("===== ITERATIVE METHOD =====\n\n");
	task1(A1, B1);
	task1(A2, B2);
	task1(A3, B3);
	printf("\n===== NEWTON METHOD =====\n\n");
	task2(A1, B1);
	task2(A2, B2);
	task2(A3, B3);
	printf("\n===== COMPARISON =====\n\n");
	task3(A1, B1);
	getchar();
}