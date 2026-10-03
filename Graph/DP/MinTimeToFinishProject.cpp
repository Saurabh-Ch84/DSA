#include<bits/stdc++.h>
using namespace std;

class Solution {
    int BFS(int n,vector<vector<int>> &adj,vector<int> &duration,vector<int> &indegree){
        queue<int> q;
        vector<int> dp(n);
        for(int u=0;u<n;u++){
            dp[u]=duration[u];
            if(!indegree[u]) q.push(u);
        }
        int count=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            count++;
            for(int &v: adj[u]){
                indegree[v]--;
                dp[v]=max(dp[v],dp[u]+duration[v]);
                if(!indegree[v]) q.push(v);
            }
        }
        if(count!=n) return -1;
        return *max_element(dp.begin(),dp.end());
    }
  public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        // code here
        int n=duration.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto &dependency: dependencies){
            int u=dependency[0], v=dependency[1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        return BFS(n,adj,duration,indegree);
    }
};

int main(){

return 0;
}