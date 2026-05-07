#include<bits/stdc++.h>

using namespace std;
using vint=vector<int>;
using vvint=vector<vint>;

class Solution{
    vvint adjList;
    vint visited;
    void DFS(int u){
        visited[u]=1;
        for(int &v: adjList[u]){
            if(visited[v]) continue;
            DFS(v);
        }
    }
        public:
    void set(vvint &edges,int n){
        adjList.resize(n);
        for(vint &edge: edges){
            int u=edge[0]-1, v=edge[1]-1;
            adjList[u].push_back(v);
        }
        visited.resize(n,0);
    }
    int findAns(){
        DFS(0);
        int count=0, n=visited.size();
        for(int i=0;i<n;i++){
            if(visited[i]) count++;
        }
        return count;
    }
};

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        Solution s;
        int n,e;
        cin>>n>>e;
        vvint edges(e);
        for(int i=0;i<e;i++){
            int u,v;
            cin>>u>>v;
            edges[i]={u,v};
        }
        s.set(edges,n);
        cout<<s.findAns()<<endl;
    }
return 0;
}