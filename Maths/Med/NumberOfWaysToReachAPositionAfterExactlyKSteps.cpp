#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    // brute force solution
    int mod=1e9+7;
    vector<long long> fact;
    void preprocess(int k){
        int sz=2*k;
        fact.resize(sz,1);
        for(int i=1;i<sz;i++)
            fact[i]=(fact[i-1]*i)%mod;
    }
    int binExpo(int base,int p){
        base=base%mod;
        long long result=1;
        while(p){
            if(p & 1) result=(result*base)%mod;
            base=(1LL*base*base)%mod;
            p=p>>1;
        }
        return result%mod;
    }
    int inverseModM(int base){
        return binExpo(base,mod-2);
    }
    int Permutation(int k,int l,int r){
        int invr1=inverseModM(fact[l]);
        int invr2=inverseModM(fact[r]);
        return ((fact[k]*invr1)%mod*invr2)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        if(startPos>endPos) swap(startPos,endPos);
        preprocess(k);
        long long ways=0;
        for(int right=k;right>=-k;right--){
            // relationship between right and left moves: right + left = k
            int left=k-right;
            int net=right-left;
            if(startPos+net==endPos){
                // the difference between numbers of constant sum is unique as we one increases the other decreases so it means that this 
                // loop can be optimized to a single calculation instead of iterating through all possible right moves. 
                // However, for the brute force solution, we are iterating through all possible right moves.
                // calculate the number of ways to arrange right and left moves in k steps using permutations.
                ways=(ways+Permutation(k,abs(left),abs(right)))%mod;
            }
        }
        return ways;
    }
};

class Solution2 {
    // optimized solution
    int mod=1e9+7;
    vector<long long> fact;
    void preprocess(int k){
        int sz=2*k;
        fact.resize(sz,1);
        for(int i=1;i<sz;i++)
            fact[i]=(fact[i-1]*i)%mod;
    }
    int binExpo(int base,int p){
        base=base%mod;
        long long result=1;
        while(p){
            if(p & 1) result=(result*base)%mod;
            base=(1LL*base*base)%mod;
            p=p>>1;
        }
        return result%mod;
    }
    int inverseModM(int base){
        // Fermat's little theorem: a^(p-1) ≡ 1 (mod p) => a^(p-2) ≡ a^(-1) (mod p)
        return binExpo(base,mod-2);
    }
    int Permutation(int k,int l,int r){
        // calculate k!/(l!*r!) mod mod
        int invr1=inverseModM(fact[l]);
        int invr2=inverseModM(fact[r]);
        return ((fact[k]*invr1)%mod*invr2)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        // derive the number of right and left moves needed to reach endPos from startPos in exactly k steps
        int n = endPos - startPos; // no need for the swap/abs trick anymore actually — think about why
        if(abs(n) > k || (k+n) % 2 != 0) return 0; // unreachable or parity fails, no integer solution
        // let right moves be r and left moves be l, we have:
        // r - l = n  (net movement)
        int right = (k+n)/2, left = k-right;
        preprocess(k);
        return Permutation(k, left, right);
    }
};

int main(){

return 0;
}