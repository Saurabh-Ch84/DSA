#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int power(int a,int b,int p){
        if(b==0) return 1;
        int halfRes=power(a,b/2,p);
        int res=(halfRes*halfRes)%p;
        if(b%2) res=(res*a)%p;
        return res;
    }

    int modInv(int b,int p){
        return power(b,p-2,p);
    }
  public:
    int nCrModM(int n, int r, int m) {
        // Code here
        vector<int> fact(n);
        fact[0]=1;
        for(int i=1;i<n;i++)
            fact[i]=i*fact[i-1];
        return (fact[n]*( modInv(fact[r],m)%m * modInv(fact[n-r],m)%m ))%m;
    }
};

int main(){

return 0;
}