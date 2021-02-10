//C++ Threads
#include <thread>
#include <windows.h>

int num_steps = 100000000;
double step;
const int NUM_THREADS = 4;
double global_sum[NUM_THREADS];

void Pi(int thread_num) {
	double x, sum = 0.0;

	step = 1.0 / (double)num_steps;

	for (int i = thread_num; i < num_steps; i += NUM_THREADS) {
		x = (i + 0.5) * step;
		sum = sum + 4.0 / (1.0 + x * x);
	}

	global_sum[thread_num] += sum;
}

int main()
{
	int i;
	double pi{ 0 };

	//array of threads
	std::thread threads[NUM_THREADS] = { std::thread(Pi,0),
		std::thread(Pi,1), std::thread(Pi, 2), std::thread(Pi, 3) };

	for (i = 0; i < NUM_THREADS; i++) {
		threads[i].join(); // waiting for the threads ending
		pi += global_sum[i] * step;
	}

	printf("%.151f\n%.151f\n", Pi, pi);
	return 0;
}