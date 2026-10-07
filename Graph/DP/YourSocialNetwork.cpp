#include<bits/stdc++.h>
using namespace std;

class Solution {
    void DFS(int u,int src,vector<vector<int>> &adj,vector<vector<vector<int>>> &reachablePairs,int dist){
        if(!reachablePairs[u].empty()){
            for(auto &pairsFromU: reachablePairs[u]){
                int v=pairsFromU[0], d=pairsFromU[1];
                reachablePairs[src].push_back({v,d+dist});
            }
            return ;
        }
        for(int &v: adj[u]){
            DFS(v,src,adj,reachablePairs,dist+1);
            reachablePairs[u].push_back({v,1});
        }
    }
  public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        // code here
        int m=arr.size(), n=m+1;
        vector<vector<int>> adj(n+1); // 1-based
        for(int i=0;i<m;i++){
            int u=i+2, v=arr[i];
            adj[u].push_back(v);
        }
        vector<vector<vector<int>>> reachablePairs(n+1);
        for(int u=2;u<=n;u++){
            DFS(u,u,adj,reachablePairs,0);
        }
        vector<vector<int>> res;
        for(int u=2;u<=n;u++){
            for(auto &pairsFromU: reachablePairs[u]){ 
                int v=pairsFromU[0], d=pairsFromU[1];
                res.push_back({u,v,d});
            }
        }
        return res;
    }
};

int main(){

return 0;
}