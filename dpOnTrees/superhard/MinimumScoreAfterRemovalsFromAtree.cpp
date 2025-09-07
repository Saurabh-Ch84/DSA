#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Brute
    int minimumScore1(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adjList(n);
        for(vector<int> &edge : edges){
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int xorTotal = 0;
        for(int &ele : nums) {
            xorTotal ^= ele;
        }

        int minDiff = INT_MAX;
        
        // Loop through all unique pairs of edges to cut
        for(int i = 0; i < n - 1; i++){
            int u1 = edges[i][0];
            int v1 = edges[i][1];
            for(int j = i + 1; j < n - 1; j++){
                int u2 = edges[j][0];
                int v2 = edges[j][1];
                
                vector<bool> visited(n, false);
                vector<int> xorSums;

                // Find the first component's XOR sum
                xorSums.push_back(dfs(nums, adjList, visited, u1, {u1, v1}, {u2, v2}));

                // Find a starting point for the second component
                int nextStart = -1;
                for (int k = 0; k < n; ++k) {
                    if (!visited[k]) {
                        nextStart = k;
                        break;
                    }
                }

                // If a second component exists, calculate its XOR sum
                if (nextStart != -1) {
                    xorSums.push_back(dfs(nums, adjList, visited, nextStart, {u1, v1}, {u2, v2}));
                }

                // Calculate the third component's XOR sum using the total XOR
                int currentXORSum = 0;
                for(int sum : xorSums) {
                    currentXORSum ^= sum;
                }
                xorSums.push_back(xorTotal ^ currentXORSum);
                
                int maxi = *max_element(xorSums.begin(), xorSums.end());
                int mini = *min_element(xorSums.begin(), xorSums.end());
                minDiff = min(minDiff, maxi - mini);
            }
        }
        return minDiff;
    }
private:
    int dfs(const vector<int>& nums, const vector<vector<int>>& adjList, vector<bool>& visited, int u, 
            pair<int, int> e1, pair<int, int> e2) {
        int xorRes = nums[u];
        visited[u] = true;
        
        for(int node : adjList[u]){
            if(visited[node]) continue;
            
            // Define the edge being considered
            pair<int, int> p1 = {u, node};
            pair<int, int> p2 = {node, u};
            
            // Check if this edge is one of the "cut" edges
            if((p1 == e1 || p1 == e2) || (p2 == e1 || p2 == e2)) continue;
            
            xorRes ^= dfs(nums, adjList, visited, node, e1, e2);
        }
        return xorRes;
    }

    void DFS(vector<vector<int>> &adjMat,vector<int> &subTreeXOR,vector<int> &inTime,vector<int> &outTime,
            int &time,int u,int parent=-1)
    {
        inTime[u]=time++;
        for(int &v:adjMat[u]){
            if(v==parent) continue;
            DFS(adjMat,subTreeXOR,inTime,outTime,time,v,u);
            subTreeXOR[u]^=subTreeXOR[v];
        }
        outTime[u]=time++;
    }

    bool isAncestor(int i,int j,const vector<int> &inTime,const vector<int> &outTime){
        return (inTime[j]>inTime[i] && outTime[j]<outTime[i]);
    }

public:
    //optimal
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>> adjMat(n);
        for(vector<int> &edge:edges){
            int u=edge[0],v=edge[1];
            adjMat[u].push_back(v);
            adjMat[v].push_back(u);
        }
        vector<int> subTreeXOR=nums;
        vector<int> inTime(n),outTime(n);
        int time=0;
        DFS(adjMat,subTreeXOR,inTime,outTime,time,0);

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int xorA=subTreeXOR[i];
            for(int j=i+1;j<n;j++){
                int xorB=subTreeXOR[j];
                if(isAncestor(i,j,inTime,outTime))
                    xorA^=xorB;

                else if(isAncestor(j,i,inTime,outTime))
                    xorB^=xorA;

                int xorC=subTreeXOR[0]^xorA^xorB;
                int max_=max({xorA,xorB,xorC});
                int min_=min({xorA,xorB,xorC});
                ans=min(ans,max_-min_);
            }
        }
        return ans;
    }
};

int main(){

return 0;
}