#include<bits/stdc++.h>
using namespace std;

class Solution {
    int inf=1e9;
    void BFS(int src,vector<vector<int>> &adjList,vector<int> &visitTime){
        int time=0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int u=q.front(); q.pop();
                visitTime[u]=time;
                for(int &v: adjList[u]){
                    q.push(v);
                }
            }
            time++;
        }
    }
    int DFS(int u,vector<int> &visitTimeBob,vector<int> &visitTimeAlice,vector<vector<int>> &adjList,vector<int> &amount){
        int currCost=0;
        if(visitTimeAlice[u]<visitTimeBob[u])
            currCost+=amount[u];
        else if(visitTimeAlice[u]==visitTimeBob[u])
            currCost+=amount[u]/2;
        if(adjList[u].empty()) return currCost;
        int cost=-inf;
        for(int &v: adjList[u]){
            int nextCost=currCost+DFS(v,visitTimeBob,visitTimeAlice,adjList,amount);
            cost=max(cost,nextCost);
        }
        return cost;
    }
    void BuildGrapDFS(int u,vector<vector<int>> &adjList,vector<int> &childToParent,int p=-1){
        childToParent[u]=p;
        for(int &v: adjList[u]){
            // if v==0 then don't visit.
            if(!v || childToParent[v]!=-1) continue;
            BuildGrapDFS(v,adjList,childToParent,u);
        }
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size(), alice=0;
        vector<vector<int>> adjList(n);
        for(auto &edge: edges){
            int u=edge[0], v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> childToParent(n,-1);
        BuildGrapDFS(0,adjList,childToParent);

        vector<vector<int>> adjList1(n), adjList2(n);
        for(int i=0;i<n;i++){
            int u=childToParent[i], v=i;
            if(u==-1) continue;
            adjList1[u].push_back(v);
            adjList2[v].push_back(u);
        }

        vector<int> visitTimeBob(n,inf);
        BFS(bob,adjList2,visitTimeBob);

        vector<int> visitTimeAlice(n,inf);
        BFS(alice,adjList1,visitTimeAlice);

        return DFS(alice,visitTimeBob,visitTimeAlice,adjList1,amount);
    }
};

int main(){

return 0;
}