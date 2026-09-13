#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(int node, int parent, int timer, vector<int>& incomingTime, vector<int>& minimumTime,
             unordered_map<int, vector<int>>& graph, unordered_map<int, bool>& visited, vector<vector<int>>& ans) {
        
        visited[node] = true;
        incomingTime[node] = minimumTime[node] = ++timer;

        for (auto neighbour : graph[node]) {
            if (neighbour == parent) continue;

            if (!visited[neighbour]) {
                dfs(neighbour, node, timer, incomingTime, minimumTime, graph, visited, ans);

                minimumTime[node] = min(minimumTime[node], minimumTime[neighbour]);

                if (incomingTime[node] < minimumTime[neighbour]) {
                    ans.push_back({node, neighbour});
                }
            } else {
                minimumTime[node] = min(minimumTime[node], incomingTime[neighbour]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int timer = 0;
        vector<int> incomingTime(n), minimumTime(n);
        unordered_map<int, vector<int>> graph;

        for (auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }

        unordered_map<int, bool> visited;
        vector<vector<int>> ans;

        dfs(0, -1, timer, incomingTime, minimumTime, graph, visited, ans);

        return ans;
    }
};

// tin-> time of insertion , low-> lowest reachable time
void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, int& timer, vector<pair<int, int>>& bridges) {
    tin[u] = low[u] = timer++;
    for (int v : adj[u]) {
        if (v == parent) continue;
        if (tin[v] == -1) {
            dfs(v, u, adj, tin, low, timer, bridges);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) 
                bridges.push_back({u, v}); // (u, v) is a bridge
        } else 
            low[u] = min(low[u], tin[v]);
    }
}

vector<pair<int,int>> findBridges(int n, vector<vector<int>>& adj) {
    vector<int> tin(n, -1), low(n, -1);
    vector<pair<int,int>> bridges;
    int timer = 0;
    for (int i = 0; i < n; ++i) {
        if (tin[i] == -1) dfs(i, -1, adj, tin, low, timer, bridges);
    }
    return bridges;
}


int main(){

return 0;
}