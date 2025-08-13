#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void DFS(vector<vector<char>> &g,int n,int m,int i,int j){
        if(i<0 || j<0 || i>=n || j>=m || g[i][j]!='L') return ;
        g[i][j]='C';
        for(int di=-1;di<=1;di++){
            for(int dj=-1;dj<=1;dj++){
                DFS(g,n,m,i+di,j+dj);
            }
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int islands=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L'){
                    DFS(grid,n,m,i,j);
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