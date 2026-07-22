#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    int recursion(vector<int> &nums, int left, int right, vector<vector<int>> &dp) {
        // no balloons left in this range
        if (left > right) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        int best = 0;
        // try every balloon as the last one to burst
        for (int k = left; k <= right; k++) {
            int coins = nums[left-1] * nums[k] * nums[right+1]
                        + recursion(nums, left, k-1, dp)   // left side
                        + recursion(nums, k+1, right, dp); // right side
            best = max(best, coins);
        }
        return dp[left][right] = best;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // add virtual balloons with value 1 at both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return recursion(nums, 1, n, dp);
    }
};


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