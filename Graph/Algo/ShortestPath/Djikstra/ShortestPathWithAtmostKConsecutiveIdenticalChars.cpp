#include<bits/stdc++.h>
using namespace std;

class Solution {
    using tuple3_t=tuple<int,int,int>;
    using minheap_t=priority_queue<tuple3_t,vector<tuple3_t>,greater<tuple3_t>>;
    int Dijkstra(int src,int dest,vector<vector<pair<int,int>>> &adj,string &labels,int k,int n){
        int inf=1e9;
        vector<vector<int>> dist(n,vector<int>(k+1,inf));
        minheap_t minHeap;
        dist[src][1]=0;
        minHeap.push({0,src,1});

        while(!minHeap.empty()){
            auto entry=minHeap.top(); minHeap.pop();
            int w=get<0>(entry), u=get<1>(entry), uCount=get<2>(entry);
            for(auto &p: adj[u]){
                int v=p.first, ww=p.second, vCount=(labels[u]==labels[v]? uCount+1:1);
                if(vCount<=k && dist[v][vCount]>w+ww){
                    dist[v][vCount]=w+ww;
                    minHeap.push({dist[v][vCount],v,vCount});
                }
            }
        }

        int mini=inf;
        for(int i=0;i<=k;i++)
            mini=min(mini,dist[dest][i]);
        
        return (mini==inf? -1:mini);
    }
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &edge: edges){
            int u=edge[0], v=edge[1], w=edge[2];
            adj[u].push_back({v,w});
        }
        int src=0, dest=n-1;
        return Dijkstra(src,dest,adj,labels,k,n);
    }
};

int main(){

return 0;
}