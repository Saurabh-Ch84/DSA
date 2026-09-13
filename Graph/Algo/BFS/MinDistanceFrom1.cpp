#include<iostream>
#include<queue>
#include<vector>
using namespace std;

using pii = pair<int, int>;
using vi = vector<int> ;
using vb = vector<bool> ; 

class Solution {
    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    void BFS(vector<vi>& dist,vector<vi>& grid,queue<pii>& q,vector<vb>& visited,int n,int m) {
        vi di = {-1, 0, 1, 0};
        vi dj = {0, 1, 0, -1};

        int steps = 1;
        while (!q.empty()) {
            int sz = q.size();

            for (int count = 0; count < sz; count++) {
                pii p = q.front();q.pop();
                int i = p.first, j = p.second;
                for (int k = 0; k < 4; k++) {
                    int i_ = i + di[k], j_ = j + dj[k];
                    if (!isValid(i_, j_, n, m) || visited[i_][j_] || grid[i_][j_] != 0)
                        continue;
                    dist[i_][j_] = steps;   
                    q.push({i_, j_});       
                    visited[i_][j_] = true; 
                }
            }
            steps++;
        }
    }

public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        if (n == 0 || m==0) return {};

        queue<pii> q;
        vector<vb> visited(n, vb(m, false));
        vector<vi> dist(n, vi(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                    dist[i][j] = 0;
                }
            }
        }

        BFS(dist, grid, q, visited, n, m);

        return dist;
    }
};

int main(){

return 0;
}