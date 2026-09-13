#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_GraphConnectivity {
private:
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<pair<int, int>> bridges;
    vector<bool> visited;
    int timer;

    void findBridges_dfs(int u, int p = -1) {
        visited[u] = true;
        disc[u] = low[u] = timer++;

        for (int v : adj[u]) {
            if (v == p) continue;
            if (visited[v]) {
                low[u] = min(low[u], disc[v]);
            } else {
                findBridges_dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    }

    void countComponent_dfs(int u, int& current_size) {
        visited[u] = true;
        current_size++;
        for (int v : adj[u]) {
            // Check if the edge (u, v) is a bridge
            bool is_bridge = false;
            for(const auto& bridge : bridges) {
                if ((bridge.first == u && bridge.second == v) || (bridge.first == v && bridge.second == u)) {
                    is_bridge = true;
                    break;
                }
            }
            if (!visited[v] && !is_bridge) {
                countComponent_dfs(v, current_size);
            }
        }
    }

public:
    int maxSizeSCC(int n, vector<vector<int>>& edges) {
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // 1. Find all bridges using Tarjan's Algorithm
        disc.assign(n, -1);
        low.assign(n, -1);
        visited.assign(n, false);
        timer = 0;
        bridges.clear();
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                findBridges_dfs(i);
            }
        }
        
        // 2. Find the size of the largest component after removing bridges
        int max_size = 0;
        visited.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int current_size = 0;
                countComponent_dfs(i, current_size);
                max_size = max(max_size, current_size);
            }
        }
        return max_size;
    }
};

void testGraphConnectivity() {
    cout << "## 4. Graph Connectivity ##" << endl;
    Solution_GraphConnectivity sol;
    // Graph with a bridge between 1 and 2
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 2}};
    cout << "Graph has a bridge at (1,2). The two components are {0,1} and {2,3,4}." << endl;
    cout << "Max size of a 2-edge-connected component: " << sol.maxSizeSCC(n, edges) << endl << endl;
}


int main() {
    testGraphConnectivity();
    return 0;
}