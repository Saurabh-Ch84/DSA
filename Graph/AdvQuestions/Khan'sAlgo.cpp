#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    vector<int> BFS(vector<vector<int>>&adjL,vector<int> &indegree){
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
            if(!indegree[i]) q.push(i);

        while(!q.empty())
        {
            int node=q.front();
            ans.push_back(node);
            for(int v:adjL[node])
            {
                indegree[v]--;
                if(!indegree[v]) q.push(v);
            }
            q.pop();
        }
        return ans;
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjL(V);
        vector<int> indegree(V,0),topoSort;
        for(int i=0;i<edges.size();i++)
        {
            adjL[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        vector<int> res=BFS(adjL,indegree);
        if(res.size()!=V) return {};
        return res;
    }
};

int main(){

return 0;
}