#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int DFS(int u,vvint &adjList){
        int ans=0;
        for(int &v: adjList[u]){
            int nextAns=1+DFS(v,adjList);
            ans=max(ans,nextAns);
        }
        return ans;
    }
    int binaryExponentiation(int base,int exp,int mod){
        base=base%mod;
        long long res=1;
        while(exp){
            if(exp&1) res=(res*base)%mod;
            exp=exp/2;
            base=(1LL*base*base)%mod;
        }
        return res%mod;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int m=edges.size()+1;
        vvint adjList(m);
        for(vint &edge: edges){
            int u=edge[0]-1, v=edge[1]-1;
            adjList[u].push_back(v);
        }
        int n=DFS(0,adjList), mod=1e9+7;
        return binaryExponentiation(2,n-1,mod);
    }
};

int main(){

return 0;
}