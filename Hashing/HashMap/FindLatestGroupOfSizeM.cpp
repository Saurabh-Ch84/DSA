#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (m == n) return n;

        vector<int> length(n + 2, 0); // Stores length of group ending/starting at index i
        vector<int> count(n + 1, 0);  // Stores how many groups of size 'x' exist
        int latest = -1;

        for (int step = 0; step < n; step++) {
            int pos = arr[step];
            
            // Get lengths of left and right neighbors
            int left = length[pos - 1];
            int right = length[pos + 1];
            int newLen = left + right + 1;

            // Remove old groups from the count since they are being merged
            if (left > 0) count[left]--;
            if (right > 0) count[right]--;

            // Add the new merged group to the count
            count[newLen]++;
            
            // Update the endpoints of the new segment to reflect the new length
            length[pos] = newLen;           // Mark the current position
            length[pos - left] = newLen;    // Update the far left end
            length[pos + right] = newLen;   // Update the far right end

            // If a group of size m exists, update the answer
            if (count[m] > 0) latest = step + 1;
        }
        return latest;
    }
};

int main() {
    Solution sol;

    // --- Test Case 1 ---
    // Explanation: Step 4 creates groups [111, 1]. Size 1 still exists.
    // Step 5 merges them into [11111]. Size 1 is gone.
    vector<int> arr1 = {3, 5, 1, 2, 4};
    int m1 = 1;
    cout << "Test Case 1: " << sol.findLatestStep(arr1, m1) << " (Expected: 4)" << endl;

    // --- Test Case 2 ---
    // Explanation: Step 1 creates group of size 1. 'm' is 2.
    // Step 2 creates group of size 2. 'm' is 2. Correct.
    // Step 3 merge.
    vector<int> arr2 = {3, 1, 5, 4, 2};
    int m2 = 2;
    cout << "Test Case 2: " << sol.findLatestStep(arr2, m2) << " (Expected: -1)" << endl; 
    // Wait! Let's trace T2 manually:
    // 3 -> [00100] (len 1)
    // 1 -> [10100] (len 1, 1)
    // 5 -> [10101] (len 1, 1, 1)
    // 4 -> [10111] (len 1, 3) -> merged 5 and 4
    // 2 -> [11111] (len 5)
    // Expected is -1 because a group of size 2 never existed!
    
    // --- Test Case 3 ---
    // A group of size 1 is created at step 1. Merged immediately at step 2.
    vector<int> arr3 = {1};
    int m3 = 1;
    cout << "Test Case 3: " << sol.findLatestStep(arr3, m3) << " (Expected: 1)" << endl;

    return 0;
}