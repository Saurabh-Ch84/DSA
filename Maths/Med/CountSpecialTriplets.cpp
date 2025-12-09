#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// Best
class Solution {
    const int MOD=1e9+7;
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<long long,int> validI;
        unordered_map<long long,int> validJ;
        long long count=0;
        for(int &num: nums){
            // can this be a valid k
            if(num%2==0) count=(count+validJ[1LL*num/2])%MOD;
            // can this be a valid j
            validJ[1LL*num]=(validJ[1LL*num]+validI[1LL*num*2])%MOD;
            // store it as valid i
            validI[1LL*num]++;
        }
        return (int)count;
    }
};

// Optimal
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        
        // Map 1: Tracks frequency of elements to the RIGHT of current index
        unordered_map<long long, int> rightMap;
        
        // Map 2: Tracks frequency of elements to the LEFT of current index
        unordered_map<long long, int> leftMap;

        // Pass 1: Fill rightMap with all frequencies initially
        for (int num : nums)
            rightMap[num]++;

        long long totalCount = 0;

        // Pass 2: Iterate and process "Middle-Out"
        for (int i = 0; i < n; i++) {
            long long current = nums[i];
            // 1. Remove current element from Right Map (it is now the Center)
            rightMap[current]--;
            // 2. Define the target we are looking for (2 * current)
            long long target = current * 2;
            // 3. Calculate triplets: (Count of target on Left) * (Count of target on Right)
            // We use .count() or just simple [] access (which returns 0 if empty)
            if (leftMap.count(target) && rightMap.count(target)) {
                long long validLeft = leftMap[target];
                long long validRight = rightMap[target];
                
                totalCount = (totalCount + (validLeft * validRight)) % MOD;
            }
            // 4. Add current element to Left Map (it becomes Left for the next index)
            leftMap[current]++;
        }

        return (int)totalCount;
    }
};

//Better
class Solution {
    int lowerBound(vector<int> &arr,int n,int target){
        int low=0,high=n-1,idx=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=target){
                high=mid-1;
                idx=mid;
            }
            else low=mid+1;
        }
        return idx;
    }

    long long nC3(long long n){
        return 1LL*(n*(n-1)*(n-2))/6;
    }
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        const int MOD=1e9+7;
        unordered_map<int,vector<int>> hashMap;
        long long zero=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) zero++;
            hashMap[nums[i]].push_back(i);
        }
        long long count=(0+nC3(zero))%MOD;
        for(int i=1;i<n-1;i++){
            if(nums[i]==0) continue;
            int target=nums[i]*2;
            if (!hashMap.count(target)) continue;
            vector<int> &temp=hashMap[target];
            int m=temp.size();
            int idx=lowerBound(temp,m,i);
            count=(count+1LL*(m-idx)*(idx))%MOD;
        }
        return (int)count;
    }
};

int main(){

return 0;
}