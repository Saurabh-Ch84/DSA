#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    // brute force solution with prefix sum array (memoization)
    using vint=vector<int>;
    int inf=-1e7;
    int recursion(int i,int n,vint &stones,vint &prefixArr,vint &dp){
        if(n-i<=1) return 0;
        if(dp[i]!=inf) return dp[i];
        int maxDiff=inf;
        for(int j=i+1;j<n;j++){
            int sum=prefixArr[j];
            int temp=sum-recursion(j,n,stones,prefixArr,dp);
            maxDiff=max(maxDiff,temp);
        }
        return dp[i]=maxDiff;
    }
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> prefixArr(n,0);
        prefixArr[0]=stones[0];
        for(int i=1;i<n;i++)
            prefixArr[i]=prefixArr[i-1]+stones[i];
        vint dp(n,inf);
        return recursion(0,n,stones,prefixArr,dp);
    }
};

class Solution2 {
    // brute force solution with prefix sum array (tabulation)
    using vint=vector<int>;
    using vvint=vector<vint>;
    int inf=-1e7;
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> prefixArr(n,0);
        prefixArr[0]=stones[0];
        for(int i=1;i<n;i++)
            prefixArr[i]=prefixArr[i-1]+stones[i];

        vint dp(n,inf);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int maxDiff=inf;
            for(int j=i+1;j<n;j++){
                int sum=prefixArr[j];
                int temp=sum-dp[j];
                maxDiff=max(maxDiff,temp);
            }
            dp[i]=maxDiff;
        }
        return dp[0];
    }
};

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int inf=-1e7;
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> prefixArr(n,0);
        prefixArr[0]=stones[0];
        for(int i=1;i<n;i++)
            prefixArr[i]=prefixArr[i-1]+stones[i];

        vint dp(n,inf);
        dp[n-1]=0;
        int suffixMax=prefixArr[n-1]-dp[n-1];
        for(int i=n-2;i>=0;i--){
            int maxDiff=suffixMax;
            dp[i]=maxDiff;
            suffixMax=max(suffixMax,prefixArr[i]-dp[i]);
        }
        return dp[0];
    }
};

int main(){

return 0;
}