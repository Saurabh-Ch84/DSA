#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        vector<long long> dp(n+1,0);
        dp[0]=0, dp[1]=nums[0];
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1])
                dp[i+1]=max(dp[i],dp[i-1]+nums[i]);
            else dp[i+1]=dp[i]+nums[i];
        }
        return dp[n];
    }
};

int main(){

return 0;
}