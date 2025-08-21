#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
        public:
    long long power(long long a, long long b, long long p){
        long long res = 1;
        a = a % p;
        while(b > 0){
            if (b & 1) res = (res * a) % p;
            a = (a * a) % p;
            b >>= 1;
        }
        return res;
    }
    long long modInv(long long a, long long p){
        return power(a, p-2, p);
    }
    long long nCrModM(int n, int r, int p) {
        if (r > n) return 0;
        vector<long long> fact(n+1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = (fact[i-1] * i) % p;
        long long inv_r = modInv(fact[r], p);
        long long inv_nr = modInv(fact[n - r], p);
        return (fact[n] * inv_r % p) * inv_nr % p;
    }
};

int main(){

return 0;
}