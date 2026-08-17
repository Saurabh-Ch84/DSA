#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool recursion(int n,vector<int> &dp){
        if(!n) return false; // whoever's turn it was they lost.
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){
            if(recursion(n-i*i,dp)==false) // if Bob loses then only Alice wins
                return dp[n]=true;
        }
        return dp[n]=false;
    }
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);
        return recursion(n,dp);
    }
};

int main(){

return 0;
}