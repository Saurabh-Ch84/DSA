#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
    void DFS(int node,vector<int> &tin,vector<int> &low,vector<vector<int>> &adjList,
            set<pair<int,int>> &bridge,int &timer,int parent=-1){
                
            tin[node]=low[node]=timer++;
            for(int &neighbor:adjList[node])
            {
                if(neighbor==parent) continue;
                if(tin[neighbor]==-1)
                {
                    DFS(neighbor,tin,low,adjList,bridge,timer,node);
                    low[node]=min(low[node],low[neighbor]);
                    if(low[neighbor]>tin[node])
                        bridge.insert({node,neighbor});
                }
                else low[node]=min(low[node],tin[neighbor]);
            }
        }
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>> adjList(V);
        for(vector<int> &edge:edges)
        {
            int u=edge[0],v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        set<pair<int,int>> bridgeSet;
        vector<int> tin(V,-1),low(V,-1);
        int timer=0;
        for(int v=0;v<V;v++)
            if(tin[v]==-1) DFS(v,tin,low,adjList,bridgeSet,timer);
            
        return bridgeSet.count({c,d})|bridgeSet.count({d,c});
    }
};

int main(){

return 0;
}