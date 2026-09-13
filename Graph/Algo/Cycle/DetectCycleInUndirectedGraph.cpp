#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    bool DFS(int v,vector<vector<int>> &adjL,vector<bool> &visited,int parent=-1){
        visited[v]=true;
        for(int &u:adjL[v]){
            if(u==parent) continue;
            if(visited[u]) return true;
            if(DFS(u,adjL,visited,v)) return true;
        }
        return false;
    }
    bool BFS(int v,vector<vector<int>> &adjL,vector<bool> &visited,int parent=-1){
        queue<pair<int,int>> q;
        q.push({v,-1});
        visited[v]=true;
        while(!q.empty())
        {
            v=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(int &u:adjL[v])
            {
                if(u==parent) continue;
                if(visited[u]) return true;
                q.push({u,v});
                visited[u]=true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<bool> isVisited(V,0);
        vector<vector<int>> adjList(V);
        for(int i=0;i<edges.size();i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<V;i++){
            if(!isVisited[i]){
                // if(DFS(i,adjList,isVisited)) return true;
                if(BFS(i,adjList,isVisited)) return true;
            }
        }
        return false;
    }
};

int main(){

return 0;
}