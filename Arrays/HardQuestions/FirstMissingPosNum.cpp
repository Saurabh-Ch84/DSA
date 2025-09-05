#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool containsOne=false;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1)
                containsOne=true;
            else if(nums[i]<=0 || nums[i]>n)
                nums[i]=1;
        }

        if(containsOne==false) return 1;

        for(int i=0;i<n;i++){
            int num=abs(nums[i]);
            int idx=num-1;
            if(nums[idx]>0) nums[idx]*=-1;
        }

        for(int i=0;i<n;i++)
            if(nums[i]>0) return i+1;

        return n+1;
    }
};

int main(){
    Solution s;
    vector<int> nums1={3,2,-1,-9,0,12};
    cout<<s.firstMissingPositive(nums1);
return 0;
}