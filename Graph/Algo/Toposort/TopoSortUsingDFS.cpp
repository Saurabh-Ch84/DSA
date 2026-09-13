#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    void DFS(int u,vector<int> &visited,vector<vector<int>> &adj,stack<int> &topoSrt){
        visited[u]=1;
        for(int &v:adj[u])
            if(!visited[v]) DFS(v,visited,adj,topoSrt);
        topoSrt.push(u);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++)
            adj[edges[i][0]].push_back(edges[i][1]);
        
        stack<int> topoSrt;
        vector<int> topoArray(V,0);
        for(int i=0;i<V;i++)
            if(!topoArray[i]) DFS(i,topoArray,adj,topoSrt);
        
        for(int i=0;i<V;i++){
            topoArray[i]=topoSrt.top();
            topoSrt.pop();
        }
        return topoArray;
    }
};

int main(){

return 0;
}