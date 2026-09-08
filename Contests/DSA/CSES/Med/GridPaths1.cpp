#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int solve(int n,vector<vector<int>> &matrix){
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[0][0]=matrix[0][0];
    for(int j=1;j<n;j++){
        if(dp[0][j-1] && matrix[0][j])
            dp[0][j]=1;
        else break;
    }
    for(int i=1;i<n;i++){
        if(dp[i-1][0] && matrix[i][0])
            dp[i][0]=1;
        else break;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][j]) dp[i][j]=(1LL*dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    return dp[n-1][n-1];
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char sign;
            cin>>sign;
            if(sign=='*') matrix[i][j]=0;
            else matrix[i][j]=1;
        }
    }
    cout<<solve(n,matrix);
return 0;
}