#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hashMap = {{0, -1}};
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            if (hashMap.count(rem)) {
                if (i - hashMap[rem] >= 2) return 1;
            } 
            else hashMap[rem] = i;
        }
        return 0;
    }
};

int main(){

return 0;
}