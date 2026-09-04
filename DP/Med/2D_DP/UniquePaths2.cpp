#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vvint=vector<vector<int>>;
    int dp[101][101];
    int recursion(int i,int j,int n,int m,vvint &obstacleGrid){
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int takeRight=0, takeBottom=0;
        if(j<m-1 && !obstacleGrid[i][j+1]) takeRight=recursion(i,j+1,n,m,obstacleGrid);
        if(i<n-1 && !obstacleGrid[i+1][j]) takeBottom=recursion(i+1,j,n,m,obstacleGrid);
        return dp[i][j]=takeRight+takeBottom;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]) return 0;
        memset(dp,-1,sizeof(dp));
        return recursion(0,0,n,m,obstacleGrid);
    }
};

int main(){

return 0;
}