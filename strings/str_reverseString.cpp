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
//================================================================================

void hello3(){

    printf("\n============START==============\n");

    string ans = "asdfgh";
    string temp = "";

    ans.pop_back();

    char ch = 'w';
    cout<<"xx "<<ans +temp<<" xx";


    printf("\n++====+++=== DONE ==++======+++++====\n");
}

int main(){
    hello3();

    return 0;
}