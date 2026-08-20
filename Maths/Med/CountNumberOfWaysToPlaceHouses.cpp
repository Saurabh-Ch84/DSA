#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Space Optimized bottom up approach
    int mod=1e9+7;
    int numberOfWaysForOneSide(int n){
        int c=1, b=1;
        for(int i=n-1;i>=0;i--){
            int a=(b+c)%mod;
            c=b;
            b=a;
        }
        return b;
    }
public:
    int countHousePlacements(int n) {
        // Calculate the number of ways to place houses on one side of the street
        long long waysFor1Side=numberOfWaysForOneSide(n);
        // the arrangement of houses on one side of the street is independent of the other side, 
        // so we can multiply the number of ways for one side by itself to get the total number of ways for both sides.
        return (waysFor1Side*waysFor1Side)%mod;
    }
};

class Solution2 {
    // Tabulation bottom up approach
    int mod=1e9+7;
    int tabulation(int n){
        vector<int> dp(n+2,0);
        dp[n+1]=1, dp[n]=1;
        for(int i=n-1;i>=0;i--)
            dp[i]=(dp[i+1]+dp[i+2])%mod;
        return dp[0];
    }
public:
    int countHousePlacements(int n) {
        long long waysFor1Side=tabulation(n);
        return (waysFor1Side*waysFor1Side)%mod;
    }
};

int main(){

return 0;
}