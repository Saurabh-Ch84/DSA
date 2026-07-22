#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int recursion(int W, vector<int> &val, vector<int> &wt,int i){
        if (i == 0)
        {
            if (W >= wt[0]) return val[0];
            return 0;
        }
        int notTake=recursion(W,val,wt,i-1);
        int take=0;
        if(W>=wt[i]) take=val[i]+recursion(W-wt[i],val,wt,i-1);
        return max(take,notTake);
    }
    int memo(int W, vector<int> &val, vector<int> &wt,int i,vector<vector<int>> &dp){
        if (i == 0)
        {
            if (W >= wt[0]) return val[0];
            return 0;
        }
        if(dp[i][W]!=-1) return dp[i][W];
        int notTake=0+memo(W,val,wt,i-1,dp);
        int take=0;
        if(W>=wt[i]) take=val[i]+memo(W-wt[i],val,wt,i-1,dp);
        return dp[i][W]=max(take,notTake);
    }
  public:
    int knapsack1(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // return recursion(W,val,wt,wt.size()-1);
        vector<vector<int>> dp(wt.size(),vector<int>(W+1,-1));
        return memo(W,val,wt,wt.size()-1,dp);
    }
    int knapsack2(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<int> dp(W+1,0);
        int n=wt.size();
        for(int i=0;i<n;i++){
            vector<int> temp(W+1,0);
            for(int j=1;j<=W;j++){
                int notTake=dp[j];
                int take=0;
                if(j>=wt[i]) take=val[i]+dp[j-wt[i]];
                temp[j]=max(take,notTake);
            }
            dp=temp;
        }
        return dp[W];
    }
    int knapsack3(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<int> dp(W+1,0);
        int n=wt.size();
        for(int i=0;i<n;i++){
            for(int j=W;j>=wt[i];j--){
                int notTake=dp[j];
                int take=0;
                if(j>=wt[i]) take=val[i]+dp[j-wt[i]];
                dp[j]=max(take,notTake);
            }
        }
        return dp[W];
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) { //this is knapsack with infinite elements
        // code here
        // vector<vector<int>> dp(wt.size(),vector<int>(capacity+1,-1));
        // return memo(val,wt,dp,capacity,wt.size()-1);
        
        vector<int> dp(capacity+1,0);
        int n=wt.size();
        for(int i=0;i<n;i++){
            for(int j=wt[i];j<=capacity;j++)
                dp[j]=max(dp[j],dp[j-wt[i]]+val[i]);
        }
        return dp.back();
    }
};

int main(){

return 0;
}