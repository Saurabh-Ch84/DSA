#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long max_gas = 0;

    // DFS returns the maximum gas starting from 'u' and going DOWN into its subtree
    long long DFS(int u, int p, vector<long long> &w, vector<vector<pair<int, long long>>> &adj) {
        long long m1 = 0; // Best downward branch
        long long m2 = 0; // Second best downward branch

        for (auto &edge : adj[u]) {
            int v = edge.first;
            long long c = edge.second;

            if (v == p) continue; // Don't go back to parent

            // Get the best downward path from the child
            long long child_val = DFS(v, u, w, adj);
            
            // Net gas if we take this branch
            long long branch_val = child_val - c;

            // Maintain the top 2 best branches (only if they yield positive net gas)
            if (branch_val > m1) {
                m2 = m1;
                m1 = branch_val;
            } else if (branch_val > m2) {
                m2 = branch_val;
            }
        }

        // Global max could be the path that turns at node 'u' (combining top 2 branches)
        max_gas = max(max_gas, w[u] + m1 + m2);

        // Return the best single downward path to the parent
        return w[u] + m1;
    }

public:
    long long solve(int n, vector<long long> &w, vector<vector<long long>> &roads) {
        vector<vector<pair<int, long long>>> adj(n);
        for (auto &road : roads) {
            int u = road[0] - 1;
            int v = road[1] - 1;
            long long c = road[2];
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        max_gas = 0;
        
        // Single DFS from arbitrary root (0)
        DFS(0, -1, w, adj);
        
        return max_gas;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<vector<long long>> roads(n - 1, vector<long long>(3));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> roads[i][j];
        }
    }
    Solution s;
    cout << s.solve(n, w, roads) << "\n";
    return 0;
}