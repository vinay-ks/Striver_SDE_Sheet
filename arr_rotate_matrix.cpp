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
//_______________________________________________

void printMatrix(int arr[][3]){
    FOR(i,0,3){
        FOR(j, 0, 3){
            cout<<arr[i][j]<<" ";
        }
        NL;
    }
}

void hello3(){

    int arr[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int n=3;

    printMatrix(arr);
    NL;

    int rotArr[3][3];

    FOR(i,0,3){
        FOR(j,0,3){
            rotArr[i][j] = arr[n-j-1][i];
        }
    }

    printMatrix(rotArr);

}

void hello4(){
        int arr[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int n=3;

    printMatrix(arr);
    NL;


    FOR(i,0,3){
        FOR(j,0,i){
            swap(arr[i][j], arr[j][i]);
        }
    }

    FOR(i,0,3){
        FOR(j,0,n/2){
            swap(arr[i][j], arr[i][n-1-j]);
        }
    }

 printMatrix(arr);
    NL;
    // printMatrix(rotArr);
}

int main(){
    hello4();

    return 0;
}
