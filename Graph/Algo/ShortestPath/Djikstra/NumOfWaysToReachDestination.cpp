#include<iostream>
#include<queue>
#include<climits>
#include<vector>
using namespace std;

using vi = vector<int> ;
using pii = pair<int,int> ;
using vpii = vector<pii> ;
using vvpii= vector<vpii> ;

class Solution {
    int dijkstra(int V,int src,int dest,vvpii &adj){
        priority_queue<pii,vpii,greater<pii>> pq;
        vi dist(V,INT_MAX),ways(V,0);
        pq.push({0,src});
        dist[src]=0,ways[src]=1;
        
        while(!pq.empty()){
            pii p=pq.top();pq.pop();
            int w=p.first,u=p.second;
            if(w>dist[u]) continue;
            for(pii &q: adj[u]){
                int w_=q.first,v=q.second;
                int d=w_+w;
                if(dist[v]>d){
                    dist[v]=d;
                    ways[v]=ways[u];
                    pq.push({dist[v],v});
                }
                else if(dist[v]==d) ways[v]+=ways[u];
            }
        }
        
        return ways[dest];
    }
    
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vvpii adj(V);
        for(vi &edge: edges){
            int u=edge[0],v=edge[1],w=edge[2];
            adj[u].push_back({w,v});
            adj[v].push_back({w,u});
        }
        return dijkstra(V,0,V-1,adj);
    }
};

int main(){

return 0;
}