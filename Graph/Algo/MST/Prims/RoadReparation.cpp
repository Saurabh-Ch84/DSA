#include<bits/stdc++.h>
using namespace std;

class Solution{
    long long getMST(int src,int n,vector<vector<vector<int>>> &adj){
        vector<bool> visited(n,0);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,src,-1}); // weight, node, parent;
        vector<vector<int>> MSTedges;
        long long mstWeight=0;
        while(!pq.empty()){
            auto entry=pq.top(); pq.pop();
            int w=entry[0], u=entry[1], p=entry[2];
            if(visited[u]) continue;
            visited[u]=1;
            if(p!=-1){
                MSTedges.push_back({p+1,u+1});
                mstWeight+=w;
            }
            for(auto &V: adj[u]){
                int w_=V[0], v=V[1];
                if(visited[v]) continue;
                pq.push({w_,v,u});
            }
        }
        int k=MSTedges.size();
        return (k==n-1? mstWeight: -1);
    }
        public:
    void solve(int n,int m,vector<vector<int>> &edges){
        vector<vector<vector<int>>> adj(n);
        for(int i=0;i<m;i++){
            int u=edges[i][0]-1, v=edges[i][1]-1, w=edges[i][2];
            adj[u].push_back({w,v});
            adj[v].push_back({w,u});
        }
        long long mstWeight=getMST(0,n,adj);
        if(mstWeight==-1) cout<<"IMPOSSIBLE";
        else cout<<mstWeight;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m,vector<int>(3));
    for(int i=0;i<m;i++)
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    Solution s;
    s.solve(n,m,edges);
return 0;
}