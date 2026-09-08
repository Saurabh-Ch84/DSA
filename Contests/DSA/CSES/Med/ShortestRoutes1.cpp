#include<bits/stdc++.h>
using namespace std;

void Dijkstra(int src,int n,vector<vector<pair<int,int>>> &adjList){
    long long inf=1e16;
    vector<long long> dist(n,inf);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> minHeap;
    minHeap.push({0,src});
    dist[src]=0;
    while(!minHeap.empty()){
        auto p=minHeap.top(); minHeap.pop();
        long long d=p.first;
        int u=p.second;
        if(d>dist[u]) continue;
        for(auto &q: adjList[u]){
            long long d_=d+q.first;
            int v=q.second;
            if(d_<dist[v]){
                dist[v]=d_;
                minHeap.push({dist[v],v});
            }
        }
    }
    for(int u=0;u<n;u++)
        cout<<dist[u]<<" ";
}

void solve(int n,int m,vector<vector<int>> &flights){
    vector<vector<pair<int,int>>> adjList(n);
    for(auto &flight: flights){
        int u=flight[0]-1, v=flight[1]-1, w=flight[2];
        adjList[u].push_back({w,v});
    }
    Dijkstra(0,n,adjList);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> flights(m,vector<int>(3));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++) 
            cin>>flights[i][j];
    }
    solve(n,m,flights);
return 0;
}