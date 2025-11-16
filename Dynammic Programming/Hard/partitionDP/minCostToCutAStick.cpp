#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
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
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        int c=cuts.size();
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return recursion(cuts,1,c,dp);
    }
};


class Solution2 {
    int recursion(int left,int right,vector<int> &cuts,vector<vector<int>> &dp){
        if(right-left<2) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int ans=INT_MAX;
        for(int i=left+1;i<=right-1;i++){
            int cost=cuts[right]-cuts[left];
            int leftCost=recursion(left,i,cuts,dp);
            int rightCost=recursion(i,right,cuts,dp);
            cost=cost+leftCost+rightCost;
            ans=min(ans,cost);
        }
        return dp[left][right]=ans;
    }
  public:
    int minCutCost(int n, vector<int>& cuts) {
        // code here
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int m=cuts.size();
        
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return recursion(0,m-1,cuts,dp);
    }
};

int main(){

return 0;
}