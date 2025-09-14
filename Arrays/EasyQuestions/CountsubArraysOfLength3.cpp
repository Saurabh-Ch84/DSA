#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(int a,int b,int c){
        return (b==(a+c)*2);
    }
    
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=0,count=0;
        while(right<n){
            if(right-left+1==3){
                if(isValid(nums[left],nums[left+1],nums[right]))
                    count++;
                left++;
            }
            right++;
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> nums={9,8,3,1,8,3,3,7,3,6};
    cout<<s.countSubarrays(nums);
return 0;
}