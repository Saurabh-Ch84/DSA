#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    // efficient in memory
    int recursion(int i,int n,vector<int>& nums,bool currEven,bool prevEven,vector<vector<vector<int>>> &dp){
        if(i==n) return 0;
        if(dp[i][currEven][prevEven]!=-1) return dp[i][currEven][prevEven];
        int notTake=recursion(i+1,n,nums,currEven,prevEven,dp),take=0;
        int need=(currEven)? 0:1;
        if(nums[i]%2==need)
            take=1+recursion(i+1,n,nums,prevEven,currEven,dp);
        return dp[i][currEven][prevEven]=max(take,notTake);
    }
public:
    int maximumLength(vector<int>& nums){
        int n=nums.size(),maxLen=2;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        int oddStart=max(recursion(0,n,nums,true,false,dp),recursion(0,n,nums,false,false,dp));
        int evenStart=max(recursion(0,n,nums,true,true,dp),recursion(0,n,nums,false,true,dp));
        return max(oddStart,evenStart);
    }
};

class Solution2 {
    //MLE
    int memoization(vector<int>& nums,int i,int n,int prev,int mod,vector<vector<vector<int>>> &dp){
        if(i>=n) return 0;
        if(dp[i][prev+1][mod]!=-1) return dp[i][prev+1][mod];
        int notTake=memoization(nums,i+1,n,prev,mod,dp);
        int take=0;
        if(prev==-1 ||(nums[prev]+nums[i])%2==mod)
            take=1+memoization(nums,i+1,n,i,mod,dp);
        return dp[i][prev+1][mod]=max(take,notTake);
    }
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int maxLen=0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n+1,vector<int>(2,-1)));
        maxLen=max(maxLen,memoization(nums,0,n,-1,0,dp));
        maxLen=max(maxLen,memoization(nums,0,n,-1,1,dp));
        return maxLen;
    }
};


class Solution3 {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size(),maxLen=1;
        vector<int> dpModOne(n,1),dpModZero(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int mod=(nums[i]+nums[j])%2;
                if(mod==1) dpModOne[i]=max(dpModOne[i],dpModOne[j]+1);
                else dpModZero[i]=max(dpModZero[i],dpModZero[j]+1);
                maxLen=max({maxLen,dpModOne[i],dpModZero[i]});
            }
        }
        return maxLen;
    }
};

int main(){
    Solution2 s;
    vector<int> nums={9,8,3,1,5,3,3,7,3,6};
    cout<<s.maximumLength(nums);
return 0;
}