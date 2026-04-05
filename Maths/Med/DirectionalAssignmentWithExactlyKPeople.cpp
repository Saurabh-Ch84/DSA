#include<iostream>
#include<vector>
using namespace std;

class Solution {
    using vint=vector<int>;
    const int mod=1e9+7;

    long long binExpo(long long b,int p){
        long long res=1;
        b=b%mod;
        while(p){
            if(p&1) res=(res*b)%mod;
            p=p>>1;
            b=(b*b)%mod;
        }
        return res%mod;
    }

    int fermat(int base){
        return binExpo(1LL*base,mod-2);
    }

    int nCrModM(vint &fact,int n,int r){
        int rInv=fermat(fact[r]);
        int n_rInv=fermat(fact[n-r]);
        return (1LL*fact[n]*rInv)%mod*(n_rInv)%mod;
    }
public:
    int countVisiblePeople(int n, int pos, int k) {
        vint fact(n,1);
        for(int i=1;i<n;i++)
            fact[i]=(1LL*fact[i-1]*i)%mod;
        return (nCrModM(fact,n-1,k)*2)%mod;
    }
};

int main(){

return 0;
}