#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution0 {
    using vll=vector<long long>;
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vll rowPrefixSum(m,0), colPrefixSum(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rowPrefixSum[i]+=grid[i][j];
                colPrefixSum[j]+=grid[i][j];
            }
        }

        for(int i=1;i<m;i++){
            rowPrefixSum[i]+=rowPrefixSum[i-1];
        }

        for(int j=1;j<n;j++){
            colPrefixSum[j]+=colPrefixSum[j-1];
        }

        for(int i=0;i<m;i++){
            if(rowPrefixSum[i]==rowPrefixSum[m-1]-rowPrefixSum[i]){
                return true;
            }
        }

        for(int j=0;j<n;j++){
            if(colPrefixSum[j]==colPrefixSum[n-1]-colPrefixSum[j]){
                return true;
            }
        }
        return false;
    }
};

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        vvint adjList(V);
        vint degree(V,0);
        for(vint &edge: edges){
            int u=edge[0], v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        queue<int> q;
        for(int v=0;v<V;v++){
            if(degree[v]==1){
                q.push(v);
            }
        }
        
        int currDepth=0,maxDepth=0;
        vint result;
        while(!q.empty()){
            int sz = q.size();
            result.clear(); // Every new layer replaces the previous one
            while(sz--){
                int u = q.front(); q.pop();
                result.push_back(u); // Add current leaf to this layer's result
                for(int &v : adjList[u]){
                    degree[v]--; 
                    if(degree[v] == 1) q.push(v);
                }
            }
        }
        return result;
    }
};

class Solution2 {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if (V == 1) return {0};
        
        vector<int> adj[V+1];
        vector<int> degree(V, 0);
        
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        int remaining = V;
        
        while (remaining > 2) {
            int sz = q.size();
            remaining -= sz;
            
            for (int i = 0; i < sz; i++) {
                auto it = q.front();
                q.pop();
                for (int u: adj[it]) {
                    degree[u]--;
                    if (degree[u] == 1) {
                        q.push(u);
                    }
                }
            }
        }
        
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};

int main(){

return 0;
}