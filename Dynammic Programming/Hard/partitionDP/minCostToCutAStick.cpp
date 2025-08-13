#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int recursion(vector<int>& cuts,int i,int j,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e8;
        for(int k=i;k<=j;k++)
        {
            int cost=cuts[j+1]-cuts[i-1]+recursion(cuts,i,k-1,dp)+recursion(cuts,k+1,j,dp);
            mini=min(cost,mini);
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return recursion(cuts,1,c,dp);
    }
};

int main(){

return 0;
}