#include<bits/stdc++.h>
using namespace std;

class Solution {
    void BFS(int src,vector<vector<pair<int,int>>> &adjList,vector<int> &distance){
        queue<pair<int,int>> q;
        q.push({src,0});
        distance[src]=0;
        while(!q.empty()){
            pair<int,int> a=q.front(); q.pop();
            int u=a.first, w=a.second;
            for(auto &b: adjList[u]){
                int v=b.first, w_=w+b.second;
                if(w_>distance[v]){
                    distance[v]=w_;
                    q.push({v,distance[v]});
                }
            }
        }
    }
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int,int>>> adjList(V);
        for(auto &e: edges){
            int u=e[0], v=e[1], w=e[2];
            adjList[u].push_back({v,w});
        }
        vector<int> distance(V,INT_MIN);
        BFS(src,adjList,distance);
        return distance;
    }
};

int main(){

return 0;
}