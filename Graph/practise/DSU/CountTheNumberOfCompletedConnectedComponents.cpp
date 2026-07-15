#include<bits/stdc++.h>
using namespace std;

int nC2(int x){
    return x*(x-1)/2;
}
class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    class DSU{
        int n;
        vint parent, size, edges;
        int find(int u){
            if(parent[u]==u) return u;
            return parent[u]=find(parent[u]);
        }
            public:
        DSU(int n):n(n){
            parent.resize(n,-1);
            edges.resize(n,0);
            size.resize(n,1);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }

        void unionBySize(int u,int v){
            int U=find(u), V=find(v);
            if(U==V){
                edges[U]++;
                return;
            }
            if(size[U]>=size[V]){
                size[U]+=size[V];
                parent[V]=U;
                edges[U]=1+edges[U]+edges[V];
            }
            else{
                size[V]+=size[U];
                parent[U]=V;
                edges[V]=1+edges[V]+edges[U];
            }
        }

        int numberOfCompleteComponents(){
            int count=0;
            for(int i=0;i<n;i++){
                if(parent[i]==i && edges[i]==nC2(size[i]))
                    count++;
            }
            return count;
        }
    };
public:
    int countCompleteComponents(int n,vvint &edges) {
        DSU ds(n);
        for(vint &edge: edges){
            int u=edge[0], v=edge[1];
            ds.unionBySize(u,v);
        }
        return ds.numberOfCompleteComponents();
    }
};

int main(){

return 0;
}