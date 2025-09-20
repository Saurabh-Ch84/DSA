#include<iostream>
#include<vector>
using namespace std;

class Solution {
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
        bool evenDone=false,oddDone=false;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        int oddStart=max(recursion(0,n,nums,true,false,dp),recursion(0,n,nums,false,false,dp));
        int evenStart=max(recursion(0,n,nums,true,true,dp),recursion(0,n,nums,false,true,dp));
        return max(oddStart,evenStart);
    }
};

int main(){
    Solution s;
    vector<int> nums={9,8,3,1,5,3,3,7,3,6};
    cout<<s.maximumLength(nums);
return 0;
}