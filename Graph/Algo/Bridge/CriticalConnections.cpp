#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void DFS(int node,vector<vector<int>> &adjList,vector<int> &tin,vector<int> &low,
             vector<vector<int>> &criticalEdge,int &timer,int parent=-1){

            tin[node]=low[node]=timer++;
            for(int &neighbor:adjList[node]){
                if(neighbor==parent) continue;
                if(!tin[neighbor]){
                    DFS(neighbor,adjList,tin,low,criticalEdge,timer,node);
                    low[node]=min(low[node],low[neighbor]);
                    if(low[neighbor]>tin[node]){
                        criticalEdge.push_back({node,neighbor});
                    }
                }
                else low[node]=min(low[node],tin[neighbor]);
            }
        }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for(vector<int> &link:connections){
            int u=link[0],v=link[1];
            adjList[v].push_back(u);
            adjList[u].push_back(v);
        }
        int totalEdge=connections.size();
        vector<vector<int>> criticalEdge;
        vector<int> tin(n,0),low(n,0);
        int timer=1;
        for(int v=0;v<n;v++)
            if(!tin[v]) DFS(v,adjList,tin,low,criticalEdge,timer);
        return criticalEdge;
    }
};

int main(){

return 0;
}