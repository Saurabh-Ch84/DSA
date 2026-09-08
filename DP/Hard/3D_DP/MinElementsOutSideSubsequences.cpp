#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[101][102][102];
    int inf=1e6;
    int recursion(int i,int pI,int pJ,int n,vector<int> &arr){
        if(i==n) return 0;
        if(dp[i][pI+1][pJ+1]!=-1) return dp[i][pI+1][pJ+1];
        int skip=1+recursion(i+1,pI,pJ,n,arr), takeInLIS=inf, takeInLDS=inf;
        if(pI==-1 || arr[i]>arr[pI]) takeInLIS=recursion(i+1,i,pJ,n,arr);
        if(pJ==-1 || arr[i]<arr[pJ]) takeInLDS=recursion(i+1,pI,i,n,arr);
        return dp[i][pI+1][pJ+1]=min({skip,takeInLIS,takeInLDS});
    }
  public:
    int minCount(vector<int>& arr) {
        // code here
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return recursion(0,-1,-1,n,arr);
    }
};

int main(){

return 0;
}