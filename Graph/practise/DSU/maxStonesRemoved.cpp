#include<iostream>
#include<vector>
#include<unordered_map>
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

using vint=vector<int>;
class Solution {
    class DSU{
        vint parent,size;
        int n;
            public:
        DSU(int n){
            this->n=n;
            size.resize(n,1);
            parent.resize(n,-1);
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
            n--;
            if(size[U]>size[V]){
                size[U]+=size[V];
                parent[V]=U;
            }
            else{
                size[V]+=size[U];
                parent[U]=V;
            }
        }

        int getNoOfComps(){
            return n;
        }
    };
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        DSU ds(n);
        unordered_map<int,int> rowMap, colMap;
        for(int i=0;i<n;i++){
            int x=stones[i][0], y=stones[i][1];
            if(rowMap.count(x))
                ds.unionBySize(i,rowMap[x]);
            if(colMap.count(y))
                ds.unionBySize(i,colMap[y]);
            rowMap[x]=i;
            colMap[y]=i;
        }
        
        int stonesRemoved=n-ds.getNoOfComps();
        return stonesRemoved;
    }
};

int main(){

return 0;
}