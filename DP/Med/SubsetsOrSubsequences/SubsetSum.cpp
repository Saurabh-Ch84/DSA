#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool recursion(vector<int> &a,int t,int i){
        if(t==0) return true;
        if(i==0) return (a[i]==t); //very imp
        bool notTake=recursion(a,t,i-1);
        bool take=false;
        if(t>=a[i]) take=recursion(a,t-a[i],i-1);
        return (take||notTake);
    }
    bool memoization(vector<int> &a,int t,int i,vector<vector<int>> &dp){
        if(t==0) return true;
        if(i==0) return (a[i]==t); //very imp
        if(dp[i][t]!=-1) return dp[i][t];
        bool notTake=memoization(a,t,i-1,dp);
        bool take=false;
        if(t>=a[i]) take=memoization(a,t-a[i],i-1,dp);
        return dp[i][t]=(take||notTake);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // return recursion(arr,sum,arr.size()-1);
        vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
        return memoization(arr,sum,arr.size()-1,dp);
    }
};

class Solution2{
    // bool recursion(vector<int> &a, int t, int i) {
    //     if (t == 0) return true;
    //     if (i == 0) return (a[i] == t);
    //     bool notTake = recursion(a, t, i-1);
    //     bool take = false;
    //     if (t >= a[i]) take = recursion(a, t-a[i], i-1);
    //     return (take || notTake);
    // }

    // bool memoization(vector<int> &a, int t, int i, vector<vector<int>> &dp) {
    //     if (t == 0) return true;
    //     if (i == 0) return (a[i] == t);
    //     if (dp[i][t]!=-1) return dp[i][t];
    //     bool notTake = memoization(a, t, i-1, dp);
    //     bool take = false;
    //     if (t >= a[i]) take = memoization(a, t-a[i], i-1, dp);
    //     return dp[i][t] = (take || notTake);
    // }
    
    void print(vector<vector<bool>> &a){
        for(vector<bool> v:a){
            for(bool val:v){
                cout<<val<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
public: 
    bool isSubsetSum(vector<int>& arr, int sum) {
        // return recursion(arr, sum, arr.size()-1);
        // vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        // return memoization(arr, sum, arr.size()-1, dp);
        
        int n=arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        // print(dp);
        dp[0][0]=true;
        // print(dp);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++)
            {
                if(j==0)
                {
                    dp[i][j]=true;
                    continue;
                }
                dp[i][j]=dp[i-1][j]; //not-take
                if (j >= arr[i - 1]) 
                    dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];//take
            }
            if(dp[i][sum]) return true;
            // print(dp);
        }
        // print(dp);ju
        return false;
    }
};

int main(){

return 0;
}