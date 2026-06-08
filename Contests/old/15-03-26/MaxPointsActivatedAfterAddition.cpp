#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
using vint=vector<int>;

class Solution {
    class DSU{
        vint size, parent;
        int n;
            public:
        DSU(int n){
            this->n=n;
            size.resize(n,1);
            parent.resize(n,-1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }

        int find(int node){
            if(node==parent[node])
                return node;
            return parent[node]=find(parent[node]);
        }

        int unionBySize(int u,int v){
            int U=find(u), V=find(v);
            if(U==V) return -1;
            n--;
            if(size[U]>size[V]){
                size[U]+=size[V];
                parent[V]=U;
                return size[U];
            }
            else{
                size[V]+=size[U];
                parent[U]=V;
                return size[V];
            }
        }

        int getNumberOfComps(){
            return n;
        }

        pair<int,int> getFirst2MaxCompsSize(){
            int firstMax=0, secondMax=0;
            for(int i=0;i<parent.size();i++){
                if(parent[i]!=i) continue;
                int sz=size[i];
                if(sz>=firstMax){
                    secondMax=firstMax;
                    firstMax=sz;
                }
                else if(sz>secondMax && sz<firstMax)
                    secondMax=sz;
            }
            return {firstMax,secondMax};
        }
    };
public:
    int maxActivated(vector<vector<int>>& points) {
        int n=points.size();
        if(!n) return 1;
        DSU ds(n);

        unordered_map<int,int> rowMap, colMap;
        int maxi=1;
        for(int i=0;i<n;i++){
            int x=points[i][0], y=points[i][1];
            if(rowMap.count(x))
                maxi=max(maxi,ds.unionBySize(i,rowMap[x]));
            if(colMap.count(y))
                maxi=max(maxi,ds.unionBySize(i,colMap[y]));
            rowMap[x]=i, colMap[y]=i;
        }

        if(ds.getNumberOfComps()==1) return maxi+1;
        pair<int,int> p=ds.getFirst2MaxCompsSize();
        return p.first+1+p.second;
    }
};

int main(){

return 0;
}