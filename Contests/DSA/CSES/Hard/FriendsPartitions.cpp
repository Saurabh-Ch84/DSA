#include<bits/stdc++.h>
using namespace std;

class DSU{
  int n;
  vector<int> parent, size;
    public:
  DSU(int n):n(n){
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
    int maxi=0;
    for(int i=0;i<n;i++){
      if(i==parent[i])
        maxi=max(maxi,size[i]);
    }
    return maxi;
  }
  vector<int> getAllCompsSize(){
    vector<int> compSize;
    for(int i=0;i<n;i++){
        if(i==parent[i]) compSize.push_back(size[i]);
    }
    return compSize;
  }
};

class Solution{
    int mod=1e9+7;
    long long binaryExponentiation(int base,int power){
        long long res=1;
        while(power){
            if(power & 1) res=(res*base)%mod;
            power=power>>1;
            base=(1LL*base*base)%mod;
        }
        return res;
    }
    long long kInverseModM(int a){
        return binaryExponentiation(a,mod-2);
    }
    long long nPrModM(int n,int r,vector<long long> &fact){
        return (fact[n]*kInverseModM(fact[n-r]))%mod;
    }
        public:
    pair<int,int> solve(int n,int m,vector<vector<int>> &friendShips){
        DSU ds(n);
        for(int i=0;i<m;i++){
            int u=friendShips[i][0]-1, v=friendShips[i][1]-1;
            ds.unionBySize(u,v);
        }
        int M=ds.sizeOfLargestComp();
        vector<int> friendGroupSizes=ds.getAllCompsSize();
        vector<long long> fact(M+1,1);
        for(int f=1;f<=M;f++)
            fact[f]=(f*fact[f-1])%mod;
        long long count=1;
        for(int &friendGroupSize: friendGroupSizes){
            count=(count*nPrModM(M,friendGroupSize,fact))%mod;
        }
        count=(count*kInverseModM(fact[M]))%mod;
        return {M, count};
    }
};

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> friendShips(m,vector<int>(2));
  for(int i=0;i<m;i++){
    for(int j=0;j<2;j++)
      cin>>friendShips[i][j];
  }
  Solution s;
  pair<int, int> ans = s.solve(n, m, friendShips);
  cout << ans.first << " " << ans.second << endl;
return 0;
}