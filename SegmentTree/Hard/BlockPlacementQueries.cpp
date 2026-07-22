#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint = vector<int>;
    using vbool = vector<bool>;
    
    class SegmentTree {
        vint sgt;
        int n;
        set<int> hashSet; 
        
        void updateTree(int i, int v, int idx, int low, int high) {
            if (low == high) {
                sgt[idx] = v;
                return;
            }
            int mid = low + (high - low) / 2;
            if (i <= mid) updateTree(i, v, 2 * idx + 1, low, mid);
            else updateTree(i, v, 2 * idx + 2, mid + 1, high);
            sgt[idx] = max(sgt[2 * idx + 1], sgt[2 * idx + 2]);
        }
        
        bool queryTree(int x, int sz, int idx, int low, int high) {
            // Prune if this range starts after x, or if the max gap here is too small
            if (x < low || sgt[idx] < sz) return false;
            if (high <= x) return true; 
            int mid = low + (high - low) / 2;
            if (queryTree(x, sz, 2 * idx + 1, low, mid)) return true;
            // Only check right child if 'x' actually extends into it
            if (x > mid) return queryTree(x, sz, 2 * idx + 2, mid + 1, high);
            return false;
        }
        
    public:
        SegmentTree(int limit) {
            n = limit;
            sgt.resize(4 * n + 1, 0);
            hashSet.insert(0);
            hashSet.insert(n);
        }

        void updateQuery(int x) {
            auto rightItr = hashSet.upper_bound(x);
            auto leftItr = prev(rightItr);
            int left = *leftItr, right = *rightItr;
            hashSet.insert(x);
            // Update the segment tree
            updateTree(x, x - left, 0, 0, n-1);
            updateTree(right, right - x, 0, 0, n-1);
        }

        bool query(int x, int sz) {
            if (sz > x) return false;
            if (hashSet.size() == 2) return true;
            
            auto it = hashSet.upper_bound(x);
            int pre = *prev(it);
            
            // 1. Check the gap from the last obstacle BEFORE x, up to x itself
            if (x - pre >= sz) return true;
            // 2. Check if any gap between obstacles before 'pre' is large enough
            return queryTree(pre, sz, 0, 0, n-1);
        }
    };
    
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        // Optimization: Find the exact max coordinate we actually need
        int max_coord = 0;
        for (auto &query : queries) {
            max_coord = max(max_coord, query[1]);
        }
        SegmentTree sgt(max_coord + 5); 
        vbool res;
        for (auto &query : queries) {
            if (query[0] == 1) sgt.updateQuery(query[1]);
            else res.push_back(sgt.query(query[1], query[2]));
        }
        return res;
    }
};


int main(){

return 0;
}