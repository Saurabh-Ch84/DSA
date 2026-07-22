#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int memoization(vector<int>& values,int i,int j,vector<vector<int>> &dp){
        if(j-i<=1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i+1;k<j;k++){
            int next=(values[i]*values[k]*values[j])+memoization(values,i,k,dp)+memoization(values,k,j,dp);
            mini=min(mini,next);
        }
        return dp[i][j]=mini;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return memoization(values,0,n-1,dp);
    }
};

int main(){

return 0;
}