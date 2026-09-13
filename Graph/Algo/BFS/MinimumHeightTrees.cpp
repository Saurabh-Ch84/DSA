#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vvint adjList(n);
        vint degree(n,0);
        for(vint &edge: edges){
            int u=edge[0], v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> q;
        vint visited(n,-1);

        for(int i=0;i<n;i++){
            if(degree[i]<=1) {
                q.push(i);
                visited[i]=0;
            }
        }

        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int &v: adjList[u]){
                degree[v]--;
                if(visited[v]==-1 && degree[v]==1){
                    visited[v]=1+visited[u];
                    q.push(v);
                }
            }
        }
        int lastVisitVal=-1;
        for(int i=0;i<n;i++){
            lastVisitVal=max(lastVisitVal,visited[i]);
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(visited[i]==lastVisitVal)
                res.push_back(i);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Base case: If there is only 1 node, it is the root
        if (n == 1) return {0};
        
        vector<vector<int>> adjList(n);
        vector<int> degree(n, 0);
        
        for (auto &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }
        
        int remainingNodes = n;
        
        // Peel the onion layer by layer until 1 or 2 nodes remain
        while (remainingNodes > 2) {
            int sz = q.size();
            remainingNodes -= sz; // Subtract the entire outer layer
            
            while (sz--) {
                int u = q.front(); q.pop();
                for (int v : adjList[u]) {
                    degree[v]--;
                    if (degree[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }
        
        // The queue now holds the exact 1 or 2 centroids of the tree!
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

int main(){

return 0;
}