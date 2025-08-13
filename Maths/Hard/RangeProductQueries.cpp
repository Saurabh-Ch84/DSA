#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    //binary exponentiation
    int modPow(int base,int exp){
        const int MOD=1e9+7;
        long res=1;
        while(exp){
            if(exp&1) res=(res*base)%MOD; //calculating the answer
            base=(1LL*base*base)%MOD; //multiplying the base
            exp=exp>>1; //dividing the exponent
        }
        return (int)res;
    }
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> prefix;
        for(int i=0;i<31;i++){
            if(n & (1LL<<i)){
                int last=(prefix.empty())?0:prefix.back();
                prefix.push_back(i+last);
            }
        }
        int q=queries.size();
        vector<int> result; //answer array
        for(int i=0;i<q;i++){
            int exp=prefix[queries[i][1]]-((queries[i][0]>0)? prefix[queries[i][0]-1]: 0);
            int res=modPow(2,exp);
            result.push_back(res);
        }
        return result;
    }
};

int main(){

return 0;
}