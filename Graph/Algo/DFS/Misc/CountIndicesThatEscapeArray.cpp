#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool DFS(int u,int n,vector<int> &arr,vector<int> &visited,int &count){   
        if(u>=n || u<=-1 || visited[u]==1) return 1;
        if(visited[u]!=-1) return 0;
        visited[u]=-2;
        bool ans=DFS(u+arr[u],n,arr,visited,count);
        if(ans) count++;
        return visited[u]=ans;
    }
  public:
    int goodIndices(vector<int> &arr) {
        // code here
        int n=arr.size(), count=0;
        vector<int> visited(n,-1); 
        // -2-> in-stack, -1->unknown, 0->bad, 1->good.
        for(int u=0;u<n;u++){
            if(visited[u]==-1) 
                DFS(u,n,arr,visited,count); 
        }
        return count;
    }
};

int main(){

return 0;
}