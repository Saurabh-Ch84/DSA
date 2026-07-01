#include<bits/stdc++.h>
using namespace std;

using vint=vector<int>;
using vvint=vector<vint>;

int getSolution(vvint &arr,int n){
  sort(arr.begin(),arr.end());
  int prevMinY=1e6, count=0;
  for(int i=0;i<n;i++){
    if(arr[i][1]<=prevMinY) count++;
    prevMinY=min(prevMinY,arr[i][1]);
  }
  return count;
} 

int main(){
  int n;
  cin>>n;
  vvint arr(n,vint(2,-1));
  for(int i=0;i<n;i++)
    cin>>arr[i][0]>>arr[i][1];
  cout<<getSolution(arr,n);
  return 0;
}