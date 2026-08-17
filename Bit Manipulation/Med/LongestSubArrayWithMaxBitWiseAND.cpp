#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(), maxAND=0;
        for(int i=0;i<n;i++)
            maxAND=max(maxAND,nums[i]);
        int left=-1, right=0, maxi=0;
        while(right<n){
            if(nums[right]==maxAND){
                if(left==-1) left=right;
                maxi=max(maxi,right-left+1);
            }
            else left=-1;
            right++;
        }
        return maxi;
    }
};

int main(){
    Solution s;
    vector<int> nums={5,7,7,1,7,7,5,5,5,5,7,7,7,0};
    cout<<s.longestSubarray(nums)<<endl;
return 0;
}