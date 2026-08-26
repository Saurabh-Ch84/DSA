#include<bits/stdc++.h>
using namespace std;

class Solution2{
    // optimal.
    int mod=1e9+7;
    using vint=vector<int>;
    int binaryExponentiation(int base,int power){
        base=base%mod;
        long long res=1;
        while(power){
            if(power & 1) res=(res*base)%mod;
            power=power/2;
            base=(1LL*base*base)%mod;
        }
        return res%mod;
    }
    int invModM(int number){
        return binaryExponentiation(number,mod-2);
    }
  public:
    int prefixStrings(int n) {
        // code here
        int m=2*n+1;
        vint fact(m,1);
        for(int i=1;i<m;i++){
            fact[i]=(1LL*i*fact[i-1])%mod;
        }
        // the answer would be nth catalan number (2n)!/((n+1)!*(n)!)
        return (1LL*fact[2*n]*invModM(fact[n+1]))%mod*(invModM(fact[n]))%mod;
    }
};

class Solution1 {
    // brute
    using vint=vector<int>;
    using vvint=vector<vint>;
    int mod=1e9+7;
  public:
    int prefixStrings(int n) {
        // code here
        vvint dp(n+1,vint(n+1,0));
        dp[n][n]=1;
        
        for(int i=n;i>=0;i--){
            long long ways=0;
            for(int j=n;j>=0;j--){
                if(i==n && j==n) continue;
                int take0=0, take1=0;
                if(i>j && j<n) take0=dp[i][j+1]%mod;
                if(i<n) take1=dp[i+1][j]%mod;
                dp[i][j]=(take0+take1)%mod;
            }
        }
        return dp[0][0];
    }
};

int main(){

return 0;
}