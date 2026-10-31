#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mod=1e9+7;
    int dp[500+1][500+1][2+1];
    int recursion(int i,int j,int k,int m,int n,vector<vector<int>>& grid){
        if(i>=m || j>=n) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(i==m-1 && j==n-1) return 1;
        int goRight=0, goDown=0;
        if(!grid[i][j]){
            goRight=recursion(i,j+1,1,m,n,grid)%mod;
            goDown=recursion(i+1,j,2,m,n,grid)%mod;
        }
        else{
            if(k==1) goDown=recursion(i+1,j,2,m,n,grid)%mod;
            else goRight=recursion(i,j+1,1,m,n,grid)%mod;
        }
        return dp[i][j][k]=(goRight+goDown)%mod;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return recursion(0,0,0,m,n,grid);
    }
};

int main(){

return 0;
}