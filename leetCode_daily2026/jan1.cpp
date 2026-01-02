#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
https://leetcode.com/problems/plus-one/description/?envType=daily-question&envId=2026-01-01
*/

vector<int> plusOne(vector<int>& digits) {
    int i = 0;
    int n = digits.size();

    int last = digits[n-1];
    int carry = 0;

    for(auto it=digits.rbegin(); it!=digits.rend(); ++it){
        if(*it != 9){
            *it += 1;
            carry = 0;
            break;
        }
        *it = 0;
        carry = 1; 
    }
    if(carry == 1){
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

vector<int> plusOne_2(vector<int>& digits) {
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        if (*it != 9) {
            ++(*it);
            return digits;
        }
        *it = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}


int main()
{
    // Test case 1
    vector<int> digits1 = {1, 2, 3};
    vector<int> result1 = plusOne(digits1);
    cout << "Test Case 1: ";
    for (int digit : result1) {
        cout << digit << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> result2 = plusOne(digits2);
    cout << "Test Case 2: ";
    for (int digit : result2) {
        cout << digit << " ";
    }
    cout << endl;

    // Test case 3
    vector<int> digits3 = {9};
    vector<int> result3 = plusOne(digits3);
    cout << "Test Case 3: ";
    for (int digit : result3) {
        cout << digit << " ";
    }
    cout << endl;

     // Test case 4
    vector<int> digits4 = {9,9,9};
    vector<int> result4 = plusOne(digits4);
    cout << "Test Case 4: ";
    for (int digit : result4) {
        cout << digit << " ";
    }
    cout << endl;


    return 0;
}
