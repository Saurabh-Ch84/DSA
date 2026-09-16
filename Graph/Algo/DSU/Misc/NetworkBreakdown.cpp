#include<bits/stdc++.h>
using namespace std;

class Solution{
    class DSU{
        int n;
        vector<int> parent,size;
        int find(int u){
            if(u==parent[u]) return u;
            return parent[u]=find(parent[u]);
        }
            public:
        DSU(int n):n(n){
            parent.resize(n,-1);
            size.resize(n,1);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
        void unionBySize(pair<int,int> p){
            int u=p.first-1, v=p.second-1;
            int U=find(u), V=find(v);
            if(U==V) return ;
            n--;
            if(size[U]>=size[V]){
                size[U]+=size[V];
                parent[V]=U;
            }
            else{
                size[V]+=size[U];
                parent[U]=V;
            }
        }
        int getNumberOfComps(){
            return n;
        }
    };
        public:
    void solve(int n,int m,int k,vector<pair<int,int>> &edges,vector<pair<int,int>> &removedEdges){
        DSU ds(n);
        set<pair<int,int>> removedEdgeSet(removedEdges.begin(),removedEdges.end());
        for(auto &edge: edges){
            pair<int,int> edge_={edge.second,edge.first};
            if(removedEdgeSet.count(edge) || removedEdgeSet.count(edge_)) continue;
            ds.unionBySize(edge);
        }
        vector<int> res(k,-1);
        for(int i=k-1;i>=0;i--){
            res[i]=ds.getNumberOfComps();
            ds.unionBySize(removedEdges[i]);
        }
        // print res.
        for(int i=0;i<k;i++)
            cout<<res[i]<<" ";
    }
};

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> edges(m);
    for(int i=0;i<m;i++)
        cin>>edges[i].first>>edges[i].second;
    vector<pair<int,int>> removedEdges(k);
    for(int i=0;i<k;i++)
        cin>>removedEdges[i].first>>removedEdges[i].second;
    Solution s;
    s.solve(n,m,k,edges,removedEdges);
return 0;
}