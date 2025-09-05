#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int maxProductBrute(vector<int>& nums) {
        int n=nums.size();
        int ans=-11;
        for(int i=0;i<n;i++){
            int temp=1;
            for(int j=i;j<n;j++){
                temp=temp*nums[j];
                ans=max(ans,temp);
            }
        }
        return ans;
    }
  public:
    int maxProductOptimal(vector<int>& nums) {
        int ans=INT_MIN; 
        int prefix=0,suffix=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            prefix*=nums[i];
            suffix*=nums[n-i-1];
            ans=max(ans,max(prefix,suffix));
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums1={1,3,-5,2,4,-3,0,1,6};
    cout<<s.maxProductOptimal(nums1);
return 0;
}