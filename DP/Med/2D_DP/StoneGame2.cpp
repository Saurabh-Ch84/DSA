#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;

    int inf=1e9;
    int recursion(int i,int n,int m,vint &piles,int t,vvvint &dp){
        if(i>=n) return 0;
        if(dp[i][m][t]!=-inf) return dp[i][m][t];
        int score=0;
        if(t){
            score=-inf;
            int x=1, prev=0, currSum=0;
            while(x<=2*m && i+x-1<n){
                currSum=prev+piles[i+x-1];
                prev=currSum;
                int temp=currSum+recursion(i+x,n,max(m,x),piles,0,dp);
                score=max(score,temp);
                x++;
            }
        }
        else{
            score=inf;
            int x=1, prev=0, currSum=0;
            while(x<=2*m && i+x-1<n){
                currSum=prev+piles[i+x-1];
                prev=currSum;
                int temp=-currSum+recursion(i+x,n,max(m,x),piles,1,dp);
                score=min(score,temp);
                x++;
            }
        }
        return dp[i][m][t]=score;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size(), m=1, S=accumulate(piles.begin(),piles.end(),0);
        vvvint dp(n,vvint(101,vint(2,-inf)));
        int aliceOptimalScoreDiff=recursion(0,n,m,piles,1,dp);
        int aliceOptimalScore=(aliceOptimalScoreDiff+S)/2;
        return aliceOptimalScore;
    }
};

class Solution2 {
    using vint = vector<int>;
    using vvint = vector<vint>;
    int inf = 1e9;
    int recursion(int i, int n, int m, vint& piles, vvint& dp) {
        if (i >= n) return 0;
        if (dp[i][m] != -inf) return dp[i][m];
        int maxDiff = -inf, currSum = 0;
        for (int x = 1; x <= 2 * m && i + x - 1 < n; x++) {
            currSum += piles[i + x - 1];
            int temp = currSum - recursion(i + x, n, max(m, x), piles, dp);
            maxDiff = max(maxDiff, temp);
        }
        return dp[i][m] = maxDiff;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size(), m = 1, S = accumulate(piles.begin(), piles.end(), 0);
        vvint dp(n, vint(101,-inf));
        int aliceOptimalScoreDiff = recursion(0, n, m, piles, dp);
        int aliceOptimalScore = (aliceOptimalScoreDiff + S) / 2;
        return aliceOptimalScore;
    }
};

int main(){

return 0;
}