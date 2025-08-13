#include<iostream>
#include<vector>
using namespace std;

//Tarjan's algo
class Solution {
    void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low,
             vector<bool>& visited, int& timer, vector<bool>& isArticulation) {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;

        for (int &v : adj[u]) {
            if (v == parent) continue;
            if (!visited[v]) {
                dfs(v, u, adj, tin, low, visited, timer, isArticulation);
                low[u] = min(low[u], low[v]);
                if (parent != -1 && low[v] >= tin[u])
                    isArticulation[u] = true;
                ++children;
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }
        if (parent == -1 && children > 1)
            isArticulation[u] = true;
    }
public:
    vector<int> articulationPoints(int n, vector<vector<int>>& adj) {
        vector<int> tin(n, -1), low(n, -1);
        vector<bool> visited(n, false), isArticulation(n, false);
        int timer = 0;
        for (int u = 0; u < n; ++u) {
            if (!visited[u])
                dfs(u, -1, adj, tin, low, visited, timer, isArticulation);
        }
        vector<int> result;
        for (int u = 0; u < n; ++u) {
            if (isArticulation[u])
                result.push_back(u);
        }
        if (result.empty()) result.push_back(-1);
        return result;
    }
};


int main(){

return 0;
}