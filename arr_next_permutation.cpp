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

void nextPerm(vector<int>& arr, vector<vector<int>> &res, int currIdx){
    if(currIdx == arr.size()){
        res.push_back(arr);
        return;
    }

    FOR(i, currIdx, arr.size()){
        swapVar(&arr[currIdx], &arr[i]);
        nextPerm(arr, res, currIdx+1);
        swapVar(&arr[currIdx], &arr[i]);
    }
}

void genPerm(vector<int> &arr, vector<vector<int>> &res){
XX
  nextPerm(arr, res, 0);  
}

int main(){

    int n = 5;

    // cout<<"Enter Maadu: ";
    // cin>>n;
    // pascalGen_nthRow(n);

cout<<"\n________________________________\n";
    
    vector<int> arr = {1,2,3};
    // samp(arr);
    printVector(arr);

    VVI res;

    genPerm(arr, res);

    cout<<"\nres Size: "<<res.size()<<"\n";

    for(auto ele : res){
        printVector(ele);
        NL;
    }
NL;
int a1[]={3,1,2};
next_permutation(a1, a1+3);
FOR(i,0,3)
    cout<<a1[i]<<" ";
NL;
cout<<"\n________________________________\n";
    cout<<"\n Next Perrmutation\n";
    return 0;
}