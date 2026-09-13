#include<iostream>
#include<bits/stdc++.h>
using namespace std;

using vvi= vector<vector<int>> ;
using vi= vector<int> ;

class Solution {
    int BFS(int i,vvi &adjMatrix,vi &distArr,vi &parent){
        int cycleLength=INT_MAX;
        queue<int> q;
        q.push(i);
        distArr[i]=0;
        
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int &v: adjMatrix[u]){
                if(v==parent[u]) continue;
                else if(distArr[v]==-1){
                    distArr[v]=distArr[u]+1;
                    parent[v]=u;
                    q.push(v);
                }
                else{
                    cycleLength=distArr[u]+distArr[v]+1;
                    return cycleLength;
                }
            }
        }
        
        return cycleLength;
    }
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vvi adjMatrix(V);
        for(vi &edge: edges){
            int u=edge[0],v=edge[1];
            adjMatrix[u].push_back(v);
            adjMatrix[v].push_back(u);
        }
        
        int minCycleLength=INT_MAX;
        for(int i=0;i<V;i++){
            vi distArr(V,-1),parent(V,-1);
            int cycleLength=BFS(i,adjMatrix,distArr,parent);
            minCycleLength=min(minCycleLength,cycleLength);
        }
        
        return (minCycleLength==INT_MAX)? -1: minCycleLength;
    }
};


int main(){

return 0;
}