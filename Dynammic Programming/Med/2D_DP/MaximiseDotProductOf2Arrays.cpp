#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vll=vector<long long>;
    using vvll=vector<vll>;
    long long recursion(int i,int j,int n,int m,vint &a,vint &b,vvll &dp){
        if(j==m) return 0;
        if(i==n) return -1e10;
        if(dp[i][j]!=-1) return dp[i][j];
        long long take=recursion(i+1,j+1,n,m,a,b,dp)+a[i]*b[j];
        long long skip=recursion(i+1,j,n,m,a,b,dp);
        return dp[i][j]=max(take,skip);
    }
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size(), m=b.size();
        vvll dp(n,vll(m,-1));
        return recursion(0,0,n,m,a,b,dp);
    }
};


int main(){

return 0;
}