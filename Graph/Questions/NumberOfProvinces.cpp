#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// User function Template for C++

class Solution {
    void DFS(vector<vector<int>> &adj,int v,vector<bool> &visited){
        visited[v]=true;
        for(int u=0;u<adj[v].size();u++){
            if(adj[v][u] && !visited[u])
                DFS(adj,u,visited);
        }
    }
    
    void BFS(vector<vector<int>> &adj,int v,vector<bool> &visited){
        queue<int> BFSq;
        BFSq.push(v);
        visited[v]=true;
        while(!BFSq.empty()){
            int V=BFSq.front();
            BFSq.pop();
            for(int u=0;u<adj[V].size();u++)
            {
                if(adj[V][u] && !visited[u])
                {
                    visited[u]=true;
                    BFSq.push(u);
                }
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> visited(V,false);
        int province=0;
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                // DFS(adj,i,visited);
                BFS(adj,i,visited);
                province++;
            }
        }
        return province;
    }
};

int main(){

return 0;
}