#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using pii = pair<int,int>;
using pipii = pair<int,pii> ; 

class Solution {
    struct Comp{
        bool operator()(const pipii &a,const pipii &b) const{
            int distA=a.first;
            int distB=b.first;
            if(distA!=distB) return distA<distB;
            return a.second > b.second;
        }
    };  
    class DSU{
        vector<int> parent,size;
        int find(int node){
            if(node==parent[node]) return node;
            return parent[node]=find(parent[node]);
        }
            public:
        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }

        bool unionBySize(int u,int v){
            int U=find(u);
            int V=find(v);
            if(U==V) return false;
            if(size[U]<size[V]){
                size[V]+=size[U];
                parent[V]=U;
            }
            else{
                size[U]+=size[V];
                parent[U]=V;
            }
            return true;
        }
    };
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pipii> edges;
        for(int i=0;i<n;i++){
            int x1=points[i][0],y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0],y2=points[j][1];
                int manHatDist=abs(x2-x1)+abs(y2-y1);
                edges.push_back({manHatDist,{i,j}});
            }
        }
        sort(edges.begin(),edges.end(),Comp());
        DSU ds(n);
        int mstWeight=0;
        for(pipii &p: edges){
            int w=p.first,u=p.second.first,v=p.second.second;
            if(ds.unionBySize(u,v))
                mstWeight+=w;
        }
        return mstWeight;
    }
};

int main(){

return 0;
}