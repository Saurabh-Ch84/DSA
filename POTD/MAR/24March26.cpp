#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    
    bool isToposortPossible(int n,vint &indegree,vvint &adjList){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indegree[i]) q.push(i);
        }
        vint toposort;
        while(!q.empty()){
            int u=q.front(); q.pop();
            toposort.push_back(u);
            for(int &v: adjList[u]){
                indegree[v]--;
                if(!indegree[v]){
                    q.push(v);
                }
            }
        }
        return (toposort.size()==n);
    }
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vint indegree(n,0);
        vvint adjList(n);
        for(vint &prerequisite: prerequisites){
            int x=prerequisite[0], y=prerequisite[1];
            indegree[x]++;
            adjList[y].push_back(x);
        }
        return isToposortPossible(n,indegree,adjList);
    }
};

int main(){

return 0;
}