#include<iostream>
#include<vector>
using namespace std;

using vi = vector<int> ;
using vb = vector<bool> ;
using pii= pair<int,int> ;

class Solution {
    pii DFS(int u,vb &visited,vector<vi> &adjM){
        // {dist, node};
        visited[u]=true;
        pii p={0,u};
        for(int &v: adjM[u]){
            if(visited[v]) continue;
            pii q=DFS(v,visited,adjM);
            q.first+=1;
            if(q.first>p.first){
                p.first=q.first;
                p.second=q.second;
            }
        }
        return p;
    }
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vi> adjM(V);
        vb visited1(V,false),visited2(V,false);
        
        for(vi &edge: edges){
            int u=edge[0],v=edge[1];
            adjM[u].push_back(v);
            adjM[v].push_back(u);
        }
        
        //find the one end of diameter.
        pii p=DFS(0,visited1,adjM);
        int u=p.second;
        
        //Find second end from the first end.
        pii q=DFS(u,visited2,adjM);
        int diameterOfGraph=q.first;
        return diameterOfGraph;
    }
};


int main(){

return 0;
}