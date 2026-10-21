#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> sortedArray;
    
    // Pass the starting index and chunk size 'k' instead of creating a new vector
    vector<int> getLPS(const vector<int> &pattern, int start, int k) {
        vector<int> lps(k, 0);
        int i = 1, len = 0;
        while (i < k) {
            if (pattern[start + i] == pattern[start + len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len) len = lps[len - 1];
                else i++;
            }
        }
        return lps;
    }
    
    bool KMPcheck(const vector<int> &text, int textStart, const vector<int> &pattern, int patStart, int k) {
        vector<int> lps = getLPS(pattern, patStart, k);
        int i = 0, j = 0;
        int n = 2 * k; // Simulated length of the duplicated text
        
        while (i < n) {
            // (i % k) creates a "virtual" duplicated array in O(1) space!
            if (text[textStart + (i % k)] == pattern[patStart + j]) {
                i++;
                j++;
                if (j == k) return true;
            } else {
                if (j) j = lps[j - 1];
                else i++;
            }
        }
        return false;
    }
    
    bool checkAllSubarrays(const vector<int> &nums, int k, int n) {
        for (int i = 0; i < n; i += k) {
            // Pass the original arrays along with the starting index 'i'
            if (!KMPcheck(sortedArray, i, nums, i, k)) return false;
        }
        return true;
    }
    
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        sortedArray = nums;
        sort(sortedArray.begin(), sortedArray.end());
        
        for (int k = 1; 1LL * k * k <= n; k++) {
            if (n % k == 0) {
                if (checkAllSubarrays(nums, k, n)) sum += k;
                if (1LL * k * k != n && checkAllSubarrays(nums, n / k, n)) sum += (n / k);
            }
        }
        return sum;
    }
};

int main(){

return 0;
}