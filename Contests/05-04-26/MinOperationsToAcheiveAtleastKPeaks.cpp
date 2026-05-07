#include<iostream>
#include<vector>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int recursion(int i,int b,int n,int k,vint &nums,vvint &dp){
        if(i>b) return (k? 1e7: 0);
        if(!k) return 0;
        if(k>(n-i+1)/2) return 1e7;
        if(dp[i][k]!=-1) return dp[i][k];
        int cost=max(0,1+max(nums[(i-1+n)%n],nums[(i+1)%n])-nums[i]);
        int notTake=recursion(i+1,b,n,k,nums,dp);
        int take=cost+recursion(i+2,b,n,k-1,nums,dp);
        return dp[i][k]=min(notTake,take);
    }
        public:
    int minOperations(vint &nums,int k){
        int n=nums.size();
        vvint dp1(n,vint(k+1,-1)), dp2(n,vint(k+1,-1));
        int ans=min(recursion(0,n-2,n,k,nums,dp1),recursion(1,n-1,n,k,nums,dp2));
        return (ans>=1e7 ?-1: ans);
    }
};

int main(){

return 0;
}