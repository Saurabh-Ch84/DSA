#include<bits/stdc++.h>
using namespace std;

class DSU{
    int n;
    public:
    vector<int> parent, size;
    DSU(int n):n(n){
        parent.resize(n,-1);
        size.resize(n,1);
        for(int i=0;i<n;i++)
        parent[i]=i;
    }
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }
    void unionBySize(int u,int v){
        int U=find(u), V=find(v);
        if(U==V) return ;
        if(size[U]>size[V]){
            parent[V]=U;
            size[U]+=size[V];
        }
        else{
            parent[U]=V;
            size[V]+=size[U];
        }
        n--;
    }
    int getNoOfComps(){
        return n;
    }
};

void solve(int n,int m,vector<vector<int>> roads){
    DSU ds(n);
    for(int i=0;i<m;i++){
        int u=roads[i][0]-1, v=roads[i][1]-1;
        ds.unionBySize(u,v);
    }
    int newRoads=ds.getNoOfComps()-1;
    cout<<newRoads<<endl;
    int U=-1;
    for(int v=0;v<n;v++){
        int V=ds.find(v);
        if(v!=V) continue;
        if(U!=-1 && U!=V) cout<<(U+1)<<" "<<(V+1)<<endl;
        U=V;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> roads(m,vector<int>(2));
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++)
            cin>>roads[i][j];
    }
    solve(n,m,roads);
return 0;
}