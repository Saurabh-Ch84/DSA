#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    int helper(vector<int>&nums,int k,int n){
        if(k<0) return 0;
        int left=0,right=0,count=0;
        unordered_map<int,int> freqMap;
        while(right<n){
            freqMap[nums[right]]++;
            while(freqMap.size()>k){
                freqMap[nums[left]]--;
                if(freqMap[nums[left]]==0) 
                    freqMap.erase(nums[left]);
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return helper(nums,k,n)-helper(nums,k-1,n);
    }
};

int main(){

return 0;
}