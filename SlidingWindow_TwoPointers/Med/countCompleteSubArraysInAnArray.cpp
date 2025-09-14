#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int distinctNumsCount(vector<int>& nums){
        unordered_set<int> hashSet(nums.begin(),nums.end());
        return hashSet.size();
    }
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int count=0,n=nums.size();
        int n_=distinctNumsCount(nums);

        unordered_map<int,int> hashMap;
        int left=0,right=0;
        while(right<n){
            hashMap[nums[right]]++;
            while(left<n && hashMap.size()==n_){
                count+=(n-right);
                hashMap[nums[left]]--;
                if(hashMap[nums[left]]==0)
                    hashMap.erase(nums[left]);
                left++;
            }
            right++;
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> nums={9,5,3,5,3,3,3};
    cout<<s.countCompleteSubarrays(nums)<<endl;
return 0;
}