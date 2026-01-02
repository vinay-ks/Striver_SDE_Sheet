#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/?envType=daily-question&envId=2026-01-02
*/

int repeatedNTimes(vector<int>& nums) {
    
    sort(nums.begin(), nums.end());

    int prev = nums[0];
    for(auto it=(nums.begin()+1); it!=nums.end(); ++it)
    {
        if(prev == *it){
            return *it;
        }
        prev = *it;
    }
    return prev;
}

int repeatedNTimes_optimized(vector<int>& nums) {
    for (int k = 1; k <= 3; ++k) {
        for (size_t i = 0; i < nums.size() - k; ++i) {
            if (nums[i] == nums[i + k]) {
                return nums[i];
            }
        }
    }
    return -1;
}

int main()
{
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 3};
    cout << "Test Case 1: " << repeatedNTimes(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {2, 1, 2, 5, 3, 2};
    cout << "Test Case 2: " << repeatedNTimes(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {5, 1, 5, 2, 5, 3, 5, 4};
    cout << "Test Case 3: " << repeatedNTimes(nums3) << endl;

    return 0;
}
