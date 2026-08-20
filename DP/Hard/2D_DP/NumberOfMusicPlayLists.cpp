#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vll=vector<long long>;
    using vvll=vector<vll>;
    int mod=1e9+7;
    long long recursion(int count,int unique,int n,int goal,int k,vvll &dp){
        if(count==goal) return (unique==n? 1:0);
        if(dp[count][unique]!=-1) return dp[count][unique];
        long long playUnique=0, playRepeat=0;
        if(unique<n) playUnique=1LL*(n-unique)*recursion(count+1,unique+1,n,goal,k,dp);
        if(unique>k) playRepeat=1LL*(unique-k)*recursion(count+1,unique,n,goal,k,dp);
        return dp[count][unique]=(playUnique+playRepeat)%mod;
    }
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vvll dp(goal+1,vll(n+1,-1));
        return recursion(0,0,n,goal,k,dp);
    }
};

int main(){

return 0;
}