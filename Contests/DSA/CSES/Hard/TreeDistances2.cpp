#include<bits/stdc++.h>
using namespace std;

long long dp[2*(int)1e5+1];
int subTreeSize[2*(int)1e5+1];

void downwardDFS(int p,int u,vector<vector<int>> &adjList){
    subTreeSize[u]=1;
    dp[u]=0;
    for(int &v: adjList[u]){
        if(v==p) continue;
        downwardDFS(u,v,adjList);
        dp[u]=dp[u]+dp[v]+subTreeSize[v];
        subTreeSize[u]=subTreeSize[u]+subTreeSize[v];
    }
}

void finalDFS(int n,int p,int u,vector<vector<int>> &adjList){
    for(int &v: adjList[u]){
        if(v==p) continue;
        dp[v]=dp[u]-subTreeSize[v]+(n-subTreeSize[v]);
        finalDFS(n,u,v,adjList);
    }
}

void solve(int n,vector<vector<int>> &edges){
    vector<vector<int>> adjList(n);
    for(auto &edge: edges){
        int u=edge[0]-1, v=edge[1]-1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    downwardDFS(-1,0,adjList);
    finalDFS(n,-1,0,adjList);
    for(int u=0;u<n;u++)
        cout<<dp[u]<<" ";
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> edges(n-1,vector<int>(2));
    for(int i=0;i<n-1;i++){
        for(int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }
    solve(n,edges);
return 0;
}