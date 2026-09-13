#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pii = pair<int,int> ;
using vpii = vector<pii> ;
using vvpii = vector<vpii> ;

class Solution {
    struct Comp{
        bool operator()(const vi &a,const vi &b){
            return a[2]<b[2];
        }
    };

    class DSU{
        int n,comps;
        vector<int> parent,size;
        
        int find(int node){
            if(parent[node]==node) return node;
            return parent[node]=find(parent[node]);
        }
        
        void init(){
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
            public:
        DSU(int n){
            this->n=n;
            comps=n;
            size.resize(n,1);
            parent.resize(n);
            init();
        }
        
        bool unionBySize(int u,int v){
            int U=find(u),V=find(v);
            if(U==V) return false;
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
        
        void reset(){
            comps=n;
            fill(size.begin(),size.end(),1);
            init();
        }
        
        int numOfComps(){
            return comps;
        }
    };
    
  public:
    int secondMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),Comp());
        DSU ds(V);
        int mstWeight=0,E=edges.size();
        vi mstEdges;
        
        for(int i=0;i<E;i++){
            int u=edges[i][0],v=edges[i][1];
            int w=edges[i][2];
            if(ds.unionBySize(u,v)){
                mstEdges.push_back(i);
                mstWeight+=w;
            }
        }
        if(ds.numOfComps()!=1) return -1;
        
        int mstSecWeight=INT_MAX,e=mstEdges.size();
        for(int i=0;i<e;i++){
            ds.reset();
            int idxOfUsedEdge=mstEdges[i],weight=0;
            for(int j=0;j<E;j++){
                if(j==idxOfUsedEdge) continue;
                int u=edges[j][0],v=edges[j][1];
                int w=edges[j][2];
                if(ds.unionBySize(u,v)) weight+=w;
            }
            
            if(ds.numOfComps()==1 && weight>mstWeight)
                mstSecWeight=min(mstSecWeight,weight);
        }

        return mstSecWeight==INT_MAX ? -1: mstSecWeight;
    }
};

int main(){

return 0;
}