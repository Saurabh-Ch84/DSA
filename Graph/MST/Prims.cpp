#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int primMST(int V, vector<vector<pii>>& adj) {
    vector<bool> visited(V, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0}); // {weight, node}
    int mst_weight = 0;

    while (!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int wt = top.first, u = top.second;
        if (visited[u]) continue;
        visited[u] = true;
        mst_weight += wt;
        for (const pii &edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if (!visited[v]) pq.push({w, v});
        }
    }
    return mst_weight;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);
    // Example: add edges (u, v, w)
    adj[0].push_back({1, 2}); adj[1].push_back({0, 2});
    adj[0].push_back({3, 6}); adj[3].push_back({0, 6});
    adj[1].push_back({2, 3}); adj[2].push_back({1, 3});
    adj[1].push_back({3, 8}); adj[3].push_back({1, 8});
    adj[1].push_back({4, 5}); adj[4].push_back({1, 5});
    adj[2].push_back({4, 7}); adj[4].push_back({2, 7});
    cout << "Total weight of MST: " << primMST(V, adj) << endl;
    return 0;
}
