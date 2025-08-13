#include<iostream>
#include<vector>
using namespace std;

class SegmentTree {
    vector<int> segTree, lazyTree;
    int n;

    void build(vector<int>& arr, int idx, int low, int high) {
        if (low == high) {
            segTree[idx] = arr[low];
            return;
        }
        int mid = (low + high)>>1;
        build(arr, 2 * idx + 1, low, mid);
        build(arr, 2 * idx + 2, mid + 1, high);
        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }

    void updateRangeUtil(int idx, int low, int high, int l, int r, int val) {
        if (lazyTree[idx] != 0) {
            // Apply the pending lazy update to this node
            segTree[idx] += (high - low + 1) * lazyTree[idx];
            if (low != high) {
                // Propagate the lazy update to children
                lazyTree[2 * idx + 1] += lazyTree[idx];
                lazyTree[2 * idx + 2] += lazyTree[idx];
            }
            lazyTree[idx] = 0; // Clear the lazy value after applying
        }

        // No overlap
        if (low > r || high < l) return;

        // Total overlap
        if (low >= l && high <= r) {
            segTree[idx] += (high - low + 1) * val;
            if (low != high) {
                lazyTree[2 * idx + 1] += val;
                lazyTree[2 * idx + 2] += val;
            }
            return;
        }

        // Partial overlap
        int mid = (low + high)>>1;
        updateRangeUtil(2 * idx + 1, low, mid, l, r, val);
        updateRangeUtil(2 * idx + 2, mid + 1, high, l, r, val);
        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }

    int queryRangeUtil(int idx, int low, int high, int l, int r) {
        
        if (lazyTree[idx] != 0) {
            // Apply pending lazy updates
            segTree[idx] += (high - low + 1) * lazyTree[idx];
            if (low != high) { //nodes has children
                lazyTree[2 * idx + 1] += lazyTree[idx];
                lazyTree[2 * idx + 2] += lazyTree[idx];
            }
            //reset
            lazyTree[idx] = 0;
        }
        
        //no overlap
        if (low > r || high < l) return 0;

        // Full overlap
        if (low >= l && high <= r) return segTree[idx];
        
        // Partial overlap
        int mid = (low + high)>>1;
        int leftSum = queryRangeUtil(2 * idx + 1, low, mid, l, r);
        int rightSum = queryRangeUtil(2 * idx + 2, mid + 1, high, l, r);
        return leftSum + rightSum;
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        segTree.resize(4 * n, 0);
        lazyTree.resize(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }

    void updateRange(int l, int r, int val) {
        updateRangeUtil(0, 0, n - 1, l, r, val);
    }

    int queryRange(int l, int r) {
        return queryRangeUtil(0, 0, n - 1, l, r);
    }
};

int main(){
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);
    cout << segTree.queryRange(1, 3) << "\n";  // Output: 3 + 5 + 7 = 15
    segTree.updateRange(1, 5, 10);              // Add 10 to elements at indices [1..5]
    cout << segTree.queryRange(1, 3) << "\n";  // Output: (3+10)+(5+10)+(7+10) = 45
    cout << segTree.queryRange(0, 5) << "\n";  // Output: 1 + 13 + 15 + 17 + 19 + 21 = 86
return 0;
}