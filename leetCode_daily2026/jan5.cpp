#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


/*
https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05
*/


long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long sum = 0;
    int negCnt = 0;
    int minAbs = INT_MAX;

    for (auto &row : matrix) {
        for (int x : row) {
            if (x < 0) negCnt++;
            sum += abs(x);
            minAbs = min(minAbs, abs(x));
        }
    }

    if (negCnt & 1)
        sum -= 2LL * minAbs;

    return sum;
}


int main()
{
    // Test case 1
    vector<vector<int>> matrix1 = {{1, -1}, {-1, 1}};
    cout << "Test Case 1: " << maxMatrixSum(matrix1) << endl;

    // Test case 2
    vector<vector<int>> matrix2 = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
    cout << "Test Case 2: " << maxMatrixSum(matrix2) << endl;

    // Test case 3
    vector<vector<int>> matrix3 = {{-1, 0, -1}, {-2, 1, 3}, {3, 2, 2}};
    cout << "Test Case 3: " << maxMatrixSum(matrix3) << endl;

    return 0;
}
