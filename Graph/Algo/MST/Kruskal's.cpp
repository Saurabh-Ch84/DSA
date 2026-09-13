#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
};

struct DSU {
    vector<int> par, rank;
    DSU(int n) : par(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }
    int find(int x) {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    }
    bool unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false;
        if (rank[xr] < rank[yr]) par[xr] = yr;
        else if (rank[xr] > rank[yr]) par[yr] = xr;
        else par[yr] = xr, rank[xr]++;
        return true;
    }
};

int kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(V);
    int mst_weight = 0;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) mst_weight += e.w;
    }
    return mst_weight;
}

int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}
    };
    cout << "Total weight of MST: " << kruskalMST(V, edges) << endl;
    return 0;
}
