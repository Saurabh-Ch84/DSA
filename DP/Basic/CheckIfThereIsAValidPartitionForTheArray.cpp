#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[n]=1, dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int curr=nums[i], next=nums[i+1];
            if(curr==next) dp[i]=dp[i+2];
            if(!dp[i] && i<n-2){
                int nextnext=nums[i+2];
                if(curr==next && next==nextnext)
                    dp[i]=dp[i+3];
                else if(curr+1==next && next+1==nextnext)
                    dp[i]=dp[i+3];
            }
        }
        return dp[0];
    }
};

int main(){

return 0;
}