#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    bool DFS(int u,int x,vint &visited,vvint &adjList){
        if(visited[u]==x) return false; // visited in current DFS, so we don't need to visit it again.
        // visited in previous DFS, so we found a node that makes k non-deletable, so we can't delete any nodes.
        if(visited[u]!=0 && visited[u]==-x) return true; 
        visited[u]=x; // mark the node as visited in current DFS.
        bool ans=false;
        for(int &v: adjList[u]){
            ans=(ans||DFS(v,x,visited,adjList));
            if(ans) break; // even one node that makes k non-deletable, we can't delete any nodes.
        }
        return ans;
    }
public:
    vint remainingMethods(int n, int k,vvint &invocations) {
        vvint adjList(n);
        for(vint &invocation: invocations){
            int u=invocation[0], v=invocation[1];
            adjList[u].push_back(v);
        }
        vint visited(n,0);
        DFS(k,-1,visited,adjList); // for suspicious nodes, we mark them as -1, so that we can find them in the next DFS.
        bool isSuspiciousConnected=false;
        for(int i=0;i<n;i++){
            if(visited[i]!=-1 && DFS(i,1,visited,adjList)){
                // found a node 'i' that makes k non-deletable, we can't delete any nodes.
                isSuspiciousConnected=true;
                break;
            }
        }
        vint remainingMethods;
        // contains non-deletable nodes
        for(int i=0;i<n;i++){
            if(isSuspiciousConnected || visited[i]!=-1) // either k is non-deletable or the node is not suspicious, so we can keep it.
                remainingMethods.push_back(i);
        }
        return remainingMethods;
    }
};

class Solution2 {
    // better solution, we can just do a DFS from k and mark all the nodes that are reachable from k as suspicious.
    // Then we can check if any of the suspicious nodes have an edge to a non-suspicious node. 
    // If yes, then we can't delete any nodes. Otherwise, we can delete all the suspicious nodes.
    using vint=vector<int>;
    using vvint=vector<vint>;
    void DFS(int u,vint &isSuspicious,vvint &adjList){
        if(isSuspicious[u]) return ;
        isSuspicious[u]=1;
        for(int &v: adjList[u])
            DFS(v,isSuspicious,adjList);
    }
public:
    vint remainingMethods(int n, int k,vvint &invocations) {
        vvint adjList(n);
        for(vint &invocation: invocations){
            int u=invocation[0], v=invocation[1];
            adjList[u].push_back(v);
        }
        vint isSuspicious(n,0);
        DFS(k,isSuspicious,adjList);
        bool isNotDeletable=false;
        for(int i=0;i<n;i++){
            if(!isSuspicious[i]){
                for(int &v: adjList[i]){
                    if(isSuspicious[v]){
                        isNotDeletable=true;
                        break;
                    }
                }
            }
            if(isNotDeletable) break;
        }
        vint remainingMethods;
        for(int i=0;i<n;i++){
            if(isNotDeletable || !isSuspicious[i])
                remainingMethods.push_back(i);
        }
        return remainingMethods;
    }
};


int main(){

return 0;
}