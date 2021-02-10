#include <omp.h>

//Works in single thread mode when library omp.h is off and in multi thread mode when it is on
int main()
{
	int num_steps = 100000000;
	const int NUM_THREADS = 4;
	double pi, x, sum = 0.0;
	double step = 1.0 / (double)num_steps;

	//Pi function moves to main

	//Executing parallel process
#pragma omp parallel num_threads(NUM_THREADS) private(x)
#pragma omp for schedule(static, 1) reduction(+:sum)

	for (int i = 0; i < num_steps; i++) {
		x = (i + 0.5) * step;
		sum = sum + 4.0 / (1.0 + x * x);
	}
	pi = sum * step;
	return 0;
}