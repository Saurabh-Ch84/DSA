#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    bool DFS(int i,vector<int> &v,vector<vector<int>> &adjL){
        if(v[i]==2) return true;
        v[i]=2;
        for(int &neighbour:adjL[i])
            if(DFS(neighbour,v,adjL)) return true;
        v[i]=1;
        return false;
    }


    bool BFS(vector<int> &ind,vector<vector<int>> &adjL){
        queue<int> q;
        int nodes=0;
        for(int i=0;i<ind.size();i++) 
            if(!ind[i]) q.push(i);
        while(!q.empty()){
            int node=q.front();
            nodes++;
            for(int &u:adjL[node]){
                ind[u]--;
                if(!ind[u]) q.push(u);
            }
            q.pop();
        }
        return nodes==ind.size();
    }
    
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adjL(V);
        for(int i=0;i<edges.size();i++)
            adjL[edges[i][0]].push_back(edges[i][1]);
            
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i])
                if(DFS(i,visited,adjL)) return true;
        }
        // if(!BFS(indegree,adjL)) return true;
        return false;
    }
};

int main(){

return 0;
}