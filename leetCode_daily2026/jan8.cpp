#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


/*
https://leetcode.com/problems/max-dot-product-of-two-subsequences/?envType=daily-question&envId=2026-01-08
*/

int maxDotProduct_compact(vector<int>& A, vector<int>& B) 
{
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = A[i] * B[j];
            if (i && j) dp[i][j] += max(dp[i - 1][j - 1], 0);
            if (i) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    }
    return dp[n - 1][m - 1];
}

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    vector<vector<int>> dp(n, vector<int>(m));
    int take, prod, skip_i, skip_j;

    for(int i=0; i<n;i++){

        for(int j=0; j<m; j++){

            prod = nums1[i] * nums2[j];

            if(i==0 && j==0){
                dp[i][j] = prod;
            }
            else{
                take = prod;

                if(i>0 && j>0){
                    take = prod + max(0, dp[i-1][j-1]);
                }

                skip_i = INT_MIN;
                if(i>0){
                    skip_i = dp[i-1][j];
                }

                skip_j = INT_MIN;
                if(j>0){
                    skip_j = dp[i][j-1];
                }

                dp[i][j] = max({take, skip_i, skip_j});
            }
        }
    }
    return dp[n-1][m-1];
}


int main()
{
    // Test Case 1: nums1 = [2,1,-2,5], nums2 = [3,0,-6] -> Output: 18
    vector<int> nums1_1 = {2, 1, -2, 5};
    vector<int> nums2_1 = {3, 0, -6};
    cout << "Test Case 1: " << maxDotProduct(nums1_1, nums2_1) << endl;

    // Test Case 2: nums1 = [3,-2], nums2 = [2,-6,7] -> Output: 21
    vector<int> nums1_2 = {3, -2};
    vector<int> nums2_2 = {2, -6, 7};
    cout << "Test Case 2: " << maxDotProduct(nums1_2, nums2_2) << endl;

    // Test Case 3: nums1 = [-1,-1], nums2 = [1,1] -> Output: -1
    vector<int> nums1_3 = {-1, -1};
    vector<int> nums2_3 = {1, 1};
    cout << "Test Case 3: " << maxDotProduct(nums1_3, nums2_3) << endl;

    return 0;
}
