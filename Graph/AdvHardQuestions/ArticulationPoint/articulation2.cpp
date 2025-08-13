#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    void DFS(int node,vector<int> &tin,vector<int> &low,int &timer,
             vector<vector<int>> &adj,unordered_set<int> &cutVertices,int parent=-1){
                 tin[node]=low[node]=timer++;
                 int child=0;
                 for(int &neighbor:adj[node]){
                     if(neighbor==parent) continue;
                     if(tin[neighbor]==-1)
                     {
                         DFS(neighbor,tin,low,timer,adj,cutVertices,node);
                         low[node]=min(low[node],low[neighbor]);
                         child++;
                         if(parent!=-1 && low[neighbor]>=tin[node])
                             cutVertices.insert(node);
                     }
                         else low[node]=min(low[node],tin[neighbor]);
                 }
                 if(parent==-1 && child>1) cutVertices.insert(node);
             }
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(vector<int> edge:edges){
            int u=edge[0],v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<int> tin(V,-1),low(V,-1);
        int timer=0;
        unordered_set<int> cutVertexSet;
        for(int v=0;v<V;v++)
            if(tin[v]==-1) DFS(v,tin,low,timer,adjList,cutVertexSet);
        
        if(!cutVertexSet.size()) return {-1};
        vector<int> cutVertices;
        cutVertices.insert(cutVertices.begin(),cutVertexSet.begin(),cutVertexSet.end());
        return cutVertices;
    }
};

int main(){

return 0;
}