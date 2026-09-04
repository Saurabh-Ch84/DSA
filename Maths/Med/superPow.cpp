#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    int mod=1337;
    int binaryExpo(int base,int power){
        long long res=1;
        base=base%mod;
        while(power){
            if(power & 1) res=(res*base)%mod;
            power=power>>1;
            base=(1LL*base*base)%mod;
        }
        return res%mod;
    }
public:
    int superPow(int a, vector<int>& b) {
        if(a==1) return 1;
        int n=b.size();
        long long res=1;
        for(int i=0;i<n;i++)
            res=(binaryExpo(res,10)*binaryExpo(a,b[i]))%mod;
        return res;
    }
};

int main(){

return 0;
}