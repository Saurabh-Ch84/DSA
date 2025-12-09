#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution {
    const int MOD=1e9+7;
    int recursion(int i,int n,int k,vector<int> &nums,vector<int> &dp){
        if(i>=n) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        int maxi=INT_MIN,mini=INT_MAX;
        for(int j=i;j<n;j++){
            maxi=max(maxi,nums[j]);
            mini=min(mini,nums[j]);
            if(maxi-mini<=k){
                int nextAns=recursion(j+1,n,k,nums,dp);
                ans=(ans+nextAns) % MOD;
            }else break;
        }
        return dp[i]=ans;
    }
public:
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return recursion(0,n,k,nums,dp);
    }
};

int main(){

return 0;
}