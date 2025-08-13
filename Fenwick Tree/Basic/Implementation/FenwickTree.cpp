#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class FenwickTree {
private:
    vector<int> BIT;  // Fenwick tree array (1-based indexing)
    int n;
    
    // Build Fenwick tree from input array
    void build(const vector<int>& arr) {
        for (int i = 0; i < n; i++) {
            update(i, arr[i]);
        }
    }
        public:
    // Constructor: initialize Fenwick tree for given size
    FenwickTree(vector<int> &arr){
        n = arr.size();
        BIT.assign(n + 1, 0);  // 1-based indexing
        build(arr);
    }

    // Update: add val to element at index idx (0-based)
    void update(int idx, int val) {
        idx++; // shift to 1-based indexing
        while (idx <= n) {
            BIT[idx] += val;
            idx += idx & (-idx);
        }
    }

    // Query: get prefix sum from [0..idx] (0-based)
    int query(int idx) {
        idx++; // shift to 1-based indexing
        int sum = 0;
        while (idx > 0) {
            sum += BIT[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

    // Query to get sum in range [l..r]
    int queryRange(int l, int r) {
        return query(r) - query(l - 1);
    }

    int lowerBoundPrefixSumIndex(int k) {
        int low = 0, prevSum = 0;
        int maxPow = (int)log2(n);  // maximum power of two <= n

        for (int i = maxPow; i >= 0; i--) {
            int next = low + (1 << i);
            if (next <= n && BIT[next] + prevSum < k) {
                low = next;
                prevSum += BIT[low];
            }
        }
        return low + 1;  // +1 for 1-based indexing result
    }

};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    FenwickTree fenw(arr);

    cout << fenw.query(2) << "\n";  // Output: 6 (sum of first 3 elements)
    fenw.update(1, 0);              // arr[1] += 0, now element at index 1 is 2
    cout << fenw.query(2) << "\n";  // Output: 6 (no change)
    cout << fenw.queryRange(1, 3) << "\n"; // Output: 9
    cout<<fenw.lowerBoundPrefixSumIndex(7)<<endl; 
    return 0;
}