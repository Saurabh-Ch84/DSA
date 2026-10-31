#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;

// User Function Template
class Solution {

    //Using Priority Queue
    vector<int> fun1(vector<vector<pair<int,int>>> &adj,int src,int V){
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        minHeap.push({0,src});
        vector<int> distance(V,1e7);
        distance[src]=0;
        while(!minHeap.empty()){
            int u=minHeap.top().second;
            int distU=minHeap.top().first;
            minHeap.pop();
            for(pair<int,int> v:adj[u])
            {
                int neighbor=v.first;
                int weight=v.second;
                if(distU + weight < distance[neighbor])
                {
                    distance[neighbor] = distU + weight;
                    minHeap.push({distance[neighbor], neighbor});
                }
            }
        }
        return distance;
    }

    //Using Sets
    vector<int> fun2(vector<vector<pair<int,int>>> &adj,int src,int V){
        
        set<pair<int,int>> minSet;
        minSet.insert({0,src});
        vector<int> distance(V,1e7);
        distance[src]=0;
        while(!minSet.empty()){
            auto itr=*(minSet.begin());
            int u=itr.second;
            int distU=itr.first;
            minSet.erase(itr);
            for(auto it:adj[u])
            {
                int neighbor=it.first;
                int weight=it.second;
                if(distU + weight < distance[neighbor])
                {
                    if(distance[neighbor]!=1e7) 
                        minSet.erase({distance[neighbor],neighbor});
                    distance[neighbor] = distU + weight;
                    minSet.insert({distance[neighbor], neighbor});
                }
            }
        }
        return distance;
    }
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adjList(V);
        for(vector<int> &e:edges)
        {
            adjList[e[0]].push_back({e[1],e[2]});
            adjList[e[1]].push_back({e[0],e[2]});
        }
        return fun1(adjList,src,V);
    }
};

int main(){

return 0;
}