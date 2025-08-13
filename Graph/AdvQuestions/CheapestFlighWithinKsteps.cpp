#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

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