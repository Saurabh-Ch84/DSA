#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(int i,int j,int m,int n){
        return (i<m && j<n && i>=0 && j>=0);
    }
    void DFS(int i,int j,int m,int n,vector<int> &di,vector<int> &dj,
            vector<vector<bool>> &visited,vector<vector<int>>& grid){
                visited[i][j]=1;
                for(int k=0;k<4;k++){
                    int i_=i+di[k], j_=j+dj[k];
                    if(!isValid(i_,j_,m,n) || !grid[i_][j_] || visited[i_][j_])
                        continue;
                   DFS(i_,j_,m,n,di,dj,visited,grid);
                }
            }
    int getNumberOfComps(int m,int n,vector<vector<int>>& grid){
        int numberOfComps=0;
        vector<int> di={-1,0,1,0}, dj={0,1,0,-1};
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && !visited[i][j]){
                    DFS(i,j,m,n,di,dj,visited,grid);
                    numberOfComps++;
                }
            }
        }
        return numberOfComps;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int numberOfIslands=getNumberOfComps(m,n,grid);
        if(numberOfIslands!=1) return 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    int newNumberOfIslands=getNumberOfComps(m,n,grid);
                    if(newNumberOfIslands!=1){
                        grid[i][j]=0;
                        return 1;
                    }
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};

int main(){

return 0;
}