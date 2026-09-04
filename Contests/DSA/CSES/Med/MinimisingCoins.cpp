#include<bits/stdc++.h>
using namespace std;

int inf=1e7;
int recursion(int i,int n,int x,vector<int> &coins,vector<vector<int>> &dp){
    if(i==n) return (x? inf: 0);
    if(dp[i][x]!=-1) return dp[i][x];
    int skip=recursion(i+1,n,x,coins,dp), take=inf;
    if(x>=coins[i]) take=1+recursion(i,n,x-coins[i],coins,dp);
    return dp[i][x]=min(skip,take);
}
int solve(int n,int x,vector<int> &coins){
    vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
    int ans=recursion(0,n,x,coins,dp);
    return (ans>=inf? -1:ans);
}

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
        cin>>coins[i];
    cout<<solve(n,x,coins)<<endl;
return 0;
}