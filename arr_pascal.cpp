#include <iostream>
#include <vector>
using namespace std;


#define FOR(I,start, end)  for(int I=start; I<end; I++)
/* In template:
        add macro to For loop

*/

int nCr(int n, int r){
    int res = 1;
    FOR(i, 0, r){
        res = res * (n-i);
        res = res / (i+1);
    }
    return res;
}



void pascalGen_nthRow(int n){
    // vector<int> arr(n,0);

// Print nth row of the pascal Triangle -- Naive Approach
    FOR(i, 1, n+1){
    cout<<nCr(n-1,i-1)<<" ";
    }
    
    cout<<"\n\n";

// Using optimal approach
    int prevEle = 1, ele = 1;
    int r = n, c = 1;
    cout<<ele<<" ";         // 1st element
    FOR(i, 1, n){
        ele = (ele * (r - i)) / i;
        // prevEle = ele;
        cout<<ele<<" ";
    }

}

void pascalGen(int n){
    // Naive Approach  
    FOR(i, 1, n+1){       // i is row number
        FOR(j, 1, i+1){   // j is col number
            cout<< nCr(i-1, j-1);
        }
        cout<<"\n";
    }

    cout<<"^^88^^88^^\n";
    // opt Approach 
    FOR(i, 1, n+1){       // i is row number
        int ele = 1;
        cout<<ele<<" ";
        FOR(j, 1, i){   // j is col number
            ele = (ele*(i-j))/j;
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
}

int main(){

    int n = 5;

    // cout<<"Enter Maadu: ";
    // cin>>n;
    pascalGen_nthRow(n);

cout<<"\n________________________________\n";
    pascalGen(n);
cout<<"\n________________________________\n";
    cout<<"\nPASCAL\n";
    return 0;
}