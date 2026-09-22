#include <bits/stdc++.h>
using namespace std;

class Solution{
    int DFS(int u,vector<vector<int>> &adj,vector<int> &dp){
        if(dp[u]!=-1) return dp[u];
        int ans=0;
        for(int &v: adj[u]){
            int nextAns=1+DFS(v,adj,dp);
            if(nextAns>ans) ans=nextAns;
        }
        return dp[u]=ans;
    }
public:
    int solve(int n, int m, vector<vector<int>> &edges){
        vector<vector<int>> adj(n);
        for (auto &edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }
        int maxi = 0;
        vector<int> dp(n,-1);
        for (int u = 0; u < n; u++)
            maxi=max(maxi,DFS(u,adj,dp));
        return maxi;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        edges[i][0] = x - 1, edges[i][1] = y - 1;
    }
    Solution s;
    cout << s.solve(n, m, edges);
    return 0;
}