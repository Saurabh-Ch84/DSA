#include<bits/stdc++.h>
using namespace std;

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minCost(int n, int i, int d, int c) {
        if (n <= 0) return 0;
        
        vector<long long> dp(n + 1, 0);
        dp[1] = i; // Cost to reach 1 is inserting 1 character

        for (int k = 2; k <= n; k++) {
            if (k % 2 == 0) {
                // Even: Insert 1 OR Double from k/2
                dp[k] = min(dp[k - 1] + i, dp[k / 2] + c);
            } else {
                // Odd: Insert 1 OR Double from (k+1)/2 and Delete 1
                dp[k] = min(dp[k - 1] + i, dp[(k + 1) / 2] + c + d);
            }
        }

        return dp[n];
    }
};

int main(){

return 0;
}