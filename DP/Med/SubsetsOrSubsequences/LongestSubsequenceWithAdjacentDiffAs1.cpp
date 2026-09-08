#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[(int)1e6+2];
public:
    int longestSubseq(vector<int>& arr) {
        int n = arr.size(), maxi = 0;
        memset(dp, 0, sizeof(dp));
        for(int num : arr){
            int prev = dp[num - 1];
            int next = dp[num + 1];
            dp[num] = max(prev, next) + 1;
            maxi = max(maxi, dp[num]);
        }
        return maxi;
    }
};

int main(){

return 0;
}