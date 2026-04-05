#include<iostream>
#include<vector>
#include<stack>
using namespace std;

using vint = vector<int>;

class Solution1 {
    void getNSE(vint &nse, vint &arr, int n) {
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if (!s.empty()) nse[i] = s.top();
            s.push(i);
        }
    }
    
public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        vint nse(n, n);
        getNSE(nse, arr, n);
        
        long long sum = 0;
        int MOD = 1e9 + 7;
        
        // 1D DP array! dp[i] represents the sum of mins of all subarrays starting at i
        vector<long long> dp(n + 1, 0);
        
        // Loop backwards so we don't even need recursion! 
        // dp[nse[i]] will already be calculated by the time we need it.
        for (int i = n - 1; i >= 0; i--) {
            long long count = nse[i] - i;
            
            // Your exact recursive formula, translated to O(1) DP lookups
            dp[i] = (count * arr[i] + dp[nse[i]]) % MOD;
            
            sum = (sum + dp[i]) % MOD;
        }
        
        return sum;
    }
};

#include <vector>
#include <stack>

using namespace std;
using vint = vector<int>;

class Solution2 {
    // Left side: strictly greater (>)
    void getNSE(vint &nse, vint &arr, int n) {
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            // FIX 1: Change >= to > to handle duplicates
            while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
            if (!s.empty()) nse[i] = s.top();
            s.push(i);
        }
    }
    
    // Right side: greater than or equal (>=)
    void getPSE(vint &pse, vint &arr, int n) {
        stack<int> s;
        for (int i = 0; i < n ; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if (!s.empty()) pse[i] = s.top();
            s.push(i);
        }
    }
    
public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        vint nse(n, n), pse(n, -1);
        getNSE(nse, arr, n);
        getPSE(pse, arr, n);
        
        long long sum = 0;
        int MOD = 1e9 + 7;
        
        for(int i = 0; i < n; i++) {
            // FIX 2: Use long long to prevent overflow during multiplication
            long long left_count = i - pse[i];
            long long right_count = nse[i] - i;
            long long total_subarrays = left_count * right_count;
            
            // Apply modulo at each multiplication and addition step
            long long contribution = (total_subarrays * arr[i]) % MOD;
            sum = (sum + contribution) % MOD;
        }
        
        return sum;
    }
};

int main(){

return 0;
}