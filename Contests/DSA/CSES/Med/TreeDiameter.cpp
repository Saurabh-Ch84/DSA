#include<bits/stdc++.h>
using namespace std;

pair<int,int> DFS(int p,int u,vector<vector<int>> &adjList){
    pair<int,int> ans={0,u};
    for(int &v: adjList[u]){
        if(v==p) continue;
        pair<int,int> nextAns=DFS(u,v,adjList);
        if(nextAns.first+1>ans.first){
            ans.first=nextAns.first+1;
            ans.second=nextAns.second;
        }
    }
    return ans;
}

int solve(int n,vector<vector<int>> &edges){
    vector<vector<int>> adjList(n);
    for(auto &edge: edges){
        int u=edge[0]-1, v=edge[1]-1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int firstNode=DFS(-1,0,adjList).second;
    int diameter=DFS(-1,firstNode,adjList).first;
    return diameter;
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