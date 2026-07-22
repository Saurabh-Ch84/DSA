#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount=0,n=nums.size();
        int left=0,right=0,maxLen=0;
        while(right<n){
            if(nums[right]==0) zeroCount++;
            while(zeroCount>1){
                if(nums[left]==0) zeroCount--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return max(0,maxLen-1);
    }
};

int main(){

return 0;
}