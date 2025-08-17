#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        // First element of AP
        int a = arr[0];
        // Common difference, derived from (last - first)/n
        // because total number of terms in actual AP is n+1
        int diff = (arr[1] - arr[0]);
        if (arr.size() > 2) {
            int diff2 = arr[2] - arr[1];
            if (diff != diff2) {
                // difference would be the one occurring more than once, 
                // for example here choose the correct diff by checking arr[2]-arr[3]
                diff = (arr[2] - arr[3] == diff) ? diff : diff2;
            }
        }
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int expected = a + mid * diff;
            if (arr[mid] == expected) {
                // so far correct, move right
                low = mid + 1;
            } else {
                // mismatch found, missing is at or before mid
                high = mid - 1;
            }
        }
        // At the end, `low` points to missing index
        return a + low * diff;
    }
};



int main(){

return 0;
}