#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


/*
https://leetcode.com/problems/maximal-rectangle/?envType=daily-question&envId=2026-01-11
*/

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int n = heights.size();
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currHeight = (i == n) ? 0 : heights[i];

        while (!st.empty() && currHeight < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();

            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> height(cols, 0);
    int ans = 0;

    for (int i = 0; i < rows; i++) {
        // DP: build histogram heights
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }

        // Histogram max rectangle
        ans = max(ans, largestRectangleArea(height));
    }

    return ans;
}


int main()
{
    // Test Case 1: Standard example -> Output: 6
    vector<vector<char>> matrix1 = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << "Test Case 1: " << maximalRectangle(matrix1) << endl;

    // Test Case 2: Single '0' -> Output: 0
    vector<vector<char>> matrix2 = {{'0'}};
    cout << "Test Case 2: " << maximalRectangle(matrix2) << endl;

    // Test Case 3: Single '1' -> Output: 1
    vector<vector<char>> matrix3 = {{'1'}};
    cout << "Test Case 3: " << maximalRectangle(matrix3) << endl;

    return 0;
}
