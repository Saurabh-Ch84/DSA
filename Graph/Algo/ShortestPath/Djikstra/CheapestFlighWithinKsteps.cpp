#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;

class Solution1 {
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
class Solution2 {
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

class Solution3 {
    using tuple3_t=tuple<int,int,int>;
    using minheap_t=priority_queue<tuple3_t,vector<tuple3_t>,greater<tuple3_t>>;
    int Djisktra(int src,int dst,vector<vector<pair<int,int>>> &adj,int n,int k){
        int inf=1e9;
        vector<vector<int>> dist(n,vector<int>(k+1,inf));
        dist[src][0]=0;
        minheap_t minHeap;
        minHeap.push({0,0,src});

        while(!minHeap.empty()){
            auto entry=minHeap.top(); minHeap.pop();
            int uPrice=get<0>(entry), uFlight=get<1>(entry), u=get<2>(entry);
            for(auto &p: adj[u]){
                int v=p.first, vPrice=p.second+uPrice, vFlight=1+uFlight;
                if(vFlight<=k && dist[v][vFlight]>vPrice){
                    dist[v][vFlight]=vPrice;
                    minHeap.push({dist[v][vFlight],vFlight,v});
                }
            }
        }

        int mini=inf;
        for(int i=0;i<=k;i++)
            mini=min(mini,dist[dst][i]);
        
        return (mini==inf? -1:mini);
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,int src,int dst,int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &flight: flights){
            int u=flight[0], v=flight[1], p=flight[2];
            adj[u].push_back({v,p});
        }
        return Djisktra(src,dst,adj,n,k+1); // k-> intermediate steps excluding final destination.
    }
};

int main(){

return 0;
}