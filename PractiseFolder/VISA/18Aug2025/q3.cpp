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


int main(){

return 0;
}