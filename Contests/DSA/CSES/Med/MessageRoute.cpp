#include<bits/stdc++.h>
using namespace std;

void solve(int n,int m,vector<vector<int>> &connections){
    vector<vector<int>> adjList(n);
    for(int i=0;i<m;i++){
        int u=connections[i][0]-1, v=connections[i][1]-1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    queue<int> q;
    vector<int> visited(n,-1);
    q.push(0);
    visited[0]=0;
    int hops=0;

    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int u=q.front(); q.pop();
            if(u==n-1){
                int nodes=hops+1;
                cout<<nodes<<endl;
                vector<int> route(nodes,-1);
                int ptr=nodes-1, node=u;
                while(ptr!=-1){
                    route[ptr]=node+1;
                    node=visited[node];
                    ptr--;
                }
                for(int i=0;i<nodes;i++)
                    cout<<route[i]<<" ";
                return;
            }
            for(int &v: adjList[u]){
                if(visited[v]!=-1) continue;
                q.push(v);
                visited[v]=u;
            }
        }
        hops++;
    }
    cout<<"IMPOSSIBLE"<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> connections(m,vector<int>(2));
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>connections[i][j];
        }
    }
    solve(n,m,connections);
return 0;
}