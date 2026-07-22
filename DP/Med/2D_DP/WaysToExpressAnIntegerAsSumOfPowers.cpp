#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    const int MOD=1e9+7;

    int memoization(vector<int> &nums,int n,int m,vector<vector<int>> &dp){
        if(n==0) return 1;
        if(m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int take=0;
        int notTake=memoization(nums,n,m-1,dp);
        if(n>=nums[m])
            take=memoization(nums,n-nums[m],m-1,dp);
        return dp[n][m]=(take+notTake)%MOD;
    }

public:

    int numberOfWays(int n, int x) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            int res=1;
            bool flag=true;
            for(int j=1;j<=x;j++){
                if(res>n){
                    flag=false;
                    break;
                }
                res=res*i;
            }
            if(flag) nums.push_back(res);
        }
        int m=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(m,-1));
        return memoization(nums,n,m-1,dp);
    }
};

int main(){
    Solution s;
    cout<<s.numberOfWays(10,1)<<endl;
    cout<<s.numberOfWays(20,2)<<endl;
    cout<<s.numberOfWays(100,4)<<endl;
return 0;
}