#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;
    
    using piint=pair<int,int>;
    using vpiint=vector<piint>;
    using vvpiint=vector<vpiint>;

    using vll=vector<long long>;
    using pllint=pair<long long,int>;
    using vpllint=vector<pllint>;

    long long inf=1e16;

    bool CheckDijkstra(int mid,int n,int src,int dest,long long k,vvpiint &adjList){
        vll dist(n,inf);
        priority_queue<pllint,vpllint,greater<pllint>> pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()){
            pllint entry=pq.top(); pq.pop();
            long long c=entry.first;
            int u=entry.second;
            if(c>k) return false;
            if(u==dest) return true;
            if(c>dist[u]) continue;
            for(auto &edge: adjList[u]){
                int v=edge.first, w=edge.second;
                if(w<mid) continue;
                if(c+w < dist[v]){
                    dist[v]=c+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return false;
    }
public:
    int findMaxPathScore(vvint &edges,vector<bool>& online,long long k) {
        int n=online.size(), low=1e9, high=0;
        vvpiint adjList(n);
        for(vint &edge: edges){
            int u=edge[0], v=edge[1], w=edge[2];
            if(!online[u] || !online[v]) 
                continue;
            adjList[u].push_back({v,w});
            low=min(low,w);
            high=max(high,w);
        }
        
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(CheckDijkstra(mid,n,0,n-1,k,adjList)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};

int main(){

return 0;
}