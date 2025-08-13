#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution1 {
    int memoization(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int minMultiplication=1e9;
        for(int k=i;k<j;k++){
            int currentMin=arr[i-1]*arr[k]*arr[j]+memoization(arr,i,k,dp)+memoization(arr,k+1,j,dp);
            minMultiplication=min(currentMin,minMultiplication);
        }
        return dp[i][j]=minMultiplication;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return memoization(arr,1,n-1,dp);
        int dp[n][n];
        for(int i=1;i<n;i++) dp[i][i]=0;
        for(int i=n-1;i>=1;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                int minMultiplication=1e9;
                for(int k=i;k<j;k++)
                {
                    int currentMin=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    minMultiplication=min(currentMin,minMultiplication);
                }
                dp[i][j]=minMultiplication;
            }
        }
        return dp[1][n-1];
    }
};

class Solution2 {
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
        vector<vector<int>> dp(c+2,vector<int>(c+2,-1));
        return recursion(cuts,1,c,dp);
    }

    int minCostDP(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        // dp[i][j] = min cost to cut stick from cuts[i-1] to cuts[j+1] (cuts between i and j)
        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

        // length is the length of the current segment (number of cuts between i and j)
        for(int len = 1; len <= c; ++len) {
            for(int i = 1; i + len - 1 <= c; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for(int k = i; k <= j; ++k) {
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        return dp[1][c];
    }
};

class Solution3 {
    int memoization(vector<int> &nums,int i,int j,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int currentMax=nums[i-1]*nums[k]*nums[j+1]+memoization(nums,i,k-1,dp)+memoization(nums,k+1,j,dp);
            maxi=max(currentMax,maxi);
        }
        return dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return memoization(nums,1,n,dp);
    }
};

class Solution {
    int memoization(string &s,int i,int j,int isTrue,vector<vector<vector<int>>> &dp)
    {
        if(i>j) return 0;
        if(i==j)
        {
            if(isTrue) return s[i]=='T';
            return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        int ways=0;
        for(int k=i+1;k<=j-1;k+=2)
        {
            int leftTrue=memoization(s,i,k-1,1,dp);
            int leftFalse=memoization(s,i,k-1,0,dp);
            int rightTrue=memoization(s,k+1,j,1,dp);
            int rightFalse=memoization(s,k+1,j,0,dp);
            if(s[k]=='&')
            {
                if(isTrue) ways+=leftTrue*rightTrue;
                else ways+=leftFalse*rightFalse+leftFalse*rightTrue+leftTrue*rightFalse;
            }
            else if(s[k]=='|')
            {
                if(isTrue) ways+=leftTrue*rightTrue+leftFalse*rightTrue+leftTrue*rightFalse;
                else ways+=leftFalse*rightFalse;
            }
            else
            {
                if(isTrue) ways+=leftTrue*rightFalse+leftFalse*rightTrue;
                else ways+=leftFalse*rightFalse+leftTrue*rightTrue;
            }
        }
        return dp[i][j][isTrue]=ways;
    }
  public:
    int countWays(string &s) {
        // code here
        int n=s.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return memoization(s,0,n-1,true,dp);
    }
};
int main(){

return 0;
}