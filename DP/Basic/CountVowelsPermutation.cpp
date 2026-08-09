#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    // memoization, top-down approach
    using vint=vector<int>;
    using vvint=vector<vint>;
    int mod=1e9+7;
    long long recursion(int i,int j,int n,vvint &adjList,vvint &dp){
        if(i==n) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        long long ways=0;
        for(int &k: adjList[j]){
            long long nextWays=recursion(i+1,k,n,adjList,dp);
            ways=(ways+nextWays)%mod;
        }
        return dp[i][j]=ways;
    }
public:
    int countVowelPermutation(int n) {
        int m=5+1;
        vvint adjList={{1,2,3,4,5},{2},{1,3},{1,2,4,5},{3,5},{1}};
        vvint dp(n+1,vint(m,-1));
        return recursion(0,0,n,adjList,dp);
    }
};

class Solution2 {
    // tabulation, bottom-up approach
    using vint=vector<int>;
    using vvint=vector<vint>;
    int mod=1e9+7;
public:
    int countVowelPermutation(int n) {
        int m=5+1;
        vvint adjList={{1,2,3,4,5},{2},{1,3},{1,2,4,5},{3,5},{1}};
        vvint dp(n+1,vint(m,-1));
        for(int j=0;j<m;j++) dp[n][j]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                long long ways=0;
                for(int &k: adjList[j])
                    ways=(ways+dp[i+1][k])%mod;
                dp[i][j]=ways;
            }
        }
        return dp[0][0];
    }
};

int main(){

return 0;
}