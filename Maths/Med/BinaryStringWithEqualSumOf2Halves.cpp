#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vll=vector<long long>;
    int binaryExponentiation(int base,int expo,int mod){
        base=base%mod;
        long long res=1;
        while(expo){
            if(expo&1) res=(res*base)%mod;
            expo=expo/2;
            base=(1LL*base*base)%mod;
        }
        return res%mod;
    }
    int invModM(int a,int p){
        return binaryExponentiation(a,p-2,p);
    }
  public:
    int computeValue(int n) {
        // code here
        int mod=1e9+7;
        long long res=1;
        vll fact(n+1,1);
        for(int i=1;i<=n;i++)
            fact[i]=(fact[i-1]*i)%mod;
        
        for(int r=1;r<=n;r++){
            int inv_r=invModM(fact[r],mod);
            int inv_nr=invModM(fact[n-r],mod);
            long long nCrModM=(fact[n]*inv_r%mod)*inv_nr%mod;
            res=(res+nCrModM*nCrModM%mod)%mod;
        }
        return res;
    }
};

class Solution2 {
    using vll = vector<long long>;
    
    int binaryExponentiation(int base, int expo, int mod) {
        base = base % mod;
        long long res = 1;
        while (expo) {
            if (expo & 1) res = (res * base) % mod;
            expo = expo / 2;
            base = (1LL * base * base) % mod;
        }
        return res % mod;
    }
    
    int invModM(int a, int p) {
        return binaryExponentiation(a, p - 2, p);
    }
    
public:
    int computeValue(int n) {
        int mod = 1e9 + 7;
        
        // We just need to calculate (2n)! / (n! * n!)
        long long fact2n = 1;
        long long factn = 1;
        
        // Calculate factorials up to 2n
        for (int i = 1; i <= 2 * n; i++) {
            fact2n = (fact2n * i) % mod;
            if (i == n) {
                factn = fact2n; // Capture n! along the way
            }
        }
        
        // Calculate the inverse of n! just once
        long long inv_factn = invModM(factn, mod);
        
        // nCr formula: (2n)! * (n!)^-1 * (n!)^-1
        long long res = (fact2n * inv_factn) % mod;
        res = (res * inv_factn) % mod;
        
        return res;
    }
};

int main(){

return 0;
}