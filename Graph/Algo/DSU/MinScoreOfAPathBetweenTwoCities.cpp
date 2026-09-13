#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    class DSU{
            public:
        int n;
        vint parent, size, parentScore;
        DSU(int n): n(n){
            size.resize(n,1);
            parent.resize(n,-1);
            parentScore.resize(n,1e9);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
        int find(int u){
            if(parent[u]==u) return u;
            return parent[u]=find(parent[u]);
        }
        void unionBySize(int u,int v,int w){
            int U=find(u), V=find(v);
            if(U==V){
                parentScore[U]=min(parentScore[U],w);
                return ;
            }
            if(size[U]>size[V]){
                size[U]+=size[V];
                parent[V]=U;
                parentScore[U]=min({parentScore[U],parentScore[V],w});
                parentScore[V]=1e9;
            }
            else{
                size[V]+=size[U];
                parent[U]=V;
                parentScore[V]=min({parentScore[V],parentScore[U],w});
                parentScore[U]=1e9;
            }
        }
        int minScore(int s,int d){
            int S=find(s), D=find(d);
            if(S!=D) return -1;
            return parentScore[S];
        }
    };
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU ds(n);
        for(vint &road: roads){
            int u=road[0]-1, v=road[1]-1, w=road[2];
            ds.unionBySize(u,v,w);
        }
        return ds.minScore(0,n-1);
    }
};

int main(){

return 0;
}