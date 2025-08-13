#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<int>& arr, int n, int k, vector<vector<int>>& dp) {
    if (k == 1) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];
        return sum;
    }
    if (n == 1) return arr[0];
    if (dp[n][k] != -1) return dp[n][k];

    int res = INT_MAX;
    // Try all possible partitions
    for (int i = 1; i < n; i++) {
        int left = solve(arr, i, k - 1, dp);
        int right = 0;
        for (int j = i; j < n; j++) right += arr[j];
        res = min(res, max(left, right));
    }
    return dp[n][k] = res;
}

int minPages(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return solve(arr, n, k, dp);
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << minPages(arr, k) << endl; // Output: 113
    return 0;
}
