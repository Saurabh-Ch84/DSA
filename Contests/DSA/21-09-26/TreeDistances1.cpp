#include<bits/stdc++.h>
using namespace std;

class Solution{
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
    void BFS(int src,vector<vector<int>> &adjList,vector<int> &dist){
        queue<int> q;
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int &v: adjList[u]){
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
    }
        public:
    void solve(int n,vector<vector<int>> &edges){
        vector<vector<int>> adjList(n);
        for(auto &edge: edges){
            int u=edge[0]-1, v=edge[1]-1;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int firstNode=DFS(-1,0,adjList).second;
        int secondNode=DFS(-1,firstNode,adjList).second;

        vector<int> dist1(n,-1), dist2(n,-1);
        BFS(firstNode,adjList,dist1);
        BFS(secondNode,adjList,dist2);

        for(int u=0;u<n;u++){
            int d=max(dist1[u],dist2[u]);
            cout<<d<<" ";
        }
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> edges(n-1,vector<int>(2));
    for(int i=0;i<n-1;i++){
        for(int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }
    Solution s;
    s.solve(n,edges);
return 0;
}