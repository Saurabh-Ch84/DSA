#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int maxIdx = -1, minIdx = -1, invalidIdx = -1;
        long long count = 0;
        
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num < minK || num > maxK) {
                invalidIdx = i;
                minIdx = -1;
                maxIdx = -1;
                continue;
            }
            
            if (num == minK) minIdx = i;
            if (num == maxK) maxIdx = i;
            
            if (minIdx != -1 && maxIdx != -1) {
                int validStart = min(minIdx, maxIdx);
                count += (validStart - invalidIdx);
            }
        }
        return count;
    }
};

int main(){

return 0;
}