#include<bits/stdc++.h>
using namespace std;

/*
When to use inf (and 0 for the start node):
Specific Shortest Paths: If the problem asks, "What is the shortest path from Node A to Node B?", you must use inf. 
If you start everyone at 0, the algorithm loses the concept of starting at Node A. It will just find the cheapest 
path from your invisible dummy node, which will completely ruin your actual distance calculations.

Reachable Cycles Only: If the problem asks, "Is there a negative cycle reachable specifically from Node 0?", you must 
use inf. If a cycle exists in a disconnected part of the graph, you want your algorithm to ignore it.€
*/

class Solution {
    int inf=1e9;
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> dist(V,0);
        for(int relax=1;relax<=V-1;relax++){
            for(auto &edge: edges){
                int u=edge[0], v=edge[1], w=edge[2];
                if(dist[u]!=inf){
                    int d=dist[u]+w;
                    if(d<dist[v]) dist[v]=d;
                }
            }
        }
        for(auto &edge: edges){
            int u=edge[0], v=edge[1], w=edge[2];
            if(dist[u]!=inf){
                int d=dist[u]+w;
                if(d<dist[v]) return 1;
            }
        }   
        return 0;
    }
};


int main(){

return 0;
}