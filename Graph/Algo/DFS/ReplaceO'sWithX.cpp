#include<iostream>
#include<vector>
using namespace std;

// User function Template for C++

class Solution {
    void DFS(vector<vector<char>> &mat,vector<vector<bool>>&v,int row,int col,int n,int m){
        v[row][col]=true;
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+dr[i],ncol=col+dc[i];
            if(nrow<0 || ncol<0 || nrow>n-1 || ncol>m-1 || mat[nrow][ncol]!='O' || v[nrow][ncol]) 
                continue;
            DFS(mat,v,nrow,ncol,n,m);
        }
    }
  public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            if(i==0 || i==n-1)
                for(int j=0;j<m;j++){
                    if(mat[i][j]=='O' && !visited[i][j])
                        DFS(mat,visited,i,j,n,m);
                }
            else
                for(int j=0;j<m;j+=max(m-1,1)){
                    if(mat[i][j]=='O' && !visited[i][j])
                        DFS(mat,visited,i,j,n,m);
            }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(mat[i][j]=='O' && !visited[i][j]) mat[i][j]='X';
            }
        }
        return mat;
    }
};

int main(){

return 0;
}