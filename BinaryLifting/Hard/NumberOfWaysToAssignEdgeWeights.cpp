#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint = vector<int>;
    using vvint = vector<vector<int>>;

    vint depth;
    vvint ancestor, adjList;
    int LOG;

    void DFS(int u, int d, int p) {
        depth[u] = d;
        ancestor[u][0] = p;
        for (int &v : adjList[u]) {
            if (v == p) continue;
            DFS(v, d + 1, u);
        }
    }

    void performBL(int root, int n) {
        DFS(root, 0, -1);
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (ancestor[i][j - 1] != -1) {
                    ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
                }
            }
        }
    }

    int binaryExponentiation(int base, int exp, int mod) {
        long long res = 1;
        base = base % mod;
        while (exp) {
            if (exp & 1) res = (res * base) % mod;
            exp = exp / 2;
            base = (1LL * base * base) % mod;
        }
        return res % mod;
    }

    int getLCA(int u, int v) {
        if (depth[u] != depth[v]) {
            if (depth[v] > depth[u]) swap(u, v);
            int k = depth[u] - depth[v];
            for (int j = LOG - 1; j >= 0; j--) {
                if (k & (1 << j)) u = ancestor[u][j];
            }
        }
        
        if (u == v) return u;
        
        for (int j = LOG - 1; j >= 0; j--) {
            if (ancestor[u][j] == -1 || ancestor[v][j] == -1)
                continue;
            if (ancestor[u][j] != ancestor[v][j]) {
                u = ancestor[u][j];
                v = ancestor[v][j];
            }
        }
        return ancestor[u][0];
    }

public:
    vint assignEdgeWeights(vvint &edges, vvint &queries) {
        int n = edges.size() + 1, q = queries.size();
        int mod = 1e9 + 7;

        LOG = ceil(log2(n)) + 1;
        depth.assign(n, 0);
        ancestor.assign(n, vint(LOG, -1));
        adjList.assign(n,vint());

        for (vint &edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        performBL(0, n);
        
        vint res(q, 0);
        for (int i = 0; i < q; i++) {
            int u = queries[i][0] - 1, v = queries[i][1] - 1;
            int lca = getLCA(u, v);
            int e = depth[u] + depth[v] - 2 * depth[lca];
            if (e > 0) res[i] = binaryExponentiation(2, e - 1, mod);
        }
        
        return res;
    }
};

int main(){

return 0;
}