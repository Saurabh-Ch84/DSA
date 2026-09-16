#include<bits/stdc++.h>
using namespace std;

class Solution{
    using vint=vector<int>;
    int timer;
    void DFS(int u,vector<vint> &adj,vint &discovery,vint &lowestNode,vector<bool> &isArticulationPoint,int p=-1){
        discovery[u]=lowestNode[u]=timer++;
        int childCount=0;
        for(int &v: adj[u]){
            if(v==p) continue;
            if(discovery[v]==-1){
                childCount++;
                DFS(v,adj,discovery,lowestNode,isArticulationPoint,u);
                lowestNode[u]=min(lowestNode[u],lowestNode[v]);
                if(lowestNode[v]>=discovery[u] && p!=-1)
                    isArticulationPoint[u]=1;
            }
            else lowestNode[u]=min(lowestNode[u],discovery[v]);
        }
        if(p==-1 && childCount>1) isArticulationPoint[u]=1;
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
        vector<bool> isArticulationPoint(N,0);
        for(int u=0;u<N;u++){
            if(discovery[u]==-1)
                DFS(u,adj,discovery,lowestNode,isArticulationPoint);
        }
        vector<int> cutVertices;
        for(int i=0;i<N;i++){
            if(isArticulationPoint[i])
                cutVertices.push_back(i);
        }
        return cutVertices.size();
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