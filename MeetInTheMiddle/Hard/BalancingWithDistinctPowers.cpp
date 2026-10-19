#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    vector<long long> generateSums(const vector<long long>& half_powers) {
        int n = half_powers.size();
        int total_states = pow(3, n); 

        vector<long long> sums;
        sums.reserve(total_states); // Crucial: prevents TLE from memory reallocation

        for (int mask = 0; mask < total_states; mask++) {
            long long current_sum = 0;
            int temp = mask;
            for (int i = 0; i < n; i++) {
                int choice = temp % 3; // Get the current base-3 "bit"
                temp /= 3;             // Shift right in base-3
                if (choice == 1) current_sum += half_powers[i];
                else if (choice == 2) current_sum -= half_powers[i];
            }
            sums.push_back(current_sum);
        }
        return sums;
    }
public:
    bool balancePan(int a,int b) {
        // 1. Generate all necessary powers of a
        vector<long long> powers;
        long long p = 1;
        // Generate until p safely exceeds b (to allow for subtraction combinations)
        while (p <= 2LL * b) {
            powers.push_back(p);
            if (p > (LLONG_MAX / a)) break; // Prevent overflow
            p *= a;
        }
        // 2. Split the array into two halves
        int mid = powers.size() / 2;
        vector<long long> left_half(powers.begin(), powers.begin() + mid), right_half(powers.begin() + mid, powers.end());
        // 3. Generate all base-3 states for both halves
        vector<long long> S1 = generateSums(left_half), S2 = generateSums(right_half);
        // 4. Sort the second half to enable binary search
        sort(S2.begin(), S2.end());
        // 5. The "Meet" (Search for b = sum1 + sum2 -> sum2 = b - sum1)
        for (long long &sum1 : S1) {
            long long target = 1LL*b - sum1;
            if (binary_search(S2.begin(), S2.end(), target)) return 1;
        }
        return 0;
    }
};

class Solution2{
public:
    bool balancePan(int a,int b) {
        while (b > 0) {
            long long rem = b % a;
            // Case 0 or 1: Weight ignored or placed on right pan
            if (rem == 0 || rem == 1) {
                b = b / a;
            } 
            // Case -1: Weight placed on left pan (needs a +1 carry)
            else if (rem == a - 1) {
                b = (b + 1) / a;
            } 
            // Invalid remainder: Cannot balance with unique powers
            else {
                return false;
            }
        }
        return true;
    }
};

int main(){

return 0;
}