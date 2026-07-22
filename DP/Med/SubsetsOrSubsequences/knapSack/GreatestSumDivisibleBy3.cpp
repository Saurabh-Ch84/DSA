#include<iostream>
#include<vector>
#include<climits>
using namespace std;
using vi = vector<int> ;

class Solution {
    int recursion(int i,int n,vi &nums,int rem,vector<vi> &dp){
        if(i>=n) return rem==0 ? rem:INT_MIN;
        if(dp[i][rem]!=-1) return dp[i][rem];
        int notTake=recursion(i+1,n,nums,rem,dp);
        int take=nums[i]+recursion(i+1,n,nums,(rem+nums[i])%3,dp);
        return dp[i][rem]=max(notTake,take);
    }
public:
    int maxSumDivThree(vi & nums) {
        int n=nums.size();
        vector<vi> dp(n,vi(3,-1));
        return recursion(0,n,nums,0,dp);
    }
};

int main(){

return 0;
}