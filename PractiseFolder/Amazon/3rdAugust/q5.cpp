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

        bool unionBySize(int u,int v){
            int U=find(u);
            int V=find(v);
            if(U==V) return false;
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
    };

    bool DSUhelper(int n, int m, vector<vector<int>> &adj){
        DSU ds(n);
        for(int i=0;i<m;i++)
            if(!ds.unionBySize(adj[i][0],adj[i][1])) return false;
        int root=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                root++;
                if(root>1) return false;
            }
        }
        return true;
    }

    bool DFS(vector<vector<int>> &adjL,vector<bool> &vis,int node,int parent=-1){
        vis[node]=true;
        for(int &neighbor:adjL[node]){
            if(!vis[neighbor]){
                if(!DFS(adjL,vis,neighbor,node)) return false;
            }
            else if(neighbor!=parent) return false;
        }
        return true;
    }

    bool DFShelper(int n, int m, vector<vector<int>> &adj) {
        // code here
        vector<vector<int>> adjList(n);
        for(int i=0;i<m;i++){
            adjList[adj[i][0]].push_back(adj[i][1]);
            adjList[adj[i][1]].push_back(adj[i][0]);
        }
        int root=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                root++;
                if(!DFS(adjList,visited,i) || root>1) return false;
            }
        }
        return true;
    }
        public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        // return DSUhelper(n,m,adj);
        return DFShelper(n,m,adj);
    }
};


int main(){

return 0;
}