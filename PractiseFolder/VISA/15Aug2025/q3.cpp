#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(int i,int j,int n,int m){
        return i<n && j<m && i>=0 && j>=0;
    }
    void DFS(vector<vector<char>>& grid,unordered_set<int> &visited,vector<int> &di,
            vector<int> &dj,int i,int j,int n,int m)
    {
        visited.insert(i*m+j);
        for(int k=0;k<di.size();k++){
            int newI=i+di[k],newJ=j+dj[k];
            if(isValid(newI,newJ,n,m) && grid[newI][newJ]=='L' && !visited.count(newI*m+newJ))
                DFS(grid,visited,di,dj,newI,newJ,n,m);
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        unordered_set<int> visited;
        int islands=0;
        
        vector<int> di={0,-1,-1,-1,0,1,1,1};
        vector<int> dj={-1,-1,0,1,1,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L' && !visited.count(i*m+j)){
                    DFS(grid,visited,di,dj,i,j,n,m);
                    islands++;
                }
            }
        }
        return islands;
    }
};

int main(){

return 0;
}