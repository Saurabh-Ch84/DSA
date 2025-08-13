#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    // int fun(vector<int> &n,int newAns,int start,int end,int jump=0){
    //     if(start>=end) return jump;
    //     for(int i=1;i<=n[start];i++){
    //         int ans=fun(n,newAns,start+i,end,jump+1);
    //         if(ans<newAns) newAns=ans;
    //     }
    //     return newAns;
    // }
    int funMemoDP(vector<int> &n,int start,int end,vector<int>&dp){
        if(start>=end) return 0;
        if(dp[start]!=-1) return dp[start];
        int minJump=1e5;
        for(int i=1;i<=n[start] && start+i<=end;i++)
        {
            int jumps=funMemoDP(n,start+i,end,dp)+1;
            if (jumps < minJump) minJump = jumps;
        }
        return dp[start]=minJump;
    }
public:
    int jump1(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int end=nums.size()-1;
        return funMemoDP(nums,0,end,dp);
    }

    int jump2(vector<int>& nums) {
        int left=0,right=0;
        int jumpCount=0;
        while(right<nums.size()-1)
        {
            int farthest=0;
            for(int i=left;i<=right;i++){
                farthest=max(farthest,nums[i]+i);
            }
            left=right+1;
            right=farthest;
            jumpCount++;
        }
        return jumpCount;
    }


};


int main(){

return 0;
}