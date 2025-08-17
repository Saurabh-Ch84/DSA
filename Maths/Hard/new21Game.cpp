#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    double memoization(int n,int k,int maxPts,int sum,
                    double p,unordered_map<int,double> &dp)
    {
        if(sum>=k) return (sum<=n)? 1.0 : 0.0;
        if(dp.count(sum)) return dp[sum];
        double ans=0.0;
        for(int i=1;i<=maxPts;i++)
            ans+=p*memoization(n,k,maxPts,sum+i,p,dp);
        return dp[sum]=ans;
    }
public:
    double new21GameA(int n, int k, int maxPts) {
        unordered_map<int,double> dp;
        double probability=memoization(n,k,maxPts,0,1.0/(double)maxPts,dp);
        return probability;
    }

    double new21Game(int n, int k, int maxPts) {
        if(k == 0) return 1.0;
        vector<double> dp(n+1,0.0);
        dp[0]=1.0;
        double windowSum=1.0;
        double probability=0.0;
        for(int i=1;i<=n;i++){
            dp[i]=windowSum/maxPts;
            if(i<k) windowSum+=dp[i];
            else probability+=dp[i];
            if(i>=maxPts && i-maxPts<k) windowSum-=dp[i-maxPts];
        }
        return probability;
    }
};

int main(){

return 0;
}