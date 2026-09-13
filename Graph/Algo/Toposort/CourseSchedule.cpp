#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    bool BFS(int n,vector<vector<int>> &adjL,vector<int> &ind){
        queue<int> q;
        for(int i=0;i<n;i++)
            if(!ind[i]) q.push(i);

        int count=0;
        while(!q.empty())
        {
            int v=q.front();
            count++;
            q.pop();
            for(int &u:adjL[v]){
                ind[u]--;
                if(!ind[u]) q.push(u);
            }
        }
        return count==n;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adjlist(numCourses);
        for(vector<int> &itrV:prerequisites)
        {
            adjlist[itrV[1]].push_back(itrV[0]);
            indegree[itrV[0]]++;
        }
        return BFS(numCourses,adjlist,indegree);
    }
};

int main(){

return 0;
}