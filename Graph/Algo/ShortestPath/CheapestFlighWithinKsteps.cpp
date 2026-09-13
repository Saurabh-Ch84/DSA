#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> temp=dist;
            for(vector<int> &flight: flights){
                int u=flight[0],v=flight[1],c=flight[2];
                if(dist[u]==INT_MAX) continue;
                if(dist[u]+c < temp[v])
                    temp[v]=dist[u]+c;
            }
            dist=temp;
        }
        return dist[dst]==INT_MAX? -1: dist[dst];
    }
};

 //
class Solution {
public:
   int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       unordered_map<int, vector<pair<int, int>>> adj;
        vector<int> distance(n, 1e8);
        distance[src] = 0;
        for(vector<int> &flight : flights)
            adj[flight[0]].push_back({flight[1], flight[2]});

        queue<pair<int, int>> BFSQueue;
        BFSQueue.push({src, 0});
        for(int stops = 0; stops <= k; stops++)
        {
            int size = BFSQueue.size();
            for(int i = 0; i < size; i++) // Process only nodes at the current level
            {
                int currentNode = BFSQueue.front().first;
                int currentPrice = BFSQueue.front().second;
                BFSQueue.pop();
                for(pair<int, int> &x : adj[currentNode])
                {
                    int newPrice = currentPrice + x.second;
                    if (distance[x.first]>newPrice)
                    {
                        distance[x.first] = newPrice;
                        BFSQueue.push({x.first, newPrice});
                    }
                }
            }
        }
        return (distance[dst] == 1e8) ? -1 : distance[dst];
    }
};

int main(){

return 0;
}