#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
You are given a sorted array with k times rotation and k is unknown. So, you need to write and 
run that code to find k for 2-3 test cases.
Example array: {6, 7, 8, 1, 2, 3, 4, 5} Ans: k = 3.
*/

class Solution{
        public:
    int findK(vector<int> &nums){
        int low=0,high=nums.size()-1;
        while(low<=high){
            if(nums[low]<nums[high]) return low;
            int mid=low+(high-low)/2;
            if((mid==0 || nums[mid]<nums[mid-1]) && (mid==nums.size()-1 || nums[mid]<nums[mid+1])) 
                return mid;
            else if(nums[mid]>nums[high])
                low=mid+1;
            else if(nums[mid]<nums[high])
                high=mid-1;
            else high--;
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<int> nums1= {6, 7, 8, 1, 2, 3, 4, 5};
    vector<int> nums2= {6, 18, 0, 1, 1, 1, 4, 5};
    cout<<s.findK(nums1)<<endl;
    cout<<s.findK(nums2)<<endl;
return 0;
}