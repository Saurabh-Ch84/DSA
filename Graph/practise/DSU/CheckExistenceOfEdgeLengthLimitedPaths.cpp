#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using vvi = vector<vector<int>> ;
using vi = vector<int> ;

class Solution {
    struct Comp{
        bool operator()(const vi &a,const vi &b){
            return a[2]<b[2];
        }
    };

    class DSU{
        vector<int> parent,size;
            public:
        DSU(int n){
            size.assign(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }

        int find(int node){
            if(node==parent[node]) return node;
            return parent[node]=find(parent[node]);
        }

        void unionBySize(int u,int v){
            int U=find(u),V=find(v);
            if(U==V) return ;
            else if(size[U]<size[V]){
                parent[U]=V;
                size[V]+=size[U];
            }
            else{
                parent[V]=U;
                size[U]+=size[V];
            }
        }
    };
public:
    vector<bool> distanceLimitedPathsExist(int n,vvi &edgeList,vvi &queries) {
        int m=queries.size();
        for(int i=0;i<m;i++) 
            queries[i].push_back(i);

        sort(queries.begin(),queries.end(),Comp());
        sort(edgeList.begin(),edgeList.end(),Comp());

        vector<bool> res(m,false);
        int ptr=0,sz=edgeList.size();
        DSU ds(n);

        for(vi &query: queries){
            int u=query[0],v=query[1];
            int dist=query[2],idx=query[3];
            while(ptr<sz && edgeList[ptr][2]<dist){
                int u_=edgeList[ptr][0];
                int v_=edgeList[ptr][1];
                ds.unionBySize(u_,v_);
                ptr++;
            }
            res[idx]=(ds.find(u)==ds.find(v));
        }

        return res;
    }
};

int main(){

return 0;
}