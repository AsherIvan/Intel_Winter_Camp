#include <omp.h>

int main()
{
	int x = 0;
#pragma omp parallel shared(x)
	{
#pragma omp critical // #pragma omp atomic
		x = x + 1;
	}
	return 0;
}