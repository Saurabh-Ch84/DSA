#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
    void DFS(int i,int j,int n,int m,vector<vector<int>>& grid){
        grid[i][j]=-1;
        for(int k=0;k<4;k++){
            int ii=i+dir[k][0], jj=j+dir[k][1];
            if(!isValid(ii,jj,n,m) || grid[ii][jj]) continue;
            DFS(ii,jj,n,m,grid);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            if(!grid[i][0]) DFS(i,0,n,m,grid);
            if(!grid[i][m-1]) DFS(i,m-1,n,m,grid);
            for(int j=1;j<m-1 && i%(n-1)==0;j++){
                if(!grid[i][j]) DFS(i,j,n,m,grid);
            }
        }
        int count=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!grid[i][j]){
                    DFS(i,j,n,m,grid);
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){

return 0;
}