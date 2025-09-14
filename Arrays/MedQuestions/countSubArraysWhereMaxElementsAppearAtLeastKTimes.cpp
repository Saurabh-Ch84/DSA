#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),maxi=0;
        for(int i=0;i<n;i++)
            maxi=max(maxi,nums[i]);

        int left=0,right=0,maxCount=0;
        long long count=0;
        while(right<n){
            if(nums[right]==maxi) 
                maxCount++;
            while(maxCount>=k && left<n){
                count+=n-right;
                if(nums[left]==maxi) 
                    maxCount--;
                left++;
            }
            right++;
        }

        return count;
    }
};

int main(){
    Solution s;
    vector<int> nums={5,2,7,6,7,3,1};
    int k=2;
    cout<<s.countSubarrays(nums,k);
return 0;
}