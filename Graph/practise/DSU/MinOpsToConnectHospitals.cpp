#include<iostream>
#include<vector>
using namespace std;

class Solution {
    class DSU{
        int comps;
        vector<int> parent,size;
            public:
        DSU(int n){
            comps=n;
            size.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
        
        int find(int node){
            if(parent[node]==node) return node;
            return parent[node]=find(parent[node]);
        }
        
        bool unionBySize(int u,int v){
            int U=find(u),V=find(v);
            if(U==V){
                return false;
            }
            else if(size[U]<size[V]){
                parent[U]=V;
                size[V]+=size[U];
            }
            else{
                parent[V]=U;
                size[U]+=size[V];
            }
            comps--;
            return true;
        }
        
        int numOfComps(){
            return comps;
        }
    };
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        DSU ds(V);
        int excessEdges=0;
        for(vector<int> &edge: edges){
            int u=edge[0],v=edge[1];
            if(!ds.unionBySize(u,v))
                excessEdges++;
        }
        int comps=ds.numOfComps();
        
        if(comps==1) return 0;
        else if(comps>excessEdges+1) return -1;
        else return comps-1;
    }
};


int main(){

return 0;
}