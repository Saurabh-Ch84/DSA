#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

using pii=pair<int,int>;
using vpii=vector<pii>;
class Solution1{
    int getCost(vpii &arr,int median,int n){
        int cost=0;
        for(auto &p: arr){
            int diff=abs(p.first-median);
            cost+=diff*p.second;
        }
        return cost;
    }
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        vpii arr;
        int sum=0, n=cost.size();
        for(int i=0;i<n;i++){
            arr.push_back({heights[i],cost[i]});
            sum+=cost[i];
        }
        // weighted Median
        sort(arr.begin(),arr.end());
        int median=0, halfSum=0, ptr=0;
        while(halfSum<(sum+1)/2 && ptr<n){
            halfSum+=arr[ptr].second;
            median=arr[ptr].first;
            ptr++;
        }
        return getCost(arr,median,n);
    }
};

using vi=vector<int>;
class Solution2 {
    int getCost(int mid,vi &heights,vi &cost,int n){
        int total=0;
        for(int i=0;i<n;i++){
            int diff=abs(heights[i]-mid);
            total+=diff*cost[i];
        }
        return total;
    }
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n=cost.size(), low=1e9, high=0;
        for(int i=0;i<n;i++){
            low=min(low,heights[i]);
            high=max(high,heights[i]);
        }
        
        int ans=-1;
        while(low<=high){
            int mid=(low)+(high-low)/2;
            int costMid=getCost(mid,heights,cost,n);
            int costRight=getCost(mid+1,heights,cost,n);
            if(costMid<=costRight){
                ans=costMid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};

using vi=vector<int>;
class Solution3 {
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
class Solution4 {
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