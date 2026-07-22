#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool isPalindrome(string &str,int st,int end,vector<vector<int>> &dp){
        if(dp[st][end]!=-1) return dp[st][end];
        int s=st,e=end;
        while(s<e)
        {
            if(str[s]!=str[e]) return dp[st][end]=false;
            s++,e--;
        }
        return dp[st][end]=true;
    }
    int memoization(string &s,int idx,int n,vector<int> &dp,vector<vector<int>> &dp2){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int mini=1e9;
        for(int k=idx;k<n;k++)
        {
            if(isPalindrome(s,idx,k,dp2))
            {
                int ways=1+memoization(s,k+1,n,dp,dp2);
                mini=min(mini,ways);
            }
        }
        return dp[idx]=mini;
    }
public:
    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        vector<vector<int>> dp2(n,vector<int>(n,-1));
        return memoization(s,0,n,dp,dp2)-1;
    }
};

int main(){

return 0;
}