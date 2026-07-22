#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution1 {
    //Brute-Force
public:
    int longestBalanced(vi & nums) {
        int n=nums.size(), maxi=0;
        vi cumSum(n,0);
        unordered_map<int,int> hashMap;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int val=(1 & num ? -1: 1);
            if(hashMap.count(num)){
                for(int j=0;j<=i;j++)
                    cumSum[j]-=val;
            }
            for(int j=0;j<=i;j++){
                cumSum[j]+=val;
                if(!cumSum[j]) maxi=max(maxi,i-j+1);
            }
            hashMap[nums[i]]=i;
        }
        return maxi;
    }
};

using vi = vector<int>;
class Solution2 {
    class SegmentTree {
        int n;
        vi segTreeMax, segTreeMin, lazyTree;

        void propagate(int i, int low, int high) {
            if (lazyTree[i] != 0) {
                segTreeMax[i] += lazyTree[i];
                segTreeMin[i] += lazyTree[i];
                if (low != high) {
                    lazyTree[2 * i + 1] += lazyTree[i];
                    lazyTree[2 * i + 2] += lazyTree[i];
                }
                lazyTree[i] = 0;
            }
        }

        void rangeUpdate(int l, int r, int i, int low, int high, int val) {
            propagate(i, low, high);
            if (low > r || high < l) return;
            if (low >= l && high <= r) {
                lazyTree[i] += val;
                propagate(i, low, high);
                return;
            }
            int mid = low + (high - low) / 2;
            rangeUpdate(l, r, 2 * i + 1, low, mid, val);
            rangeUpdate(l, r, 2 * i + 2, mid + 1, high, val);
            segTreeMax[i] = max(segTreeMax[2 * i + 1], segTreeMax[2 * i + 2]);
            segTreeMin[i] = min(segTreeMin[2 * i + 1], segTreeMin[2 * i + 2]);
        }

        int query(int i, int low, int high, int ub) {
            propagate(i, low, high);
            // Optimization: If range is completely outside query range
            if (low >= ub) return -1;
            // Pruning: If 0 is impossible in this range (min > 0 or max < 0), stop.
            if (segTreeMin[i] > 0 || segTreeMax[i] < 0) return -1;
            if (low == high){
                return (segTreeMax[i] == 0) ? low : -1;
            }
            int mid = low + (high - low) / 2;
            // Try left child first to find the LEFTMOST index
            int leftRes = query(2 * i + 1, low, mid, ub);
            if (leftRes != -1) return leftRes;
            return query(2 * i + 2, mid + 1, high, ub);
        }

    public:
        SegmentTree(int size) {
            n = size;
            segTreeMax.assign(4 * n, 0);
            segTreeMin.assign(4 * n, 0);
            lazyTree.assign(4 * n, 0);
        }

        void update(int l, int r, int val) {
            if (l > r) return;
            rangeUpdate(l, r, 0, 0, n - 1, val);
        }

        // Only query up to current index 'i' to avoid uninitialized zeros
        int queryLeftMostZero(int ub) {
            return query(0, 0, n - 1, ub);
        }
    };

public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        unordered_map<int, int> lastPos; // Stores last seen index of each value
        SegmentTree sgt(n);

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int val = (num & 1) ? -1 : 1; // Odd: -1, Even: 1
            // 1. If duplicate, remove its previous contribution
            // This ensures we only count distinct elements for ranges starting <= lastPos
            if (lastPos.count(num)) {
                int i_ = lastPos[num];
                // Subtract 'val' from all ranges that included the previous instance
                sgt.update(0, i_, -val); 
            }
            // 2. Add current contribution
            // Add 'val' to all ranges ending at 'i' (starts 0 to i)
            sgt.update(0, i, val);
            // 3. Update map
            lastPos[num] = i;
            // 4. Query for the leftmost start index 'k' where Sum(k...i) == 0
            int k = sgt.queryLeftMostZero(i);
            if (k != -1) maxi = max(maxi, i - k + 1);
        }
        return maxi;
    }
};

int main(){

return 0;
}