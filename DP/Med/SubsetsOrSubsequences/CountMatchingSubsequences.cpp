#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vll=vector<long long>;
    using vvll=vector<vll>;
    int mod=1e9+7;
    long long recursion(int i,int j,int n,int m,string &s1,string &s2,vvll &dp){
        if(j==m) return 1;
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long ans=0;
        for(int idx=i;idx<n;idx++){
            if(s1[idx]==s2[j])
                ans=(ans%mod+recursion(idx+1,j+1,n,m,s1,s2,dp)%mod)%mod;
        }
        return dp[i][j]=ans;
    }
  public:
    int countWays(string &s1, string &s2) {
        // code here
        int n=s1.size(), m=s2.size();
        if(m>n) return 0;
        vvll dp(n,vll(m,-1));
        return recursion(0,0,n,m,s1,s2,dp)%mod;
    }
};


int main(){

return 0;
}