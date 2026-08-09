#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    // Brute-Force
    int recursion(int i,int k,int n,vector<int> &nums,vector<int> &dp){
        if(i==n-1) return nums[i];
        if(dp[i]!=-1e5) return dp[i];
        int cost=-1e5;
        for(int j=i+1;j<=min(n-1,i+k);j++){
            int nextCost=nums[i]+recursion(j,k,n,nums,dp);
            cost=max(cost,nextCost);
        }
        return dp[i]=cost;
    }
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n+1,-1e5);
        return recursion(0,k,n,nums,dp);
    }
};

class Solution2{
    //better
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,-1e9);
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int cost=-1e9;
            for(int j=i+1;j<=min(n-1,i+k);j++)
                cost=max(cost,nums[i]+dp[j]);
            dp[i]=cost;
        }
        return dp[0];
    }
};

class Solution3{
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,-1e9);
        dp[n-1]=nums[n-1];
        priority_queue<pair<int,int>> pq;
        pq.push({nums[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            int cost=-1e9;
            while(!pq.empty() && pq.top().second-i>k)
                pq.pop();
            cost=max(cost,nums[i]+pq.top().first);
            dp[i]=cost;
            pq.push({cost,i});
        }
        return dp[0];
    }
};

int main(){

return 0;
}