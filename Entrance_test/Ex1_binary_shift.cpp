#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	unsigned int k, tmp;
	cout << "Enter k: ";
	cin >> k;
	tmp = k;

	short count{ 0 };

	if (k == 0)
		count = 1;

	//counting the number of filled bits
	while (tmp > 0) {
		cout << "tmp = " << tmp << endl;
		tmp = tmp >> 1;
		count++;
	}

	k = ~k;

	// changing 1-bit cells to 0-bit cells
	k = k << 32 - count;
	k = k >> 32 - count;

	cout << "k = " << k << endl;

	system("pause");
	return 0;
}