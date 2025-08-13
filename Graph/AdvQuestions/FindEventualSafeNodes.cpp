#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// Cycle detection method
class Solution1 {
    bool DFS(int v,vector<int> &visited,vector<vector<int>> &g){
        if(visited[v]==2) return false;
        if(visited[v]==1) return true;
        visited[v]=2;
        for(int &u:g[v])
            if(!DFS(u,visited,g)) return false;
        visited[v]=1;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int V=graph.size();
        vector<int> visited(V,0);
        for(int i=0;i<V;i++)
            if(DFS(i,visited,graph)) ans.push_back(i);        

        sort(ans.begin(),ans.end());
        return ans;
    }
};


//kahn's algo method
class Solution2 {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<vector<int>> revAdj(V);
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                revAdj[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> result;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            result.push_back(node);
            for (int prev : revAdj[node]) {
                indegree[prev]--;
                if (indegree[prev] == 0) q.push(prev);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main(){

return 0;
}