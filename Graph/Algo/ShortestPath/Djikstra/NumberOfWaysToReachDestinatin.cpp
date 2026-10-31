#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

// User function Template for C++
class Solution {
    int fun(vector<vector<pair<int,int>>> &adj, int src, int V) {
        const int MOD = 1e9 + 7;
        using ll = long long;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> minHeap;
        minHeap.push({0, src});
        vector<ll> distance(V, LLONG_MAX);
        vector<int> ways(V, 0);
        distance[src] = 0;
        ways[src] = 1;
        while (!minHeap.empty()) {
            int u = minHeap.top().second;
            ll distU = minHeap.top().first;
            minHeap.pop();
            if (distU > distance[u]) continue;
            for (auto &v : adj[u]) {
                int neighbor = v.first;
                ll weight = v.second;
                if (distU + weight < distance[neighbor]) {
                    distance[neighbor] = distU + weight;
                    ways[neighbor] = ways[u];
                    minHeap.push({distance[neighbor], neighbor});
                } else if (distU + weight == distance[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[u]) % MOD;
                }
            }
        }
        return ways[V - 1] % MOD;
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int src = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (auto &road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        return fun(adj, src, n);
    }
};


int main(){

return 0;
}