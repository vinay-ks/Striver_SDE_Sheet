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

//================================================================================

void hello3(){

    printf("\n============START==============\n");

    vector<char> v = {'a', 'f', 'd'};
  
  	// Inserting 'z' at the back
  	v.push_back('z');
  
  	// Inserting 'c' at end
  	v.insert(v.end(), 'c');

    auto it = v.begin();
    it++; it++;
    *it = 'l'; 


  	for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
        


    printf("\n++====+++=== DONE ===+++====++\n");
}

int main(){
    hello3();

    return 0;
}
