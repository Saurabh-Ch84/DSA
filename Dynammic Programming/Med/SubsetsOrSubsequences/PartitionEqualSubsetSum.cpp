#include<iostream>
#include<vector>
using namespace std;

using vvi = vector<vector<int>> ;
class Solution {
    bool recursion(int i,int n,int target,vector<int> &nums,vvi &dp){
        if(i>=n) return target==0;
        if(dp[i][target]!=-1) return dp[i][target];
        bool notTake=false,take=false;
        notTake=recursion(i+1,n,target,nums,dp);
        if(nums[i]<=target)
            take=recursion(i+1,n,target-nums[i],nums,dp);
        return dp[i][target]=take|notTake;
    }
public:
    bool canPartition1(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int &num: nums) sum+=num;
        if(sum % 2 ==1) return false;
        int target=sum/2;
        vvi dp(n,vector<int>(target+1,-1));
        return recursion(0,n,target,nums,dp);
    }
};

class Solution {
public:
    bool canPartition2(vector<int>& nums) {
        int sum=0;
        for(int &val:nums) sum+=val;
        if(sum%2) return false;
        sum=sum/2;
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            vector<bool> temp(sum+1,false);
            for(int j=0;j<=sum;j++)
            {
                if(j==0) temp[j]=true;
                bool notTake=dp[j];
                bool take=false;
                if(j>=nums[i]) take=dp[j-nums[i]];
                temp[j]=take|notTake;
            }
            dp=temp;
            if(dp[sum]) return true;
        }
        return false;
    }
};

int main(){
    Solution s;
return 0;
}