#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    vector<int> fun(vector<vector<pair<int,int>>> &adj,int s,int V){
        vector<int> distance(V+1,1e8);
        distance[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        vector<int> parent(V+1,-1);
        while(!pq.empty())
        {
            int u=pq.top().second;
            int distU=pq.top().first;
            pq.pop();
            for(pair<int,int> p:adj[u])
            {
                int v=p.first,weight=p.second;
                if(distance[v]>weight+distU)
                {
                    parent[v]=u;
                    distance[v]=weight+distU;
                    pq.push({distance[v],v});
                }
            }
        }
        if(distance[V]==1e8) return {-1};
        vector<int> path;
        int node=V;
        path.push_back(distance[V]);
        while(node!=-1)
        {
            path.push_back(node);
            node=parent[node];
        }
        reverse(path.begin()+1,path.end());
        return path;
    }
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
    {
        // Code here
        int src=1;
        vector<vector<pair<int,int>>> adjList(n+1);
        for(vector<int> &e:edges)
        {
            adjList[e[0]].push_back({e[1],e[2]});
            adjList[e[1]].push_back({e[0],e[2]});
        }
        return fun(adjList,src,n);
    }
};

int main(){

return 0;
}