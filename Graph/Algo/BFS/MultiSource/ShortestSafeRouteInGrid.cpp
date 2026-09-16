#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
    void multisourceBFS(int n,int m,vector<vector<int>> &mat,int target){ 
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==target) q.push({i,j});
            }
        }
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto entry=q.front(); q.pop();
                int i=entry.first, j=entry.second;
                for(int k=0;k<4;k++){
                    int i_=i+dir[k][0], j_=j+dir[k][1];
                    if(!isValid(i_,j_,n,m) || !mat[i_][j_])
                        continue;
                    mat[i_][j_]=target;
                }
            }
        }
    }
    int multisourceBFS(int n,int m,vector<vector<int>> &mat){ 
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            if(mat[i][0]){
                visited[i][0]=1;
                q.push({i,0});
            }
        }
        int moves=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto entry=q.front(); q.pop();
                int i=entry.first, j=entry.second;
                if(j==m-1) return moves+1;
                for(int k=0;k<4;k++){
                    int i_=i+dir[k][0], j_=j+dir[k][1];
                    if(!isValid(i_,j_,n,m) || !mat[i_][j_] || visited[i_][j_])
                        continue;
                    visited[i_][j_]=1;
                    q.push({i_,j_});
                }
            }
            moves++;
        }
        return -1;
    }
  public:
    int shortestPath(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(), m=mat[0].size();
        // marking
        multisourceBFS(n,m,mat,0);
        // shortest-route
        return multisourceBFS(n,m,mat);
    }
};

int main(){

return 0;
}