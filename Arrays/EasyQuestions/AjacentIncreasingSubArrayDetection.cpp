#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isIncreasing(vector<int> &nums,int idx,int k,int n){
        if(k+idx>n) return false;
        for(int i=idx+1;i<idx+k;i++)
            if(nums[i]<=nums[i-1]) return false;
        return true;
    }
public:
    bool hasIncreasingSubarrays1(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!isIncreasing(nums,i,k,n)) continue;
            if(isIncreasing(nums,i+k,k,n)) return true;
        }
        return false;
    }

    bool hasIncreasingSubarrays2(vector<int>& nums, int k) {
        int n=nums.size();
        int prev=0,curr=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) curr++;
            else{
                prev=curr;
                curr=1;
            }
            if(curr>=2*k || min(prev,curr)>=k) return true;
        }
        return false;
    }
};

int main(){

return 0;
}