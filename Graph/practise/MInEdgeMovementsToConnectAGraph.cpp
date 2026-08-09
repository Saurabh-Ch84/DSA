#include<bits/stdc++.h>
using namespace std;

class Solution {
    class DSU{
        int comps;
        vector<int> parent, size;
            public:  
        DSU(int n):comps(n){
            parent.resize(n,-1);
            size.resize(n,1);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
        int find(int u){
            if(parent[u]==u)
                return u;
            return parent[u]=find(parent[u]);
        }
        bool unionBySize(int u,int v){
            int U=find(u), V=find(v);
            if(U==V) return false;
            if(size[U]>size[V]){
                size[U]+=size[V];
                parent[V]=U;
            }
            else{
                size[V]+=size[U];
                parent[U]=V;
            }
            comps--;
            return true;
        }
        int numberOfComps(){
            return comps;
        }
    };
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        DSU ds(n);
        int excessEdges=0;
        for(auto &edge: edges){
            int u=edge[0], v=edge[1];
            if(!ds.unionBySize(u,v)) 
                excessEdges++;
        }
        int operations=ds.numberOfComps()-1;
        if(operations>excessEdges) return -1;
        return operations;
    }
};

int main(){

return 0;
}