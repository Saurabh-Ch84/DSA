#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//This was asked in sprinklr's OA for my internship for k=1
class Solution {
    static bool comp(const pair<long long,long long>&a,const pair<long long,long long>&b){
        return a.first-a.second < b.first-b.second;
    }
    
    long long memoization(int node,int isParentEdgeRemoved,int parent,int k,
                   vector<vector<pair<int,int>>> &adjList,vector<vector<long long>> &dp)
    {
        if(dp[node][isParentEdgeRemoved]!=-1) return dp[node][isParentEdgeRemoved];
        int edgesToRemove=max(0,(int)adjList[node].size()-k-isParentEdgeRemoved);
        long long answer=0;
        vector<pair<long long,long long>> candidates;
        for(const pair<int,int> &edge:adjList[node]){
            int neighbor=edge.first,weight=edge.second;
            if(neighbor!=parent)
            {
                long long notRemove=memoization(neighbor,0,node,k,adjList,dp)+weight;
                long long remove=memoization(neighbor,1,node,k,adjList,dp);
                candidates.push_back({notRemove,remove});
            }
        }
        
        sort(candidates.begin(),candidates.end(),comp);
        
        for (int i = 0; i < (int)candidates.size(); i++) {
            long long notRemove = candidates[i].first;
            long long remove = candidates[i].second;
            if (i < edgesToRemove) answer += remove;
            else answer += max(notRemove, remove);
        }
        return dp[node][isParentEdgeRemoved] = answer;
    }
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int V=edges.size()+1;
        vector<vector<pair<int,int>>> adjList(V);
        for(const vector<int> &edge:edges){
            int u=edge[0],v=edge[1],wt=edge[2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        vector<vector<long long>>dp(V, vector<long long>(2, -1));
        return memoization(0,0,-1,k,adjList,dp);
    }
};

int main(){

return 0;
}