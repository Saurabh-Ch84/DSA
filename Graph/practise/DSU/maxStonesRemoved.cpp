#include<iostream>
#include<vector>
using namespace std;

class Solution {
    class DSU{
            public:
        vector<int> parent,size;
        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++) parent[i]=i;
        }

        int find(int node){
            if(node==parent[node]) return node;
            return parent[node]=find(parent[node]);
        }

        void unionBySize(int u,int v){
            int U=find(u);
            int V=find(v);
            if(U==V) return ;
            if(size[U]>size[V]){
                size[U]+=size[V];
                parent[V]=U;
            }
            else{
                size[V]+=size[U];
                parent[U]=V;
            }
        }
    };
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=0,m=0,noOfStones=stones.size();
        for(vector<int> &stone:stones){
            int i=stone[0],j=stone[1];
            n=max(i,n);
            m=max(j,m);
        }
        n+=1,m+=1;
        DSU ds(n+m);
        for(vector<int> &stone:stones){
            int nodeU=stone[0];
            int nodeV=stone[1]+n;
            ds.unionBySize(nodeU,nodeV);
        }
        int numberOfComponents=0;
        for(int i=0;i<ds.parent.size();i++){
            //ds.size[i]>1 denotes that it's a stone
            if(ds.size[i]>1 && ds.parent[i]==i)
                numberOfComponents++;
        }
        int stonesRemoved=noOfStones-numberOfComponents;
        return stonesRemoved;
    }
};

int main(){

return 0;
}