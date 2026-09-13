#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// User function Template for C++
class Solution {
    void DFS(int u,vector<vector<pair<int,int>>> &adj,stack<int> &s,
            vector<bool> &v){
        v[u]=true;
        for(pair<int,int> p:adj[u])
            if(!v[p.first]) DFS(p.first,adj,s,v);
        s.push(u);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        int src=0;
        vector<vector<pair<int,int>>> adjList(V);
        for(vector<int> &v:edges)
            adjList[v[0]].push_back({v[1],v[2]});
            
        stack<int> topoStack;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
            if(!visited[i]) DFS(i,adjList,topoStack,visited);

        vector<int> distance(V,-1);
        distance[src]=0;
        while(!topoStack.empty()){
            int node=topoStack.top();
            int dist=distance[node];
            topoStack.pop();
            if(distance[node]==-1) continue;
            for(pair<int,int> neighbour:adjList[node])
            {
                if(distance[neighbour.first]==-1 || 
                    distance[neighbour.first]>neighbour.second+dist)
                    distance[neighbour.first]=neighbour.second+dist;
            }
        }
        return distance;
    }
};


int main(){

return 0;
}