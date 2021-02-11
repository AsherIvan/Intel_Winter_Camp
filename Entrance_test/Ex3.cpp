#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        unsigned short n = matrix.at(0).size();
        unsigned short first{ 0 };
        unsigned short last = n - 1;

        int tmp;

        for (auto i(0); i < n / 2; i++) {
            for (auto j(first); j < last; j++) {
                tmp = matrix.at(first + j).at(last);
                matrix.at(first + j).at(last) = matrix.at(first).at(first + j);
                matrix.at(first).at(first + j) = matrix.at(last - j).at(first);
                matrix.at(last - j).at(first) = matrix.at(last).at(last - j);
                matrix.at(last).at(last - j) = tmp;
                cout << "fuck! j = " << j << endl;
            }
            first++;
            last--;
        }

    }

};

int main()
{
    //vector<vector<int>> matrix = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    vector<vector<int>> matrix = { {1, 2, 3, 4},{ 5, 6, 7, 8},{ 9, 10, 11, 12}, {13, 14, 15, 16 } };

    for (auto i(0); i < matrix.size(); i++) {
        for (auto j(0); j < matrix.at(i).size(); j++)
            cout << matrix.at(i).at(j) << " ";
        cout << endl;
    }

    Solution k;
    k.rotate(matrix);

    for (auto i(0); i < matrix.size(); i++) {
        for (auto j(0); j < matrix.at(i).size(); j++)
            cout << matrix.at(i).at(j) << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}