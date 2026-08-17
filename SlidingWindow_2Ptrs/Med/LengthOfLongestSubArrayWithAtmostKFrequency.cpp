#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size(), left=0, right=0, maxi=0;
        unordered_map<int,int> hashMap;
        
        while(right<n){
            hashMap[nums[right]]++;
            while(hashMap[nums[right]]>k && left<right){
                hashMap[nums[left]]--;
                if(!hashMap[nums[left]])
                    hashMap.erase(nums[left]);
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};

int main(){

return 0;
}