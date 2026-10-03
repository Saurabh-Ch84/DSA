#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[100+2][100+2][200+2];
    bool recursion(int i,int j,int k,int n,int m,vector<vector<char>>& grid){
        if(j>=m || i>=n) return 0;
        k=k+(grid[i][j]=='(' ? 1:-1);
        if(k<0) return 0;
        if(i==n-1 && j==m-1) return (k==0);
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        bool right=recursion(i,j+1,k,n,m,grid);
        if(right) return dp[i][j][k]=1;
        bool down=recursion(i+1,j,k,n,m,grid);
        return dp[i][j][k]=down;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return recursion(0,0,0,n,m,grid);
    }
};

int main(){

return 0;
}