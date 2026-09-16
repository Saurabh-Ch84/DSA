#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mod=1e9+7;
    int dp[1002][1002][2];
    long long recursion(int i,int n,int k,bool isIntervalStarted){
        if(!k) return 1;
        if(i==n) return 0;
        if(dp[i][k][isIntervalStarted]!=-1) return dp[i][k][isIntervalStarted];
        long long skip=recursion(i+1,n,k,isIntervalStarted), take=0;
        if(isIntervalStarted) take=recursion(i,n,k-1,0);
        else if(i!=n-1) take=recursion(i+1,n,k,1);
        return dp[i][k][isIntervalStarted]=(skip+take)%mod;
    }
public:
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return recursion(0,n,k,0);
    }
};

int main(){

return 0;
}