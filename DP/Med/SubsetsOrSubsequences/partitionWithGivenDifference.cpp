#include<iostream>
#include<vector>
using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
    int memo(vector<int> &a, vector<vector<int>> &dp, int index, int target) {
        if (index == 0) {
            if (target == 0 && a[0] == 0) return 2; // pick or not pick zero
            if (target == 0 || a[0]==target) return 1;
            return 0;
        }
        if (dp[index][target] != -1) return dp[index][target];
        int notTake = memo(a, dp, index - 1, target) % MOD;
        int take = 0;
        if (target >= a[index]) take = memo(a, dp, index - 1, target - a[index]) % MOD;
        return dp[index][target] = (take + notTake) % MOD;
    }
public:
    int countPartitions(vector<int>& arr, int d) {
        int sum = 0;
        for (int val : arr) sum += val;
        // Check for impossible cases
        if (sum < d || (sum - d) % 2 != 0) return 0;
        int target = (sum - d) / 2;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return memo(arr, dp, n - 1, target);
    }
};


int main(){

return 0;
}