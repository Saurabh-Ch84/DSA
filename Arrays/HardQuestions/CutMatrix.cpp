#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint = vector<int>;
    using vvint = vector<vint>;
    using vvvint = vector<vvint>;
    int mod = 1e9 + 7;
    
    int getSum(int r1, int c1, int r2, int c2, const vvint &pref) {
        if (r1 > r2 || c1 > c2) return 0;
        return pref[r2 + 1][c2 + 1] - pref[r2 + 1][c1] - pref[r1][c2 + 1] + pref[r1][c1];
    }

    bool possibleToCut(int i1, int j1, int i2, int j2, int i3, int j3, int i4, int j4, const vvint &pref) {
        int sumOfSubMatrixA = getSum(i1, j1, i2 - 1, j2 - 1, pref);
        int sumOfSubMatrixB = getSum(i3, j3, i4 - 1, j4 - 1, pref);
        return (sumOfSubMatrixA > 0 && sumOfSubMatrixB > 0);
    }

    int recursion(int i, int j, int c, int n, int m, int k, vvint &matrix, const vvint &pref, vvvint &dp) {
        if(c == k) return 1;
        if(dp[i][j][c] != -1) return dp[i][j][c];
        long long ways = 0;
        // 1. Try all possible horizontal cuts
        for(int r = i + 1; r < n; r++) {
            if(possibleToCut(i, j, r, m, r, j, n, m, pref))
                ways = (ways + recursion(r, j, c + 1, n, m, k, matrix, pref, dp)) % mod;
        }
        // 2. Try all possible vertical cuts
        for(int col = j + 1; col < m; col++) {
            if(possibleToCut(i, j, n, col, i, col, n, m, pref))
                ways = (ways + recursion(i, col, c + 1, n, m, k, matrix, pref, dp)) % mod;
        }
        return dp[i][j][c] = ways;
    }
    
public:
    int findWays(vvint &matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        vvint pref(n + 1, vint(m + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++)
                pref[i][j] = matrix[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
        if (getSum(0, 0, n - 1, m - 1, pref) < k) return 0;
        vvvint dp(n, vvint(m, vint(k, -1))); 
        return recursion(0, 0, 0, n, m, k - 1, matrix, pref, dp);
    }
};

int main(){

return 0;
}