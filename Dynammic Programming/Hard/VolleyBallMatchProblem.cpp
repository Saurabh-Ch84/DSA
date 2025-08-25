#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
class Solution{
    int MOD=1e9+7;
    
    int memoization(int a,int b,int tA,int tB,map<pair<int,int>,long long> &dp){
        if(a==tA && b==tB) return 1;
        if((a>=25 && a-b>=2) || (b>=25 && b-a>=2)) return 0;
        if(a>tA || b>tB) return 0;
        pair<int,int> key={a,b};
        if(dp.count(key)) return dp[key];
        long long result=0;
        result=(result+memoization(a+1,b,tA,tB,dp))%MOD;
        result=(result+memoization(a,b+1,tA,tB,dp))%MOD;
        return dp[key] = result;
    }
    
    long long modpow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    
    long long modInverse(long long a) {
        return modpow(a, MOD - 2, MOD);
    }
    
    long long nCr(int n, int r) {
        if (n < r || r < 0) return 0;
        if (n == r || r == 0) return 1;
        if (r > n - r) r = n - r;
        
        long long num = 1, den = 1;
        for (int i = 0; i < r; ++i) {
            num = (num * (n - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }
        return (num * modInverse(den)) % MOD;
    }
    
    long long mathematics(int tA, int tB) {
        // Check if it's a valid ending score
        if ((tA >= 25 || tB >= 25) && abs(tA - tB) < 2) return 0;
        
        // Case 1: One player reaches exactly 25, other has < 24
        if ((tA == 25 && tB < 24) || (tB == 25 && tA < 24)) {
            long long total = nCr(tA + tB, min(tA, tB));
            // Subtract invalid paths where the losing player gets the last point
            return (total - 1 + MOD) % MOD;
        }
        
        // Case 2: Deuce situation - both players >= 24, difference = 2
        if (min(tA, tB) >= 24 && abs(tA - tB) == 2) {
            long long pathsTo24_24 = nCr(48, 24);
            int extraPoints = max(tA, tB) - 24;
            long long pathsFromTie = nCr(2 * extraPoints, extraPoints);
            // The winner must get the last 2 points
            pathsFromTie = (pathsFromTie * modInverse(2)) % MOD;
            return (pathsTo24_24 * pathsFromTie) % MOD;
        }
        return 0;
    }
        public:
    int fun(int tA,int tB){
        if(max(tA,tB)<25 || abs(tA-tB)<2) return 0;
        map<pair<int,int>,long long> dp;
        return memoization(0,0,tA,tB,dp);
        // return mathematics(tA,tB); //it's giving wrong answer don't know why
    }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Solution s;
    int a,b;
    cin>>a>>b;
    cout<<s.fun(a,b);
    return 0;
}