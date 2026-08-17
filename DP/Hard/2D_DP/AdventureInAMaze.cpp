#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mod=1e9+7;
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;
    
    bool isValid(int i,int j,int n){
        return (i>=0 && j>=0 && i<n && j<n);
    }
    
    vector<int> recursion(int i,int j,int n,vvint &grid,vvvint &dp){
        if(i==n-1 && j==n-1) return {1,grid[i][j]};
        if(dp[i][j][0]!=-1 && dp[i][j][1]!=-1) return dp[i][j];
        vector<int> ways={0,0};
        if(grid[i][j]==1 || grid[i][j]==3){
            int i_=i, j_=j+1;
            if(isValid(i_,j_,n)){
                vector<int> right=recursion(i_,j_,n,grid,dp);
                if(right[0]){
                    ways[0]=(ways[0]+right[0])%mod;
                    ways[1]=max(ways[1],right[1]+grid[i][j]);
                }
            }
        }
        if(grid[i][j]==2 || grid[i][j]==3){
            int i_=i+1, j_=j;
            if(isValid(i_,j_,n)){
                vector<int> down=recursion(i_,j_,n,grid,dp);
                if(down[0]){
                    ways[0]=(ways[0]+down[0])%mod;
                    ways[1]=max(ways[1],down[1]+grid[i][j]);
                }
            }
        }
        return dp[i][j]=ways;
    }
  public:
    vector<int> findWays(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        vvvint dp(n,vvint(n,vint(2,-1)));
        return recursion(0,0,n,grid,dp);
    }
};

int main(){

return 0;
}