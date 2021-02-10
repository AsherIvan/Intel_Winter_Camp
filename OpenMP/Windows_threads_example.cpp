//Windows Threads
#include <windows.h>

int num_steps = 100000000;
double step;
const int NUM_THREADS = 4;
HANDLE thread_handles[NUM_THREADS];
double global_sum[NUM_THREADS];

void Pi(void* arg) { // informative void pointer
	double x, sum = 0.0;
	int start = *(int*)arg; // thread's number

	step = 1.0 / (double)num_steps;

	for (int i = start; i < num_steps; i += NUM_THREADS) {
		x = (i + 0.5) * step;
		sum = sum + 4.0 / (1.0 + x * x);
	}

	global_sum[start] += sum;
}

int main()
{
	int i;
	double pi;
	DWORD threadID;
	int threadArg[NUM_THREADS];

	for (int i = 0; i < NUM_THREADS; i++)
		threadArg[i] = i;

	//Creating threads by function from windowsAPI
	for (i = 0; i < NUM_THREADS; i++)
		thread_handles[i] = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Pi, (LPVOID)threadArg[i], 0, &threadID);

	//Waiting for all the threads enfing
	WaitForMultipleObjects(NUM_THREADS, thread_handles, TRUE, INFINITE);

	//accumulating results
	for (i = 0; i < NUM_THREADS; i++)
		pi += global_sum[i] * step;

	return 0;
}