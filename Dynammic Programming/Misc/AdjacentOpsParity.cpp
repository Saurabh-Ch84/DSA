#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution_AdjacentOps {
private:
    // Helper to find the cost to make a number a certain parity
    // Returns INT_MAX if impossible (e.g., making 0 odd)
    int cost_to(int num, int target_parity) {
        if (num == 0 && target_parity == 1) {
            return INT_MAX; // Impossible to make 0 odd
        }
        int operations = 0;
        while (num > 0 && (num % 2) != target_parity) {
            num /= 2;
            operations++;
        }
        if ((num % 2) == target_parity) {
            return operations;
        }
        return INT_MAX; // Cannot be converted
    }

public:
    int minOperations(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // dp[i][0]: min cost for prefix arr[0..i] with arr[i] being EVEN
        // dp[i][1]: min cost for prefix arr[0..i] with arr[i] being ODD
        vector<vector<int>> dp(n, vector<int>(2, INT_MAX));

        // Base case for the first element
        dp[0][0] = cost_to(arr[0], 0);
        dp[0][1] = cost_to(arr[0], 1);

        // Fill DP table using transitions
        for (int i = 1; i < n; ++i) {
            int cost_to_even = cost_to(arr[i], 0);
            int cost_to_odd = cost_to(arr[i], 1);

            // To make arr[i] even, arr[i-1] must be odd
            if (dp[i-1][1] != INT_MAX && cost_to_even != INT_MAX) {
                dp[i][0] = dp[i-1][1] + cost_to_even;
            }

            // To make arr[i] odd, arr[i-1] must be even
            if (dp[i-1][0] != INT_MAX && cost_to_odd != INT_MAX) {
                dp[i][1] = dp[i-1][0] + cost_to_odd;
            }
        }

        int result = min(dp[n-1][0], dp[n-1][1]);
        return (result == INT_MAX) ? -1 : result; // Return -1 if no solution
    }
};

int main() {
    cout << "## 1. Adjacent Element Operations ##" << endl;
    Solution_AdjacentOps sol;
    vector<int> arr = {10, 5, 2, 7, 1};
    // Possible optimal sequence: 5(O,1 op), 2(E,1 op), 1(O,1 op), 2(E,1 op), 1(O,0 ops) -> Total 4 ops
    cout << "Array: {10, 5, 2, 7, 1}" << endl;
    cout << "Minimum Operations: " << sol.minOperations(arr) << endl << endl;
    return 0;
}