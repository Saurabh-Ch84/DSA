#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<bool> sieve(int l){
        vector<bool> prime(l+1,true);
        prime[0]=false, prime[1]=false;
        for(int i=0;i<=l;i++){
            if(!prime[i]) continue;
            for(int j=i*i;j<=l;j+=i){
                prime[j]=false;
            }
        }
        return prime;
    }
public:
    int sumOfPrimesInRange(int n) {
        int r=0, n_=n;
        while(n_){
            int d=n_%10;
            r=r*10+d;
            n_=n_/10;
        }
        int mn=min(r,n), mx=max(r,n), sum=0;
        vector<bool> prime=sieve(mx);
        for(int i=mn;i<=mx;i++){
            if(prime[i]) sum+=i;
        }
        return sum;
    }
};

int main(){

return 0;
}