#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    void BFS(vector<vector<int>> &grid,queue<pair<int,int>> &q,int n,int m){
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        int step=0;
        while(!q.empty()){
            step++;
            int size=q.size();
            for(int i=0;i<size;i++){
                int row=q.front().first,col=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int nrow=row+dr[k];
                    int ncol=col+dc[k];
                    if(nrow<0 || ncol<0 || nrow>n-1 || ncol>m-1) continue;
                    if(grid[nrow][ncol]==0)
                    {
                        grid[nrow][ncol]=step;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    q.push({i,j});
                    grid[i][j]=-1;
                }
            }
        }
        
        BFS(grid,q,n,m);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-1) grid[i][j]=0;
            }
        }
        return grid;
    }
};

class Solution2 {
    void BFS(vector<vector<int>> &grid, queue<pair<int,int>> &q, int n, int m) {
        int step = 0;
        while (!q.empty()) {
            step++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int row = q.front().first, col = q.front().second;
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (abs(dr) == abs(dc) || row + dr < 0 || col + dc < 0 || row + dr >= n || col + dc >= m)
                            continue;
                        if (grid[row + dr][col + dc] == -1) { // Only visit unvisited 1s
                            grid[row + dr][col + dc] = step;
                            q.push({row + dr, col + dc});
                        }
                    }
                }
                q.pop();
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int n = mat.size(), m = mat[0].size();
        // Mark 1s as unvisited (-1), 0s as sources
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }
        BFS(mat, q, n, m);
        // No need to reset 0s, as they are already 0
        return mat;
    }
};


int main(){

return 0;
}