#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    void BFS(vector<vector<int>> &grid,queue<pair<int,int>> &q,int n,int m){
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first,col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newRow=row+dr[i],newCol=col+dc[i];
                if(newRow>n-1 || newCol>m-1 || newRow<0 || newCol<0 || !grid[newRow][newCol])
                    continue;
                else{
                    q.push({newRow,newCol});
                    grid[newRow][newCol]=0;
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(n<=2 || m<=2) return 0;
        queue<pair<int,int>> q;
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]) q.push({0,j});
            if(grid[n-1][j]) q.push({n-1,j});
        }
        for(int i=1;i<n-1;i++)
        {
            if(grid[i][0]) q.push({i,0});
            if(grid[i][m-1]) q.push({i,m-1});
        }
        BFS(grid,q,n,m);
        int enclave=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++)
                if(grid[i][j]) enclave+=1;
        }
        return enclave;
    }
};

int main(){

return 0;
}