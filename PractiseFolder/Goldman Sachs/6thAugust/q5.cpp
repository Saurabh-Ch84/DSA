#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    int memoization(int n,int k,vector<vector<int>> &dp){
        if(k<=1 || n==1) return k;
        if(dp[n][k]!=-1) return dp[n][k];
        int minSteps=INT_MAX;
        for(int i=1;i<=k;i++){
            int tempSteps=1+max(memoization(n-1,i-1,dp),memoization(n,k-i,dp));
            minSteps=min(minSteps,tempSteps);
        }
        return dp[n][k]=minSteps;
    }

    int tabulation(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 1e9));

        for(int i=0; i<=n; i++) dp[i][0] = 0;      // zero floors
        for(int i=1; i<=k; i++) dp[1][i] = i;      // one egg

        for(int i=2; i<=n; i++){
            for(int j=1; j<=k; j++){
                for(int x=1; x<=j; x++){
                    int breakCase = dp[i-1][x-1];
                    int noBreakCase = dp[i][j-x];
                    int tempSteps = 1 + max(breakCase, noBreakCase);
                    dp[i][j] = min(dp[i][j], tempSteps);
                }
            }
        }
        return dp[n][k];
    }
  public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k) {
        // vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        // return memoization(n,k,dp);
        return tabulation(n,k);
    }
};

int main(){
    Solution s;
    cout<<s.eggDrop(3,12);
return 0;
}