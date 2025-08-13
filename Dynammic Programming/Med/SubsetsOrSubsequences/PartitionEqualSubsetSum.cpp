#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
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

return 0;
}