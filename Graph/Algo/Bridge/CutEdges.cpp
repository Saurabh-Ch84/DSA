#include<bits/stdc++.h>
using namespace std;

class Solution{
    using vint=vector<int>;
    int timer;
    void DFS(int u,vector<vint> &adj,vint &discovery,vint &lowestNode,vector<pair<int,int>> &bridges,int p=-1){
        discovery[u]=lowestNode[u]=timer++;
        for(int &v: adj[u]){
            if(v==p) continue;
            if(discovery[v]==-1){
                DFS(v,adj,discovery,lowestNode,bridges,u);
                lowestNode[u]=min(lowestNode[u],lowestNode[v]);
                if(lowestNode[v]>discovery[u])
                    bridges.push_back({u,v});
            }
            else lowestNode[u]=min(lowestNode[u],discovery[v]);
        }
    }
        public:
    int solve(int N,int M,vector<pair<int,int>> &edges){
        vector<vint> adj(N);
        for(auto &edge: edges){
            int u=edge.first-1, v=edge.second-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        timer=0;
        vint discovery(N,-1), lowestNode(N,-1);
        vector<pair<int,int>> bridges;
        for(int u=0;u<N;u++){
            if(discovery[u]==-1)
                DFS(u,adj,discovery,lowestNode,bridges);
        }
        return bridges.size();
    }
};

int main(){
    int N,M;
    cin>>N>>M;
    vector<pair<int,int>> edges(M);
    for(int i=0;i<M;i++)
        cin>>edges[i].first>>edges[i].second;
    Solution s;
    cout<<s.solve(N,M,edges);
return 0;
}