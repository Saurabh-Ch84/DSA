#include<bits/stdc++.h>
using namespace std;


class TreeAncestor{
    int n, m;
    vector<vector<int>> ancestor;
    vector<int> depth;
    void initialDFS(vector<vector<int>> &adj,int u,int d=0){
        depth[u]=d;
        for(int &v: adj[u])
            initialDFS(adj,v,d+1);
    }
        public:
    TreeAncestor(vector<int> &parents){
        n=parents.size(), m=ceil(log2(n))+1;
        ancestor.resize(n,vector<int>(m,-1));
        vector<vector<int>> adj(n);
        for(int u=0;u<n;u++){
            ancestor[u][0]=parents[u];
            int p=ancestor[u][0];
            if(p!=-1) adj[p].push_back(u);
        }
        for(int j=1;j<m;j++){
            for(int u=0;u<n;u++){
                if(ancestor[u][j-1]!=-1){
                    ancestor[u][j]=ancestor[ancestor[u][j-1]][j-1];
                }
            }
        }

        depth.resize(n,-1);
        initialDFS(adj,0);
    }
    int getKthAncestor(int u,int k){
        for(int j=0;j<m;j++){
            if(k & (1<<j)){
                u=ancestor[u][j];
                if(u==-1) return -1;
            }
        }
        return u;
    }
    int getLCA(int u,int v){
        if(depth[u]<depth[v]) 
            swap(u,v);
        int k=depth[u]-depth[v];
        u=getKthAncestor(u,k);
        if(u==v) return u;
        for(int j=m-1;j>=0;j--){
            if(ancestor[u][j]!=ancestor[v][j]){
                u=ancestor[u][j];
                v=ancestor[v][j];
            }
        }
        return ancestor[u][0];
    }
};

int main(){

return 0;
}