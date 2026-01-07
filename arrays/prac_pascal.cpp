#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
Link
*/

void print_pascal(vector<vector<int>> res){
    for(auto ele : res){
        for(auto ele2 : ele){
            cout<<ele2<<" ";
        }
        cout<<"\n";
    }
}

// Optimal and better version
long long nCr_opt(int n, int r) {
    r = min(r, n - r);
    long long res = 1;

    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}


int nCr(int n, int r){
    int res = 1;
    for(int i=0; i<r; i++){
        res = res * (n-i);
        res = res / (i+1);
    }

    return res;
}

// O(n^2) time
vector<vector<int>> pascalGen_apprch1(int n)
{
    vector<vector<int>> res;

    for(int i=0; i<n; i++){
        vector<int> row(i+1, 1);
        for(int j=1; j<i; j++){
            row[j] = res[i-1][j-1] + res[i-1][j];
        }
        res.push_back(row);
    }
    return res;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; i++) {
        vector<int> row;
        for (int j = 0; j <= i; j++) {
            row.push_back(nCr(i, j));
        }
        ans.push_back(row);
    }
    return ans;
}




int main()
{
    // Test case 
    int n = 10;
    // vector<vector<int>> res = pascalGen_apprch1(n);
    vector<vector<int>> res = generate(n);

    print_pascal(res);

    printf("nCr : %d \n", nCr(5,2));

    return 0;
}
