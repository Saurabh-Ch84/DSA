#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int recursion(int i,int j,int n,vint &nums,vvint &dp){
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==nums[j])
            return 1+recursion(i+1,j+1,n,nums,dp);
        int notTake=recursion(i+1,j+1,n,nums,dp);
        int take=recursion(i,j+1,n,nums,dp);
        return dp[i][j]=max(take,notTake);
    }
public:
    int maxFixedPoints(vint &nums){
        int n=nums.size();
        vvint dp(n+1,vint(n+1,-1));
        return recursion(0,0,n,nums,dp);
    }
};

int main(){

return 0;
}