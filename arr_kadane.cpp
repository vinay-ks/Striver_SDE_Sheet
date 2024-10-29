
#include <bits/stdc++.h>
using namespace std;

#define FOR(I,start, end)  for(int I=start; I<end; I++)

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN;
    long long sum = 0;

    int st=-1, ed=-1, temp_st=0;

    FOR(i, 0, n){

        if(sum==0)  temp_st = i;

        sum = sum + arr[i];

        if(sum>maxi){
            maxi = sum;
            st = temp_st;
            ed = i;
        }

        if(sum<0){
            sum=0;
        }

    }

cout<<st<<" "<<ed;
    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

