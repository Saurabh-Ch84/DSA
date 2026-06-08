#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        // 1. Base case: If only one element exists, we must return it
        if (n == 1) return arr[0]; 
        long long product = 1;
        int mod = 1e9 + 7, maxNeg = -1e9, maxNegIdx = -1;
        int negCount = 0, zeroCount = 0;
        // 2. First Pass: Gather statistics
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                zeroCount++;
            } else if (arr[i] < 0) {
                negCount++;
                if (arr[i] > maxNeg) {
                    maxNeg = arr[i];
                    maxNegIdx = i; // Track index to skip it later
                }
            }
        }
        // 3. Explicit Edge Cases (Removes the need for your max() check at the end)
        if (zeroCount == n || (negCount == 1 && zeroCount == n - 1)) return 0; 
        // Array is all zeros or 
        // Array is all zeros and one negative
        
        // 4. Second Pass: Calculate the product cleanly in one loop
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) continue; // Always skip zeros
            // Skip the single largest negative number if the negative count is odd
            if (negCount % 2 != 0 && i == maxNegIdx) continue;
            product = (product * arr[i]) % mod;
        }
        return (product + mod) % mod; 
    }
};

int main(){

return 0;
}