#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;

    int recursion(int i,int j,int k,int m,int n,int q,vvint &coins,vvvint &dp){
        if(dp[i][j][k]!=-1e9) return dp[i][j][k];
        if(i==m-1 && j==n-1){
            if(coins[i][j]<0 && k<q) return 0;
            return coins[i][j];
        }
        // don't use neutralization
        int down=-1e9,right=-1e9;
        if(i<m-1) down=coins[i][j]+recursion(i+1,j,k,m,n,q,coins,dp);
        if(j<n-1) right=coins[i][j]+recursion(i,j+1,k,m,n,q,coins,dp);
        if(coins[i][j]<0 && k<q){
            // use neutralization
            if(i<m-1) down=max(down,recursion(i+1,j,k+1,m,n,q,coins,dp));
            if(j<n-1) right=max(right,recursion(i,j+1,k+1,m,n,q,coins,dp));
        }
        return dp[i][j][k]=max(right,down);
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size(), n=coins[0].size(), q=2;
        vvvint dp(m+1,vvint(n+1,vint(q+1,-1e9)));
        return recursion(0,0,0,m,n,q,coins,dp);
    }
};

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size(), n=coins[0].size(), q=2;
        vvvint dp(m,vvint(n,vint(q+1,-1e9)));
        dp[0][0][0]=coins[0][0];
        if(coins[0][0]<0){
            dp[0][0][1]=0;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                for(int k=0;k<=q;k++){
                    int prevMax=-1e9;
                    if(i>0) prevMax=max(prevMax,dp[i-1][j][k]);
                    if(j>0) prevMax=max(prevMax,dp[i][j-1][k]);
                    if(prevMax!=-1e9){
                        dp[i][j][k]=max(dp[i][j][k],prevMax+coins[i][j]);
                    }
                    if(coins[i][j]<0 && k>0){
                        int prevMaxk1=-1e9;
                        if(i>0) prevMaxk1=max(prevMaxk1,dp[i-1][j][k-1]);
                        if(j>0) prevMaxk1=max(prevMaxk1,dp[i][j-1][k-1]);
                        if(prevMaxk1!=-1e9){
                            dp[i][j][k]=max(dp[i][j][k],prevMaxk1+0);
                        }
                    }
                }
            }
        }
        return *max_element(dp[m-1][n-1].begin(),dp[m-1][n-1].end());
    }
};

class Solution2 {
    using vint=vector<int>;
    int recursion(int n,int k,vint &dp){
        if(dp[n]!=-1) return dp[n];
        if(n==0) return 0;
        if(n==1) return k;
        if(n==2) return k*k;
        return dp[n]=(recursion(n-1,k,dp)+recursion(n-2,k,dp))*(k-1);
    }
  public:
    int countWays(int n, int k) {
        // code here
        vint dp(n+1,-1);
        return recursion(n,k,dp);
    }
};

class Solution {
  public:
    int countWays(int n, int k) {
        // code here
        if(n==1) return k;
        int same=k, different=k*(k-1);
        for(int i=3;i<=n;i++){
            int newSame=different;
            int newDifferent=(same+different)*(k-1);
            same=newSame;
            different=newDifferent;
        }
        return same+different;
    }
};

int main(){

return 0;
}