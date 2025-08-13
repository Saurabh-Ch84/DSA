#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// User function Template for C++

class Solution {
    class DSU{
            public:
        vector<int> parent,size;
        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++) parent[i]=i;
        }
        int find(int u){
            if(u==parent[u]) return u;
            return parent[u]=find(parent[u]);
        }
        int unionBySize(int u,int v){
            int U=find(u);
            int V=find(v);
            if(U==V) return size[U];
            if(size[U]>size[V])
            {
                size[U]+=size[V];
                parent[V]=U;
                return size[U];
            }
            size[V]+=size[U];
            parent[U]=V;
            return size[V];
        }
    };
    
    bool isNotValid(int i,int j,int n,int m)
    {
      if(i<0 || j<0 || i>=n || j>=m) return true;
      return false;
    }
    
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size(),maxArea=1;
        DSU ds(n*m);
        vector<int> di={-1,0,1,0};
        vector<int> dj={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int nodeU=i*m+j;
                    for(int k=0;k<4;k++){
                        int newI=i+di[k],newJ=j+dj[k];
                        if(isNotValid(newI,newJ,n,m)) continue;
                        if(grid[newI][newJ]){
                            int nodeV=newI*m+newJ;
                            maxArea=max(ds.unionBySize(nodeU,nodeV),maxArea);
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j]){
                    int area=1;
                    unordered_set<int> neighbourSet;
                    for(int k=0;k<4;k++)
                    {
                        int newI=i+di[k],newJ=j+dj[k];
                        if(isNotValid(newI,newJ,n,m)) continue;
                        if(grid[newI][newJ])
                        {
                            int nodeV=newI*m+newJ;
                            int parentOfV=ds.find(nodeV);
                            neighbourSet.insert(parentOfV);
                        }
                    }
                    for(int node:neighbourSet)
                        area+=ds.size[node];
                    maxArea=max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};


int main(){

return 0;
}