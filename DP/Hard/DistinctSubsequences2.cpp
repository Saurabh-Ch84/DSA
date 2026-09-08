#include<bits/stdc++.h>
using namespace std;

class Solution1{
    int dp[2002];
    vector<int> prev;
    int mod=1e9+7;
    int recursion(int i){
        if(i==0) return 1;
        if(dp[i]!=-1) return dp[i];
        int distinctSubsets=(2LL*recursion(i-1))%mod;
        if(prev[i]){
            int dups=recursion(prev[i]-1);
            distinctSubsets=(1LL*distinctSubsets-dups+mod)%mod;
        }
        return dp[i]=distinctSubsets;
    }
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        prev.assign(n+1,0);
        vector<int> lastSeen(26,0);
        for(int i=1;i<=n;i++){
            int idx=s[i-1]-'a';
            prev[i]=lastSeen[idx];
            lastSeen[idx]=i;
        }
        memset(dp,-1,sizeof(dp));
        return (1LL*recursion(n)-1+mod)%mod;
    }
};

class Solution2{
public:
    int distinctSubseqII(string s) {
        int n=s.size(), mod=1e9+7;
        vector<int> dp(n+1,0), prev(n+1,0), lastSeen(26,0);
        for(int i=1;i<=n;i++){
            int idx=s[i-1]-'a';
            prev[i]=lastSeen[idx];
            lastSeen[idx]=i;
        }
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int total=(2LL*dp[i-1])%mod;
            if(prev[i]){
                int dups=dp[prev[i]-1];
                total=(1LL*total-dups+mod)%mod;
            }
            dp[i]=total;
        }
        return (1LL*dp[n]-1+mod)%mod;
    }
};

int main(){

return 0;
}