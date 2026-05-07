#include<iostream>
#include<vector>
using namespace std;

class Solution {
    using vint=vector<int>;
    using ll=long long;
    using vll=vector<ll>;
    using vvll=vector<vll>;
    long long recursion(int i,int n,bool isSkipUsed,vint &nums,vvll &dp){
        if(i>=n-1) return 0;
        if(dp[i][isSkipUsed]!=-1) return dp[i][isSkipUsed];
        ll cost=max(0,1+max(nums[i-1],nums[i+1])-nums[i]);
        if(isSkipUsed) dp[i][isSkipUsed]=cost+recursion(i+2,n,true,nums,dp);
        else{
            ll takeAndSkipNext=cost+recursion(i+3,n,true,nums,dp);
            ll takeAndSkipLater=cost+recursion(i+2,n,false,nums,dp);
            dp[i][isSkipUsed]=min(takeAndSkipNext,takeAndSkipLater);
        }
        return dp[i][isSkipUsed];
    }
public:
    long long minIncrease(vector<int>& nums) {
        int n=nums.size();
        if(n&1){
            ll count=0;
            for(int i=1;i<n-1;i+=2)
                count=count+max(0,1+max(nums[i-1],nums[i+1])-nums[i]);
            return count;
        }
        vvll dp(n,vll(2,-1));
        return min(recursion(1,n,0,nums,dp),recursion(2,n,1,nums,dp));
    }
};

int main(){

return 0;
}