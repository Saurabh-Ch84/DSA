#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    const int mod = 1e9 + 7;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    long long windowSum = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = windowSum;
        windowSum = (windowSum + dp[i]) % mod;
        if (i >= 6) {
            windowSum = (windowSum - dp[i - 6] + mod) % mod;
        }
    }
    cout << dp[n];
    return 0;
}