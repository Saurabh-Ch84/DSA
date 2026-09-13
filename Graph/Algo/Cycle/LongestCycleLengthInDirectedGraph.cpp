#include<iostream>
#include<vector>
using namespace std;

using vb = vector<bool> ;
using vi = vector<int> ;

class Solution {
    void DFS(int u,vi &edges,vb &visited,vb &inStack,vi &distArr,int &maxCycleLength){
        visited[u]=true; inStack[u]=true;
        int v=edges[u];
        if(v!=-1){
            if(!visited[v]){
                distArr[v]=distArr[u]+1;
                DFS(v,edges,visited,inStack,distArr,maxCycleLength);
            }
            else if(inStack[v]){
                int cycleLength=distArr[u]-distArr[v]+1;
                maxCycleLength=max(maxCycleLength,cycleLength);
            }
        }
        inStack[u]=false;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size(),maxCycleLength=-1;
        vb visited(n,false),inStack(n,false);
        vi distArr(n,1);

        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            DFS(i,edges,visited,inStack,distArr,maxCycleLength);
        }
        return maxCycleLength;
    }
};

int main(){

return 0;
}