#include<iostream>
#include<vector>
using namespace std;

class Fancy1{
    vector<long long> arr, multFactor, addFactor;
    const int mod=1e9+7;
public:
    Fancy1(){}
    
    void append(int val) {
        arr.push_back(val);
        multFactor.push_back(1);
        addFactor.push_back(0);
    }
    
    void addAll(int inc) {
        if(arr.empty()) return ;
        addFactor.back()=(addFactor.back()+inc)%mod;
    }
    
    void multAll(int m) {
        if(arr.empty()) return ;
        multFactor.back()=((multFactor.back()%mod)*m)%mod;
        addFactor.back()=((addFactor.back()%mod)*m)%mod;
    }
    
    int getIndex(int idx){
        if(idx>=arr.size()) return -1;
        long long val = arr[idx];
        for(int i = idx; i < arr.size(); i++){
            val = (val * multFactor[i]) % mod;
            val = (val + addFactor[i]) % mod;
        }
        return (int)val;
    }
};

//Optimal Solution
class Fancy2{
    const int mod=1e9+7;
    vector<long long> arr;
    long long add, mult;

    int inverseModM(long long mult){
        int p=mod-2;
        return binExpo(mult,p);
    }

    long long binExpo(long long b, int p){
        long long res = 1;
        b %= mod;
        while(p > 0){
            if (p & 1) 
                res = (res * b) % mod;
            b = (b * b) % mod;
            p = (p>>1);
        }
        return res;
    }

public:
    Fancy2(): add(0), mult(1) {}
    
    void append(int val) {
        // storing inverse intentionally.
        int numerator=((val%mod)-(add%mod)+mod)%mod;
        int inverseDenominator=inverseModM(mult);
        arr.push_back((1LL*numerator*inverseDenominator)%mod);
    }
    
    void addAll(int inc){
        add=(add+inc)%mod;
    }
    
    void multAll(int m){
        add=((add%mod)*m)%mod;
        mult=((mult%mod)*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx>=arr.size()) return -1;
        return ((arr[idx]*mult)%mod+(add%mod))%mod;
    }
};


int main(){

return 0;
}