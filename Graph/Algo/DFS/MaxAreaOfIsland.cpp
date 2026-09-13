#include<iostream>
#include<vector>
using namespace std;

using vi = vector<int> ;
using vb = vector<bool> ;
using vvc = vector<vector<char>> ;

class Solution {
    bool isValid(int i,int j,int n,int m){
        return (i<n && i>=0 && j<m && j>=0);
    }
    void DFS(int i,int j,int n,int m,vi &di,vi &dj,vector<vb> &visited,vvc &grid){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int i_=i+di[k],j_=j+dj[k];
            if(!isValid(i_,j_,n,m) || visited[i_][j_] || grid[i_][j_]=='0')
                continue;
            DFS(i_,j_,n,m,di,dj,visited,grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vi di={-1,0,1,0},dj={0,1,0,-1};
        vector<vb> visited(n,vb(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    DFS(i,j,n,m,di,dj,visited,grid);
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