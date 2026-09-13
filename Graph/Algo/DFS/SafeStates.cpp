#include<iostream>
#include<vector>
using namespace std;

using vvi = vector<vector<int>> ;
using vi = vector<int> ;
using vb = vector<bool> ;

class Solution {
    bool DFS(int u,vvi &adjMatrix,vi &isSafeNode,vb &inStack){
        if(inStack[u]){
            isSafeNode[u]=-1;
            return false;
        }
        if(!adjMatrix[u].size()){
            isSafeNode[u]=1;
            return true;
        }
        
        inStack[u]=true;
        bool ans=true;
        for(int &v: adjMatrix[u]){
            bool nextAns;
            if(isSafeNode[v])
                nextAns=(isSafeNode[v]==1) ? true : false;
            else
                nextAns=DFS(v,adjMatrix,isSafeNode,inStack);
            ans=ans && nextAns;
        }
        inStack[u]=false;
        isSafeNode[u]=(ans)? 1 : -1;
        
        return ans;
    }
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vvi adjMatrix(V);
        for(vi &edge: edges){
            int u=edge[0],v=edge[1];
            adjMatrix[u].push_back(v);
        }

        vi isSafeNode(V,0);
        vb inStack(V,false);
        for(int u=0;u<V;u++){
            if(!isSafeNode[u]){
                DFS(u,adjMatrix,isSafeNode,inStack);
            }
        }
        
        vi res;
        for(int u=0;u<V;u++){
            if(isSafeNode[u]==1){
                res.push_back(u);
            }
        }
        
        return res;
    }
};

int main(){

return 0;
}