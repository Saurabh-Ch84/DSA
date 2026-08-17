#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    // better to use prefix sum array to avoid calculating sum of subarray every time
    using vint=vector<int>;
    using vvint=vector<vint>;
    int inf=-1e9;
    int recursion(int low,int high,vint &stones,vint &prefixArr,vvint &dp){
        if(low>=high) return 0;
        if(dp[low][high]!=inf) return dp[low][high];
        int left=prefixArr[high]-prefixArr[low];
        int right=prefixArr[high-1]-(low? prefixArr[low-1]:0);
        int removeLeft=left-recursion(low+1,high,stones,prefixArr,dp);
        int removeRight=right-recursion(low,high-1,stones,prefixArr,dp);
        int maxDiff=max(removeLeft,removeRight);
        return dp[low][high]=maxDiff;
    }
public:
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<int> prefixArr(n,0);
        prefixArr[0]=stones[0];
        for(int i=1;i<n;i++)
            prefixArr[i]=prefixArr[i-1]+stones[i];
        vvint dp(n+1,vint(n+1,inf));
        return recursion(0,n-1,stones,prefixArr,dp);
    }
};

class Solution {
    // best solution without prefix sum array
    using vint = vector<int>;
    using vvint = vector<vint>;
    int inf = -1e9;

    int recursion(int low, int high, int total, vint &stones, vvint &dp){
        if(low >= high) return 0;
        if(dp[low][high] != inf) return dp[low][high];
        int left=total-stones[low];
        int right=total-stones[high];
        // the minus sign is because the next player will try to minimize the score of the current player
        int removeLeft  = left - recursion(low+1, high,   total - stones[low],  stones, dp);
        int removeRight = right - recursion(low,   high-1, total - stones[high], stones, dp);
        return dp[low][high] = max(removeLeft, removeRight);
    }

public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        vvint dp(n, vint(n, inf));
        return recursion(0, n-1, totalSum, stones, dp);
    }
};

int main(){

return 0;
}