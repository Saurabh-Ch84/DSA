#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    int memoization(vector<int> &nums,int i,int j,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int currentMax=nums[i-1]*nums[k]*nums[j+1]+memoization(nums,i,k-1,dp)+memoization(nums,k+1,j,dp);
            maxi=max(currentMax,maxi);
        }
        return dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return memoization(nums,1,n,dp);
    }
};

int main(){

return 0;
}