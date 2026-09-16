#include<bits/stdc++.h>
using namespace std;

class Solution1{
    pair<int,int> DFS(int u,vector<vector<int>> &adj,int p=-1){
        pair<int,int> ans={u,0};
        for(int &v: adj[u-1]){
            if(v==p) continue;
            pair<int,int> nextAns=DFS(v,adj,u);
            if(nextAns.second+1>ans.second){
                ans.second=nextAns.second+1;
                ans.first=nextAns.first;
            }
        }
        return ans;
    }
    pair<int,int> BFS(int src,vector<vector<int>> &adj){
        int n=adj.size();
        vector<bool> visited(n,0);
        queue<pair<int,int>> q;
        q.push({src,0});
        visited[src-1]=1;
        
        pair<int,int> ans={src,0};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto entry=q.front(); q.pop();
                int u=entry.first, dist=entry.second;
                if(dist>ans.second) ans=entry;
                for(int &v: adj[u-1]){
                    if(visited[v-1]) continue;
                    q.push({v,dist+1});
                    visited[v-1]=1;
                }
            }
        }
        return ans;
    }
  public:
    int partyHouse(vector<vector<int>> &adj) {
        // code here
        int firstEnd=BFS(1,adj).first;
        int diameter=BFS(firstEnd,adj).second;
        int ans=(diameter+1)/2;
        return ans;
    }
};

int main(){

return 0;
}