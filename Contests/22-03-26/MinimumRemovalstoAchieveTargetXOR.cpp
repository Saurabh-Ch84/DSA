#include<iostream>
#include<vector>
#include <cstring>

using namespace std;

class Solution {
    const int inf = 1e9 + 7;
    int dp[51][16384]; 
    
    int recursion(int i, int n, vector<int>& nums, int target, int current_xor) {
        // Base case: If we reached the end, did we hit our target?
        // If yes, 0 more removals needed. If no, return infinity.
        if (i == n) return (current_xor == target) ? 0 : inf;
        if (dp[i][current_xor] != -1) return dp[i][current_xor];
        // Option 1: Take the element (0 cost + future cost)
        int take = recursion(i + 1, n, nums, target, current_xor ^ nums[i]);
        // Option 2: Skip/Remove the element (1 cost + future cost)
        int skip = 1 + recursion(i + 1, n, nums, target, current_xor);
        return dp[i][current_xor] = min(take, skip);
    }

public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        // memset is incredibly fast for initializing raw 2D arrays to -1
        memset(dp, -1, sizeof(dp)); 
        int res = recursion(0, n, nums, target, 0);
        return (res > n) ? -1 : res;
    }
};

int main(){

return 0;
}