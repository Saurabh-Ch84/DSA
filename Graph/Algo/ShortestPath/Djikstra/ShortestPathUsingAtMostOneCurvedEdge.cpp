#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;
using pii = pair<int,int> ;
using vpii = vector<pii> ;
using vi = vector<int> ;
using vvpii = vector<vpii> ;

class Solution {
    void dijkstra(int a,vvpii &adjMat,vi &dist){
        priority_queue<pii,vpii,greater<pii>> pq;
        dist[a]=0;
        pq.push({0,a});
        
        while(!pq.empty()){
            pii entry=pq.top();pq.pop();
            int cost=entry.first,u=entry.second;
            if(cost>dist[u]) continue;
            for(pii &p: adjMat[u]){
                int w=p.first,v=p.second;
                w=w+cost;
                if(w<dist[v]){
                    dist[v]=w;
                    pq.push({dist[v],v});
                }
            }
        }
    }
    
    int useCircularEdge(int a,int b,int u,int v,int cw,vi &distAtoB,vi &distBtoA){
        int ans=INT_MAX;
        //Case-1
        if(distAtoB[u]!=INT_MAX  && distBtoA[v]!=INT_MAX)
            ans=min(ans,distAtoB[u]+cw+distBtoA[v]);
        //Case-2
        if(distAtoB[v]!=INT_MAX  && distBtoA[u]!=INT_MAX)
            ans=min(ans,distAtoB[v]+cw+distBtoA[u]);
        return ans;
    }
  public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        // code here
        vvpii adjMat(V);
        for(vi &edge: edges){
            int u=edge[0],v=edge[1];
            int sw=edge[2];
            adjMat[u].push_back({sw,v});
            adjMat[v].push_back({sw,u});
        }
        
        vi distAtoB(V,INT_MAX);
        dijkstra(a,adjMat,distAtoB);
        //No Circular Edge Case
        int ans=distAtoB[b];
        
        vi distBtoA(V,INT_MAX);
        dijkstra(b,adjMat,distBtoA);
        
        for(vi &edge: edges){
            int u=edge[0],v=edge[1];
            int cw=edge[3];
            int cost=useCircularEdge(a,b,u,v,cw,distAtoB,distBtoA);
            ans=min(ans,cost);
        }
        
        return (ans==INT_MAX)? -1: ans;
    }
};

int main(){

return 0;
}