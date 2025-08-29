#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countDivisiblePairs(const vector<int>& a, int k) {
    unordered_map<int, int> remCount;
    for (int num : a) {
        int rem = num % k;
        remCount[rem]++;
    }
    int count = 0;
    // Handle remainder 0 separately
    count += (remCount[0] * (remCount[0] - 1)) / 2;
    // Handle pairs (r, k - r)
    for (int r = 1; r <= k / 2; ++r) {
        if (r != k - r) count += remCount[r] * remCount[k - r];
    }
    // If k is even, handle k/2 separately
    if (k % 2 == 0) count += (remCount[k / 2] * (remCount[k / 2] - 1)) / 2;
    return count;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6};
    int k = 3;
    cout << "Number of valid pairs: " << countDivisiblePairs(a, k) << endl;
    return 0;
}
