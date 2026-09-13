#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int> ;
using vvi = vector<vi> ;

class Solution {
    int DFS(int u,int p,vvi &adjList,vi &values,int k,int &ans){
        int sum=values[u];
        for(int &v: adjList[u]){
            if(v==p) continue;
            sum+=DFS(v,u,adjList,values,k,ans);
        }
        if(sum%k==0){
            ans++;
            return 0;
        }
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vvi &edges,vi &values, int k) {
        vvi adjList(n);
        for(vi &edge: edges){
            int u=edge[0],v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int ans;
        DFS(0,-1,adjList,values,k,ans);
        return ans;
    }
};

int main(){

return 0;
}