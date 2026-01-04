#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04
*/

int sumFourDivisors(vector<int>& nums) {
    
    int res = 0;
    int count, sum;

    for(int i=0; i<nums.size(); i++){
        count = 0;
        sum = 0;
        for(int j=1; j*j <= nums[i]; j++){
            if(nums[i] % j == 0){
                count++;
                sum += j;

                if(j != (nums[i]/j)){
                    count++;
                    sum += (nums[i]/j);
                }
            }
        }
        if(count == 4){
            res += sum;
        }
    }
    return res;
}


int main()
{
    // Test case 1
    vector<int> nums1 = {21, 4, 7};
    cout << "Test Case 1: " << sumFourDivisors(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {21, 21};
    cout << "Test Case 2: " << sumFourDivisors(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Test Case 3: " << sumFourDivisors(nums3) << endl;

    return 0;
}
