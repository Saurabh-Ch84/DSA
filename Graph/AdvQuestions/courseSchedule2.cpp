#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using vi = vector<int> ;
class Solution {
    vi topoSort(int numCourses,vi &indegree,vector<vi> &adjList){
        queue<int> q;
        for(int i=0;i<numCourses;i++)
            if(indegree[i]==0) q.push(i);
        
        vector<int> result;
        while(!q.empty()){
            int u=q.front();q.pop();
            result.push_back(u);
            for(int &v: adjList[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return result.size()==numCourses? result : vector<int>();
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vi> adjList(numCourses);
        vi indegree(numCourses);
        for(vi &prerequisite: prerequisites){
            int a=prerequisite[0],b=prerequisite[1];
            adjList[b].push_back(a);
            indegree[a]++;
        }
        return topoSort(numCourses,indegree,adjList);
    }
};

int main(){

return 0;
}