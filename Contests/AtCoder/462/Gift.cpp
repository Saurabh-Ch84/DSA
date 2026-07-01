#include<bits/stdc++.h>
using namespace std;

using vint=vector<int>;
using vvint=vector<vint>;

vvint getSolution(vvint &adjList,int n){
  vvint res(n);
  for(int i=0;i<n;i++){
    for(int &j: adjList[i])
      res[j].push_back(i);
  }
  return res;
} 

int main(){
  int n;
  cin>>n;
  vvint adjList(n);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int m;
      cin>>m;
      adjList[i].push_back(m-1);
    }
  }
  
  vvint res=getSolution(adjList,n);
  for(int i=0;i<n;i++){
    int m=res[i].size();
    cout<<m;
    for(int j=0;j<m;j++)
      cout<<" "<<1+res[i][j];
    cout<<"\n";
  }
  return 0;
}