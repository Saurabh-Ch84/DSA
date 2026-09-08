#include<bits/stdc++.h>
using namespace std;

class DSU{
  vector<int> parent, size;
    public:
  DSU(int n){
    parent.resize(n,-1);
    size.resize(n,1);
    for(int i=0;i<n;i++)
      parent[i]=i;
  }
  int find(int u){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
  }
  void unionBySize(int u,int v){
    int U=find(u), V=find(v);
    if(U==V) return ;
    if(size[U]>size[V]){
      parent[V]=U;
      size[U]+=size[V];
    }
    else{
      parent[U]=V;
      size[V]+=size[U];
    }
  }
  int sizeOfLargestComp(){
    int maxi=0, n=parent.size();
    for(int i=0;i<n;i++){
      if(i==parent[i])
        maxi=max(maxi,size[i]);
    }
    return maxi;
  }
};

int solve(int n,int m,vector<vector<int>> &friendShips){
  DSU ds(n);
  for(int i=0;i<m;i++){
    int u=friendShips[i][0]-1, v=friendShips[i][1]-1;
    ds.unionBySize(u,v);
  }
  return ds.sizeOfLargestComp();
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> friendShips(m,vector<int>(2));
  for(int i=0;i<m;i++){
    for(int j=0;j<2;j++)
      cin>>friendShips[i][j];
  }
  cout<<solve(n,m,friendShips);
return 0;
}