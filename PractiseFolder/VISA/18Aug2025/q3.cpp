#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(int i,int j,int n,int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    
    void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<bool>>& visited,
            vector<int> &di,vector<int> &dj,int n,int m) {
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k){
            int newI = i + di[k], newJ = j + dj[k];
            if(isValid(newI,newJ,n,m) && !visited[newI][newJ] && heights[newI][newJ]>=heights[i][j]) 
                dfs(newI,newJ,heights,visited,di,dj,n,m);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> dpPacific(n, vector<bool>(m, false));
        vector<vector<bool>> dpAtlantic(n, vector<bool>(m, false));
        vector<int> di = {0, -1, 0, 1}, dj = {-1, 0, 1, 0};

        for (int i = 0; i < n; ++i) {
            dfs(i, 0, heights, dpPacific,di,dj,n,m);
            dfs(i, m - 1, heights, dpAtlantic,di,dj,n,m);
        }
        for (int j = 0; j < m; ++j) {
            dfs(0, j, heights, dpPacific,di,dj,n,m);     
            dfs(n - 1, j, heights, dpAtlantic,di,dj,n,m);
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (dpPacific[i][j] && dpAtlantic[i][j])
                    res.push_back({i, j});
        return res;
    }
};

class Solution2 {
    using vbool=vector<bool>;
    using vvbool=vector<vbool>;
    using vint=vector<int>;
    using vvint=vector<vint>; 
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
    void dfs(int i,int j,int n,int m,vint &di,vint &dj,vvbool &visited,vvint &mat){
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int i_=i+di[k], j_=j+dj[k];
            if(!isValid(i_,j_,n,m) || visited[i_][j_] || mat[i_][j_]<mat[i][j])
                continue;
            dfs(i_,j_,n,m,di,dj,visited,mat);
        }
    }
  public:
    int countCoordinates(vector<vector<int>>& mat) {
        // code here
        int n=mat.size(), m=mat[0].size();
        vvbool stationP(n,vbool(m,0)), stationQ(n,vbool(m,0));
        vint di={-1,0,1,0}, dj={0,1,0,-1};
        for(int j=0;j<m;j++){
            dfs(0,j,n,m,di,dj,stationP,mat);
            dfs(n-1,j,n,m,di,dj,stationQ,mat);
        }
        for(int i=0;i<n;i++){
            dfs(i,0,n,m,di,dj,stationP,mat);
            dfs(i,m-1,n,m,di,dj,stationQ,mat);
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(stationP[i][j] && stationQ[i][j])
                    count++;
            }
        }
        return count;
    }
};


int main(){

return 0;
}