#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;

using vi = vector<int>;
using memo_t = vector<map<pair<long long, long long>, int>>;

class Solution {
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int recursion(int i, int n, vi &nums, long long v, long long k, memo_t &dp) {
        long long g = gcd(v, k);
        v /= g, k /= g;

        if (i >= n) return v == k ? 1 : 0;

        auto key = make_pair(v, k);
        if (dp[i].count(key)) return dp[i][key];

        long long num = nums[i];
        int ans = 0;

        // Action 1: Multiply ratio by num
        long long g1 = gcd(k, num);
        long long m1 = num / g1; 
        
        // Prune to prevent long long overflow
        if (v <= LLONG_MAX / m1) {
            ans += recursion(i + 1, n, nums, v * m1, k / g1, dp);
        }

        // Action 2: Divide ratio by num
        long long g2 = gcd(v, num);
        long long m2 = num / g2; 
        
        if (k <= LLONG_MAX / m2) {
            ans += recursion(i + 1, n, nums, v / g2, k * m2, dp);
        }

        // Action 3: Unchanged
        ans += recursion(i + 1, n, nums, v, k, dp);

        return dp[i][key] = ans;
    }

public:
    int countSequences(vector<int>& nums, long long k) {
        int n = nums.size();
        memo_t dp(n);
        return recursion(0, n, nums, 1, k, dp);
    }
};

int main(){

return 0;
}