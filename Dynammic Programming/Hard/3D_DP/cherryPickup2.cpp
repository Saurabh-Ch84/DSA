#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    int recursion(vector<vector<int>> &g,int i,int j1,int j2,int m,int n){
        if(j1<0 || j1>=n || i>=m || i<0 || j2<0 || j2>=n) return -1e6;
        if(i==m-1)
        {
            if(j1==j2) return g[i][j1];
            else return g[i][j1]+g[i][j2];
        }
        int maxCherry=-1e6;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                if(j1==j2) maxCherry=max(maxCherry,g[i][j1]+recursion(g,i+1,j1+dj1,j2+dj2,m,n));
                else maxCherry=max(maxCherry,g[i][j1]+g[i][j2]+recursion(g,i+1,j1+dj1,j2+dj2,m,n));
            }
        }
        return maxCherry;
    }
    int memoization1(vector<vector<int>> &g,int i,int j1,int j2,int m,int n,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=n || i>=m || i<0 || j2<0 || j2>=n) return -1e6;
        if(i==m-1)
        {
            if(j1==j2) return g[i][j1];
            return g[i][j1]+g[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxCherry=-1e6;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int cherries=0;
                cherries=(j1==j2)? g[i][j1]:g[i][j1]+g[i][j2];
                cherries+=memoization1(g,i+1,j1+dj1,j2+dj2,m,n,dp);
                maxCherry=max(cherries,maxCherry);
            }
        }
        return dp[i][j1][j2]=maxCherry;
    }

    int memoization2(vector<vector<int>> &g,int i,int j1,int j2,int m,int n,unordered_map<string,int> &dp){
        if(j1<0 || j2<0 || j1>=n || j2>=n || i>=m) return -1e6;
        if(i==m-1){
            if(j1==j2) return g[i][j1];
            return g[i][j1]+g[i][j2];
        }
        string key=to_string(i)+","+to_string(j1)+","+to_string(j2);
        if(dp.find(key)!= dp.end()) return dp[key];
        int maxCherry=-1e6;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int cherries=0;
                cherries=(j1==j2)? g[i][j1]:g[i][j1]+g[i][j2];
                cherries+=memoization2(g,i+1,j1+dj1,j2+dj2,m,n,dp);
                maxCherry=max(cherries,maxCherry);
            }
        }
        return dp[key]=maxCherry;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        // return recursion(grid,0,0,n-1,m,n); //grid,0th row,0th col,n-1th col

        //memoization using 3D vector
        // vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        // return memoization1(grid,0,0,n-1,m,n,dp);
        unordered_map<string,int> dp;
        return memoization2(grid,0,0,n-1,m,n,dp);
    }
};

int main(){

return 0;
}