#include<bits/stdc++.h>
using namespace std;

int DFS(int p,int u,vector<int> &dp,vector<vector<int>> &adjList){
    if(dp[u]!=-1) return dp[u];
    int count=0;
    for(int &neighbor: adjList[u]){
        if(neighbor==p) continue;
        count=count+1+DFS(u,neighbor,dp,adjList);
    }
    return dp[u]=count;
}

void solve(int n,vector<int> &parents){
    vector<vector<int>> adjList(n);
    for(int i=0;i<n-1;i++){
        int u=parents[i]-1, v=i+1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<int> dp(n,-1);
    for(int i=0;i<n;i++){
        cout<<DFS(-1,i,dp,adjList)<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> parents(n-1);
    for(int i=0;i<n-1;i++)
        cin>>parents[i];
    solve(n,parents);
return 0;
}