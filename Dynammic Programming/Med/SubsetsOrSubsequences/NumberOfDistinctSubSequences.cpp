#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        const int MOD=1e9+7;
        int n=str.length();
        vector<int> prevIdx(26,-1);
        vector<long long> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=2LL*dp[i-1];
            int idx=str[i-1]-'a';
            if(prevIdx[idx]!=-1){
                dp[i]=(dp[i]%MOD -dp[prevIdx[idx]-1]%MOD + MOD)%MOD;
            }
            prevIdx[idx]=i;
        }    
        return dp[n];
    }
};

int main(){

return 0;
}