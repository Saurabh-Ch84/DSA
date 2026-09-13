#include<iostream>
#include<vector>
using namespace std;

// User function Template for C++

class Solution {
    void DFS(int node,int &timer,vector<int>& tin,vector<int> &low,
            vector<int> adj[],
            vector<bool> &articulationPoints,int parent=-1){
                tin[node]=low[node]=timer++;
                int child=0;
                for(int &neighbor:adj[node]){
                    if(neighbor==parent) continue;
                    if(tin[neighbor]==-1){
                        DFS(neighbor,timer,tin,low,adj,articulationPoints,node);
                        low[node]=min(low[node],low[neighbor]);
                        if(parent!=-1 && low[neighbor]>=tin[node]){
                            articulationPoints[node]=true;
                        }
                        child++;
                    }
                    else low[node]=min(low[node],tin[neighbor]);
                }
                if(parent==-1 && child>1) 
                    articulationPoints[node]=true;
            }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int> tin(V,-1),low(V,-1);
        int timer=0;
        vector<bool> isArticulationPoint(V);
        
        for(int v=0;v<V;v++)
            if(tin[v]==-1)
                DFS(v,timer,tin,low,adj,isArticulationPoint);

        vector<int> answer;
        for(int v=0;v<V;v++)
            if(isArticulationPoint[v]) answer.push_back(v);
            
        if(answer.size()) return answer;
        return {-1};
    }
};

int main(){

return 0;
}