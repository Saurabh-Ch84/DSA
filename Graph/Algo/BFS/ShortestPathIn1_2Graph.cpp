#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    
    using piint=pair<int,int>;
    using vpiint=vector<pair<int,int>>;
    using vvpiint=vector<vpiint>;
    
    int Dijkstra(int V,int src,int dest,vvpiint &adjList){
        int inf=1e9;
        vint dist(V,inf);
        priority_queue<piint,vpiint,greater<piint>> pq;
        dist[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            piint entry=pq.top(); pq.pop();
            int w=entry.first, u=entry.second;
            if(u==dest) break;
            if(dist[u]<w) continue;
            for(piint &p: adjList[u]){
                int w_=w+p.first, v=p.second;
                if(w_<dist[v]){
                    dist[v]=w_;
                    pq.push({w_,v});
                }
            }
        }
        return (dist[dest]==inf? -1: dist[dest]);
    }
  public:
    int shortestPath(int V,int src,int dest,vvint &edges) {
        // code here
        vvpiint adjList(V);
        for(vint &edge: edges){
            int u=edge[0], v=edge[1], w=edge[2];
            // undirected graph
            adjList[u].push_back({w,v});
            adjList[v].push_back({w,u});
        }
        
        return Dijkstra(V,src,dest,adjList);
    }
};

class Solution2 {
    using vint=vector<int>;
    using vvint=vector<vint>;

    int BFS(int V,int src,int dest,vvint &adjList){
        vint visited(V,0);
        queue<int> q;
        q.push(src);
        int dist=0;
        visited[src]=1;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int u=q.front(); q.pop();
                if(u==dest) return dist;
                for(int &v: adjList[u]){
                    if(visited[v]) continue;
                    q.push(v);
                    visited[v]=1;
                }
            }
            dist++;
        }
        return -1;
    }
  public:
    int shortestPath(int V,int src,int dest,vvint &edges) {
        // code here
        int m=edges.size(), newNodes=0;
        vvint adjList(V+m);
        for(vint &edge: edges){
            int u=edge[0], v=edge[1], w=edge[2];
            if(w==2){
                int x=V+newNodes++;
                adjList[u].push_back(x);
                adjList[x].push_back(u);
                
                adjList[v].push_back(x);
                adjList[x].push_back(v);
            }
            else{
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }
        return BFS(V+newNodes,src,dest,adjList);
    }
};

int main(){

return 0;
}