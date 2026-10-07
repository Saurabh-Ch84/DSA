#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int u, int p, vector<vector<int>> &adj, vector<int> &vis, vector<int> &parent, int &cycle_start, int &cycle_end) {
        vis[u] = 1;
        parent[u] = p;
        for (int v : adj[u]) {
            if (v == parent[u]) continue;
            if (vis[v]) {
                // Cycle detected! Record where it starts and ends
                cycle_end = u;
                cycle_start = v;
                return 1;
            }
            if (!vis[v]) {
                if (dfs(v, u, adj, vis, parent, cycle_start, cycle_end)) 
                    return 1;
            }
        }
        return 0;
    }

public:
    void roundTrip(int n, int m, vector<pair<int, int>> &edges) {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }
        
        vector<int> vis(n + 1, 0);
        vector<int> parent(n + 1, -1);
        int cycle_start = -1, cycle_end = -1;
        
        // Handle disconnected components
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis, parent, cycle_start, cycle_end)) {
                    break;
                }
            }
        }
        
        if (cycle_start == -1) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        // Reconstruct the cycle using the parent pointers
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start); // Complete the loop
        // Reverse to get the correct traversal order
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << "\n";
        for (int node : cycle) {
            cout << node << " ";
        }
        cout << "\n";
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edges(m);
    for(int i=0;i<m;i++)
        cin>>edges[i].first>>edges[i].second;
    Solution s;
    s.roundTrip(n,m,edges);
return 0;
}