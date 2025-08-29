#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long binaryExpoPower(int a,int b,int m){
        long long res=1;
        a=a%m;
        while(b){
            if(b%2==1) res=(res*a)%m;
            a=(a*a)%m;
            b=b>>1;
        }
        return res;
    }

    int modInv(int denominator,int m){
        return binaryExpoPower(denominator,m-2,m);
    }

  public:
    int nCrModM(int n, int r, int m) {
        // Code here
        if(r<0 || r>n || m==1) return 0;
        if(r==0 || r==n) return 1;

        vector<long long> fact(n+1);
        fact[0]=1;
        for(int i=1;i<=n;i++)
            fact[i]=(fact[i-1]*i)%m;

        long long numerator=fact[n];
        long long denominator=(fact[n-r]*fact[r])%m;
        return (numerator*modInv(denominator,m))%m;
    }
};

int main(){
    Solution s;
    cout<<s.nCrModM(50,3,101);
return 0;
}