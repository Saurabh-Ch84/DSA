#include<bits/stdc++.h>
using namespace std;

class Solution {
    int BFS01(vector<vector<pair<int,int>>> &adj,int src,int dst,int n){
        deque<int> dq;
        vector<int> dist(n,1e9);
        dq.push_front(src);
        dist[src]=0;
        
        while(!dq.empty()){
            int u=dq.front(); dq.pop_front();
            for(auto &edge: adj[u]){
                int w=edge.first, v=edge.second;
                if(dist[v]>w+dist[u]){
                    dist[v]=w+dist[u];
                    if(w==0) dq.push_front(v);
                    else dq.push_back(v);
                }
            }
        }
        return (dist[dst]==1e9? -1: dist[dst]);
    }
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // code here  
        vector<vector<pair<int,int>>> adj(n);
        for(auto &edge: edges){
            int u=edge[0]-1, v=edge[1]-1;
            adj[u].push_back({0,v});
            adj[v].push_back({1,u});
        }
        return BFS01(adj,src-1,dst-1,n);
    }
};

int main(){

return 0;
}