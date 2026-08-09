#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    void dfs1(int u,vint &visited,vvint &adjList,vint &finishTime){
        visited[u]=1;
        for(int &v: adjList[u]){
            if(visited[v]) continue;
            dfs1(v,visited,adjList,finishTime);
        }
        finishTime.push_back(u);
    }
    void dfs2(int u,vint &visited,vvint &revAdjList){
        visited[u]=1;
        for(int &v: revAdjList[u]){
            if(visited[v]) continue;
            dfs2(v,visited,revAdjList);
        }
    }
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vvint adjList(V), revAdjList(V);
        for(auto &edge: edges){
            int u=edge[0], v=edge[1];
            adjList[u].push_back(v);
            revAdjList[v].push_back(u);
        }
        vint visited(V,0);
        vint finishTime;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs1(i,visited,adjList,finishTime);
            }
        }
        
        int countOfSCC=0;
        visited.assign(V,0);
        while(!finishTime.empty()){
            int u=finishTime.back(); 
            finishTime.pop_back();
            if(!visited[u]){
                dfs2(u,visited,revAdjList);
                countOfSCC++;
            }
        }
        return countOfSCC;
    }
};

int main(){

return 0;
}