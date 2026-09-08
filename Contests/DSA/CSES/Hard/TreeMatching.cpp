#include<bits/stdc++.h>
using namespace std;

int dp[2*(int)1e5+1][2];
void DFS(int p,int u,vector<vector<int>> &adjList){
    int optimalSumOfChildren=0;
    for(int &v: adjList[u]){
        if(v==p) continue;
        DFS(u,v,adjList);
        optimalSumOfChildren+=max(dp[v][0],dp[v][1]);
    }   
    dp[u][0]=optimalSumOfChildren;
    dp[u][1]=0;
    for(int &v: adjList[u]){
        if(v==p) continue;
        int chooseV=optimalSumOfChildren-max(dp[v][0],dp[v][1])+dp[v][0]+1;
        dp[u][1]=max(dp[u][1],chooseV);
    }
}

int solve(int n,vector<vector<int>> &edges){
    vector<vector<int>> adjList(n);
    for(auto &edge: edges){
        int u=edge[0]-1, v=edge[1]-1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    DFS(-1,0,adjList);
    return max(dp[0][0],dp[0][1]);
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
    cout<<solve(n,edges);
return 0;
}