#include<bits/stdc++.h>
using namespace std;

class Solution{
    using vint=std::vector<int>;
    int mod=1e9+7;
    long long recursion(int n,int m,vint &dp){
        if(m>n) return 1;
        if(dp[n]!=-1) return dp[n];
        long long horizontal=recursion(n-1,m,dp)%mod;
        long long vertical=0;
        if(n>=m) vertical=recursion(n-m,m,dp)%mod;
        return dp[n]=(horizontal+vertical)%mod;
    }
  public:
    int countWays(int n, int m) {
        // code here.
        vint dp(n+1,-1);
        return recursion(n,m,dp);
    }
};

int main(){

return 0;
}