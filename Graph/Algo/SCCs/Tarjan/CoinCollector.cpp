#include<bits/stdc++.h>
using namespace std;

class Solution{
    int timer;
    using vint=vector<int>;
    using vll=vector<long long>;
    vector<vint> SCCs;
    void DFS(int u,vector<vint> &adj,vint &discovery,vint &lowest,vint &instack,stack<int> &orderStack){
        discovery[u]=lowest[u]=timer++;
        instack[u]=1;
        orderStack.push(u);
        for(int &v: adj[u]){
            if(discovery[v]==-1){
                DFS(v,adj,discovery,lowest,instack,orderStack);
                lowest[u]=min(lowest[u],lowest[v]);
            }
            else if(!instack[v]){
                continue;
            }
            else lowest[u]=min(lowest[u],discovery[v]);
        }
        if(lowest[u]==discovery[u]){
            int prev=-1;
            vector<int> SCC;
            while(prev!=u && !orderStack.empty()){
                prev=orderStack.top();
                SCC.push_back(prev);
                instack[prev]=0;
                orderStack.pop();
            }
            SCCs.push_back(SCC);
        }
    }
    void createDAG(int N,int n,int m,vector<pair<int,int>> &tunnels,vint &coins,vll &totalCoins,vector<vint> &newAdj){
        vint idOfSCC(n,-1);
        for(int i=0;i<N;i++){
            int k=SCCs[i].size();
            for(int j=0;j<k;j++){
                int u=SCCs[i][j];
                totalCoins[i]+=coins[u];
                idOfSCC[u]=i;
            }
        }
        for(int i=0;i<m;i++){
            int u=tunnels[i].first-1, v=tunnels[i].second-1;
            int U=idOfSCC[u], V=idOfSCC[v];
            if(U!=V) newAdj[U].push_back(V);
        }
    }
        public:
    long long solve(int n,int m,vector<int> &coins,vector<pair<int,int>> &tunnels){
        // Create Graph
        vector<vint> adj(n);
        for(int i=0;i<m;i++){
            int u=tunnels[i].first-1, v=tunnels[i].second-1;
            adj[u].push_back(v);
        }
        // Find SCCs
        timer=0;
        SCCs.clear();
        vint discovery(n,-1), lowest(n,-1), instack(n,0);
        stack<int> orderStack;
        for(int u=0;u<n;u++){
            if(discovery[u]==-1)
                DFS(u,adj,discovery,lowest,instack,orderStack);
        }
        // Create DAG on SCCs
        int N=SCCs.size();
        vll totalCoins(N,0);
        vector<vint> newAdj(N);
        createDAG(N,n,m,tunnels,coins,totalCoins,newAdj);
        // DFS+DP
        vll dp(N,0);
        long long maxi=0;
        for (int u = 0; u < N; u++) {
            long long maxChildPath = 0;
            for (int &v : newAdj[u]) {
                maxChildPath = max(maxChildPath, dp[v]);
            }
            dp[u] = totalCoins[u] + maxChildPath;
            maxi = max(maxi, dp[u]);
        }
        return maxi;
    }
};

int main(){ 
    int n,m;
    cin>>n>>m;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
        cin>>coins[i];
    vector<pair<int,int>> tunnels(m);
    for(int i=0;i<m;i++)
        cin>>tunnels[i].first>>tunnels[i].second;
    Solution s;  
    cout<<s.solve(n,m,coins,tunnels);
return 0;
}