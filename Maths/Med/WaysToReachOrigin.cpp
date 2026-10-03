#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mod=1e9+7;
    int binaryExponentiation(int base,int power){
        base=base%mod;
        long long res=1;
        while(power){
            if(power & 1) res=(res*base)%mod;
            base=(1LL*base*base)%mod;
            power=power>>1;
        }
        return res%mod;
    }
    int invModM(int x){
        return binaryExponentiation(x,mod-2);
    }
  public:
    int ways(int x, int y) {
        // code here
        vector<int> fact(x+y+1,1);
        for(int i=1;i<=x+y;i++){
            fact[i]=(1LL*i*fact[i-1])%mod;
        }
        long long ans=(1LL*fact[x+y]*invModM(fact[x])%mod*invModM(fact[y]))%mod;
        return (int)ans;
    }
};

int main(){

return 0;
}