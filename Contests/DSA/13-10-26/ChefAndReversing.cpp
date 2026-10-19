#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReversals(int n, int m, vector<vector<int>>& edges) {
        // adj[u] stores {neighbor, weight}
        // weight 0 = original direction, weight 1 = reverse direction
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1];
            if (u == v) continue; // Ignore self loops
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        vector<int> dist(n + 1, 1e9);
        deque<int> dq;

        dist[1] = 0;
        dq.push_front(1);

        while (!dq.empty()) {
            int u = dq.front(); dq.pop_front();
            if (u == n) return dist[n];
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first, weight = neighbor.second;
                // Relaxation step
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    if (weight == 0) dq.push_front(v); // 0-weight edges processed immediately
                    else dq.push_back(v);  // 1-weight edges pushed to back
                }
            }
        }
        return dist[n] == 1e9 ? -1 : dist[n];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (cin >> n >> m) {
        vector<vector<int>> edges(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> edges[i][0] >> edges[i][1];
        }
        Solution sol;
        cout << sol.minReversals(n, m, edges) << "\n";
    }
    return 0;
}