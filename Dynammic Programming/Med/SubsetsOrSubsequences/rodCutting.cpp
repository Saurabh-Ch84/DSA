#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    int recursion(vector<int> &price, int idx, int rodTotalSize, vector<vector<int>> &dp) {
        if (idx == 0) return price[0] * rodTotalSize;
        if (dp[idx][rodTotalSize] != -1) return dp[idx][rodTotalSize];
        int notTake = recursion(price, idx - 1, rodTotalSize, dp);
        int take = -1e6;
        int rodLength = idx + 1;
        if (rodTotalSize >= rodLength)
            take = price[idx] + recursion(price, idx, rodTotalSize - rodLength, dp);
        return dp[idx][rodTotalSize] = max(take, notTake);
    }
public:
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return recursion(price, n - 1, n, dp);
    }
};


int main(){

return 0;
}