#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vll=vector<long long>;
public:
    vint sumAndMultiply(string s,vvint &queries) {
        int n=s.size(), mod=1e9+7, m=queries.size();
        vll prefixVal(n,0);
        vint prefixSum(n,0), countDigit(n,0), powersOf10(n+1,1);
        prefixVal[0]=s[0]-'0', prefixSum[0]=s[0]-'0';
        countDigit[0]=(s[0]=='0'? 0: 1);

        for(int i=1;i<n;i++){
            int d=s[i]-'0';
            if(d) prefixVal[i]=(prefixVal[i-1]*10+d)%mod;
            else prefixVal[i]=prefixVal[i-1];
            prefixSum[i]=(prefixSum[i-1]+d)%mod;
            countDigit[i]=(countDigit[i-1]+(d==0? 0: 1))%mod;
            powersOf10[i]=(10LL*powersOf10[i-1])%mod;
        }
        vint res(m,-1);
        for(int i=0;i<m;i++){
            int l=queries[i][0], r=queries[i][1];
            int k=countDigit[r]-(l? countDigit[l-1]:0);
            int x=(1LL*prefixVal[r]-(l? (1LL*prefixVal[l-1]*powersOf10[k])%mod:0)+mod)%mod;
            int sumOfDigits=(prefixSum[r]-(l? prefixSum[l-1]:0));
            res[i]=(1LL*x*sumOfDigits)%mod;
        }
        return res;
    }
};

int main(){

return 0;
}