#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

// User function Template for C++
class Solution {
  public:
    int findCity1(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        
        vector<vector<int>> distM(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++) distM[i][i]=0;
        
        for(vector<int> &e:edges){
            distM[e[0]][e[1]]=e[2];
            distM[e[1]][e[0]]=e[2];
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(distM[i][k]!=1e9 && distM[k][j]!=1e9)
                        distM[i][j]=min(distM[i][j],distM[i][k]+distM[k][j]);
                }
            }
        }
        
        int countCity=n;
        int cityNo=-1;
        
        for(int city=0;city<n;city++){
            int count=0;
            for(int adjCity=0;adjCity<n;adjCity++){
                if(distM[city][adjCity]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=countCity){
                countCity=count;
                cityNo=city;
            }
        }
        return cityNo;
    }

    
    int findCity2(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int minReachable = n + 1;
        int cityNo = -1;

        // Run Dijkstra for each city
        for (int src = 0; src < n; ++src) {
            vector<int> dist(n, INT_MAX);
            dist[src] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, src});

            while (!pq.empty()) {
                pair<int, int> top = pq.top(); pq.pop();
                int d = top.first, u = top.second;
                if (d > dist[u]) continue;
                for (auto &vw : adj[u]) {
                    int v = vw.first, w = vw.second;
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            // Count reachable cities (including itself)
            int count = 0;
            for (int d : dist) {
                if (d <= distanceThreshold) count++;
            }

            // If tie, prefer the city with the larger number
            if (count <= minReachable) {
                minReachable = count;
                cityNo = src;
            }
        }
        return cityNo;
    }
};


int main(){

return 0;
}