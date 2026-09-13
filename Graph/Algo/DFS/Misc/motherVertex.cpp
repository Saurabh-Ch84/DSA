#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    void dfs(int u,vvint &adjList,vint &visited){
        if(visited[u]) return;
        visited[u]=1;
        for(int &v: adjList[u]){
            dfs(v,adjList,visited);
        }
    }
  public:
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        vvint adjList(V);
        for(vint &edge: edges){
            int u=edge[0], v=edge[1];
            adjList[u].push_back(v);
        }
        vint visited(V,0);
        int motherVertex;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adjList,visited);
                motherVertex=i;
            }
        }
        fill(visited.begin(),visited.end(),0);
        dfs(motherVertex,adjList,visited);
        for(int i=0;i<V;i++)
            if(!visited[i]) return -1;
        
        return motherVertex;
    }
};

int main(){

return 0;
}