#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(int mid,int k,int n,vector<int> &nums){
        int i=0;
        while(i<n){
            if(nums[i]<=mid){
                // rob this house
                k--;
                // skip the next house
                i+=2;
                // if we have robbed k houses, return true
                if(k==0) return true;
            }
            // if we cannot rob this house, move to the next house
            else i+=1;
        }
        // if we have not robbed k houses, return false
        return false;
    }   
public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size(), low=nums[0], high=nums[0];
        for(int i=1;i<n;i++){
            low=min(low,nums[i]);
            high=max(high,nums[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,k,n,nums)){
                // if we can rob k houses with capability mid, try to find a smaller capability
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};

int main(){

return 0;
}