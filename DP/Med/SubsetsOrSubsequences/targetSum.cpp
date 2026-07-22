#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

using vi = vector<int> ;
class Solution {
    int recursion(int i,int n,int target,vi &nums){
        if(i>=n) return target==0;
        int take=recursion(i+1,n,target-nums[i],nums);
        int give=recursion(i+1,n,target+nums[i],nums);
        return take+give;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return recursion(0,n,target,nums);
    }
};

class Solution {
    int recursion(vector<int>& n,int t,int idx){
        if(idx==0){
            if(t==n[0] && n[0]==0) return 2;
            if(t==n[0] || t==-n[0]) return 1;
            return 0;
        }
        int take=0,give=0;
        take=recursion(n,t-n[idx],idx-1);
        give=recursion(n,t+n[idx],idx-1);
        return take+give;
    }
    
    int memo(vector<int>& n,int t,int idx,unordered_map<string,int> &dp){
        if(idx==0){
            if(t==n[0] && n[0]==0) return 2;
            if(t==n[0] || t==-n[0]) return 1;
            return 0;
        }
        string key=to_string(idx)+","+to_string(t);
        if(dp.find(key)!=dp.end()) return dp[key];
        int take=memo(n,t-n[idx],idx-1,dp);
        int give=memo(n,t+n[idx],idx-1,dp);
        return dp[key]=take+give;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // return recursion(nums,target,nums.size()-1);
        // unordered_map<string,int> dp;
        // return memo(nums,target,nums.size()-1,dp);
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum < abs(target) || (sum - target) % 2 != 0) return 0;
        int actualTarget = (sum - target) / 2;
        vector<int> dp(actualTarget + 1, 0);
        dp[0] = 1;
        for (int num : nums){
            for (int j = actualTarget; j >= num; --j)
                dp[j] += dp[j - num];
        }
        return dp[actualTarget];
    }
};

int main(){

return 0;
}