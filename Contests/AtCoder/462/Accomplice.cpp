#include<bits/stdc++.h>
using namespace std;

using vint=vector<int>;
using vvint=vector<vint>;

long long getSolution(vvint &arr,int n,int d){
  sort(arr.begin(),arr.end());
  long long count=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(arr[i][1]<=arr[j][0]) break;
      int st=max(arr[i][0],arr[j][0]);
      int end=min(arr[i][1],arr[j][1]);
      int timeGap=end-st;
      count=count+max(0,timeGap-d+1);
    }
  }
  return count;
} 

int main(){
  int n, d;
  cin>>n>>d;
  vvint arr(n,vint(2,-1));
  for(int i=0;i<n;i++)
    cin>>arr[i][0]>>arr[i][1];
  cout<<getSolution(arr,n,d);
  return 0;
}