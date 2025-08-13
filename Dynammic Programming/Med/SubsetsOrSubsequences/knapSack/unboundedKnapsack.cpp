#include<iostream>
#include<vector>
using namespace std;

// User function Template for C++

class Solution {
    int memo(vector<int>& val, vector<int>& wt, vector<vector<int>> &dp, int capacity, int idx) {
        if (idx == 0) {
            // You can take the 0th item as many times as it fits
            int maxItems = capacity / wt[0];
            return maxItems * val[0];
        }
        if (dp[idx][capacity] != -1) return dp[idx][capacity];

        int notTake = memo(val, wt, dp, capacity, idx - 1);
        int take = 0;
        if (capacity >= wt[idx])
            take = val[idx] + memo(val, wt, dp, capacity - wt[idx], idx); // Note: idx, not idx-1

        return dp[idx][capacity] = max(notTake, take);
    }
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<vector<int>> dp(wt.size(), vector<int>(capacity + 1, -1));
        return memo(val, wt, dp, capacity, wt.size() - 1);
    }
};


int main(){

return 0;
}