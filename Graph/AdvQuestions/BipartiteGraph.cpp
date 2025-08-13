#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    bool BFS(int i,vector<int> &color,vector<vector<int>> &adj){
        queue<int> q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int &neighbour:adj[node])
            {
                if(color[neighbour]==-1)
                {
                    color[neighbour]=1-color[node];
                    q.push(neighbour);
                }
                else if(color[neighbour]==color[node]) return false;
            }
        }
        return true;
    }
    
    bool DFS(int i,vector<int> &color,vector<vector<int>> &adj,int col=0){
        if(color[i]!=-1) return color[i]==col;
        color[i]=col;
        for(int &neighbour:adj[i]) if(!DFS(neighbour,color,adj,1-col)) return false;
        return true;
    }
    
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> color(V,-1);
        vector<vector<int>> adjList(V);
        for(int i=0;i<edges.size();i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                // if(!BFS(i,color,adjList)) return false;
                if(!DFS(i,color,adjList)) return false;
            }
        }
        return true;
    }
};

int main(){

return 0;
}