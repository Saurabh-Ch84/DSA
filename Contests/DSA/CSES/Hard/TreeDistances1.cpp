#include<bits/stdc++.h>
using namespace std;

int farthest[(int)1e5*2+1];
int farthestNode[(int)1e5*2+1];
int secondFarthest[(int)1e5*2+1];
int up[(int)1e5*2+1];

void downwardDFS(int p,int u,vector<vector<int>> &adjList){
    farthest[u]=0, secondFarthest[u]=0;
    for(int &v: adjList[u]){
        if(v==p) continue;
        downwardDFS(u,v,adjList);
        int currDist=1+farthest[v];
        if(currDist>farthest[u]){
            secondFarthest[u]=farthest[u];
            farthest[u]=currDist;
            farthestNode[u]=v;
        }
        else if(currDist>secondFarthest[u]){
            secondFarthest[u]=currDist;
        }
    }
}

void finalDFS(int p,int u,vector<vector<int>> &adjList){
    for(int &v: adjList[u]){
        if(v==p) continue;
        int bestVShapedPath=(v==farthestNode[u]? secondFarthest[u]:farthest[u]);
        int maxPathOutsideSubTree=max(up[u],bestVShapedPath);
        up[v]=1+maxPathOutsideSubTree;
        finalDFS(u,v,adjList);
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
    up[0]=0;
    finalDFS(-1,0,adjList);
    for(int u=0;u<n;u++){
        cout<<max(farthest[u],up[u])<<" ";
    }
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