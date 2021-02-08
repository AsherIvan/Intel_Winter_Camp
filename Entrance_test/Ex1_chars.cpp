#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::nothrow;

class Solution {
public:
    int findComplement(int num) {
        int answer(0);

        if (num == 0)
            answer = 1;
        else {
            int count(0);

            for (auto i(num); i > 0; count++)
                i = i >> 1;

            char* Bits = new(nothrow) char[count + 1];

            for (auto i(0); i < count; i++) {
                Bits[count - i - 1] = '0' + !(num % 2);
                num /= 2;
            }

            int base = 2;
            answer = Bits[count - 1] - '0';
            for (auto i(1); i < count; i++) {
                answer = answer + base * (Bits[count - i - 1] - '0');
                base *= 2;
            }

            delete[] Bits;
        }

        return answer;
    }
};

int main()
{
    cout << "Enter the number: ";
    int num;
    cin >> num;
    Solution result;
    cout << "Result = " << result.findComplement(num) << endl;
    system("pause");
    return 0;
}