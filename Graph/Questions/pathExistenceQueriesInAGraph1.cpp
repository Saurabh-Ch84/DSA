#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vbool=vector<bool>;
    using vint=vector<int>;
    using vvint=vector<vint>;
    class DSU{
        vint parent, size;
        int find(int u){
            if(parent[u]==u) return u;
            return parent[u]=find(parent[u]);
        }
            public:
        DSU(int n){
            size.resize(n,1);
            parent.resize(n,-1);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }

        void unionBySize(int u,int v){
            int U=find(u), V=find(v);
            if(U==V) return ;
            if(size[U]>size[V]){
                parent[V]=parent[U];
                size[U]+=size[V];
            }
            else{
                parent[U]=parent[V];
                size[V]+=size[U];
            }
        }

        bool areConnected(int u,int v){
            int U=find(u), V=find(v);
            return (U==V);
        }
    };
public:
    vbool pathExistenceQueries(int n,vint & nums, int maxDiff,vvint &queries) {
        DSU ds(n);
        int m=queries.size();
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff)
                ds.unionBySize(i-1,i);
        }
        vbool res(m,0);
        for(int i=0;i<m;i++){
            int u=queries[i][0], v=queries[i][1];
            res[i]=ds.areConnected(u,v);
        }
        return res;
    }
};

int main(){

return 0;
}