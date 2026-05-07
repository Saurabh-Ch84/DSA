#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    class DSU{
        int n;
        vint parent, size;
        int find(int u){
            if(u==parent[u])
                return u;
            return parent[u]=find(parent[u]);
        }
            public:
        DSU(int n): n(n){
            size.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++) 
                parent[i]=i;
        }
        bool unionBySize(int u,int v){
            int U=find(u), V=find(v);
            if(U==V) return false;
            n--;
            if(size[U]>size[V]){
                size[U]+=size[V];
                parent[V]=U;
            }
            else{
                size[V]+=size[U];
                parent[U]=V;
            }
            return true;
        }
        int getNoOfComps(){
            return n;
        }
    };
public:
    vint findRedundantDirectedConnection(vvint &edges){
        int m=edges.size(), n=0;
        for(int i=0;i<m;i++)
            n=max({n,edges[i][0],edges[i][1]});

        for(int i=m-1;i>=0;i--){
            DSU ds(n);
            vint indegree(n,0);
            int count=0;
            for(int j=0;j<m;j++){
                if(i==j) continue;
                int u=edges[j][0]-1, v=edges[j][1]-1;
                if(!ds.unionBySize(u,v) || ++indegree[v]>1){
                    count=-1;
                    break;
                }
                if(indegree[v]==1) count++;
            }
            if(ds.getNoOfComps()==1 && count==n-1) 
                return edges[i];
        }
        return {-1,-1};
    }
};

int main(){

return 0;
}