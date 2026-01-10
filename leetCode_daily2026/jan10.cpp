#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/?envType=daily-question&envId=2026-01-10
*/

int minimumDeleteSum(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // dp[i][j] = max ASCII sum of common subsequence
    // between s1[0..i-1] and s2[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + (int)s1[i - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int totalSum = 0;
    for (char c : s1) totalSum += c;
    for (char c : s2) totalSum += c;

    // Minimum delete sum
    return totalSum - 2 * dp[n][m];
}


int main()
{
    // Test Case 1: s1 = "sea", s2 = "eat" -> Output: 231
    string s1_1 = "sea";
    string s2_1 = "eat";
    cout << "Test Case 1: " << minimumDeleteSum(s1_1, s2_1) << endl;

    // Test Case 2: s1 = "delete", s2 = "leet" -> Output: 403
    string s1_2 = "delete";
    string s2_2 = "leet";
    cout << "Test Case 2: " << minimumDeleteSum(s1_2, s2_2) << endl;
    
    return 0;
}
