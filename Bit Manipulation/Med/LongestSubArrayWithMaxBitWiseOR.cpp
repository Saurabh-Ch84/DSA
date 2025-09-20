#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0,maxLen=1;
        for(int &num:nums)
            maxi=max(maxi,num);
        int n=nums.size(),left=0,right=0;

        while(right<n){
            if(nums[right]==maxi){
                left=right;
                while(right<n && nums[right]==maxi)
                    right++;
                maxLen=max(maxLen,right-left);
            }
            else
                right++;
        }
        return maxLen;
    }
};

int main(){
    Solution s;
    vector<int> nums={5,7,7,1,7,7,5,5,5,5,7,7,7,0};
    cout<<s.longestSubarray(nums)<<endl;
return 0;
}