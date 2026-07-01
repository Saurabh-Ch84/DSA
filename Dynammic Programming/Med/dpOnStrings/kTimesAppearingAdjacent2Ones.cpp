#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;
    int mod=1e9+7;
    long long recursion(int i,int p,int n,int k,vvvint &dp){
        if(i>=n) return !k;
        if(dp[i][k][p]!=-1) return dp[i][k][p];
        long long notTake=0, take=0;
        notTake=recursion(i+1,0,n,k,dp);
        if(k || !p) take=recursion(i+1,1,n,k-p,dp);
        return dp[i][k][p]=(take+notTake)%mod;
    }
  public:
    int countStrings(int n, int k){
        // code here
        vvvint dp(n,vvint(k+1,vint(2,-1)));
        return recursion(0,0,n,k,dp);
    }
};

int main(){

return 0;
}