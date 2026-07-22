#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int memoization(vector<vector<int>> &g,vector<vector<vector<int>>> &dp,int m,int n,int i1,int i2,int k){
        int j1=k-i1;
        int j2=k-i2;
        if(i1>=m || i2>=m || j1>=n || j2>=n || i1<0|| i2<0|| g[i1][j1]==-1 || g[i2][j2]==-1)
            return -1e6;
        if(k==m+n-2) return g[i1][j1];
        if(dp[k][i1][i2]!=-1) return dp[k][i1][i2];

        int maxCherry=-1e6;
        for(int di1=0;di1<=1;di1++){
            for(int di2=0;di2<=1;di2++){
                int cherries=(i1==i2 && j1==j2)? g[i1][j1]:g[i1][j1]+g[i2][j2];
                cherries+=memoization(g,dp,m,n,i1+di1,i2+di2,k+1);
                if(cherries>maxCherry) maxCherry=cherries;
            }
        }
        return dp[k][i1][i2]=maxCherry;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m+n-1,vector<vector<int>>(m,vector<int>(m,-1)));
        //k=r1+c1=r2+c2;
        int result= memoization(grid,dp,m,n,0,0,0);
        return max(0,result);
    }
};

int main(){

return 0;
}