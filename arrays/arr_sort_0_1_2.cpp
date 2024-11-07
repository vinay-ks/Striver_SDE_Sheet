#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define VI                 vector<int>
#define VVI                vector<vector<int>>
#define FOR(I,start, end)  for(int I=start; I<end; I++)

#define XX     int aaa = 2;

#define NL printf("\n")

void printVector(vector<int> arr){
    for(auto ele : arr){
        cout<< ele << " ";
    }
}

void swapVar(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void samp(vector<int> &arr){
    arr[0] = arr[1];
}

//---------------------------------------------------------------------------------
void hello3(){
    
    // int nums[] = {2,1,0,1,0,1,0,2,0};
    int nums[]={2,0,1};
    int n = 3;

    int low=0, mid=0, high=n-1;

    while(mid <= high){
        switch(nums[mid]){
            case 0:
                swap(nums[low], nums[mid]);
                low++;
                mid++;
                break;            
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid], nums[high]);
                high--;
        }
    }
    FOR(i,0,n){
        cout<<nums[i]<<" ";
    }
    NL;
}

int main(){
    hello3();

    return 0;
}