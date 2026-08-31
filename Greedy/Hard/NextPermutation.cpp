#include<bits/stdc++.h>
using namespace std;

class Solution {
    int getJustMaxIdx(vector<int> &nums,int l,int n,int x){
        int maxIdx=l;
        for(int i=l+1;i<n;i++){
            int num=nums[i];
            // equal to cause we want to place it as far as possible.
            if(num>x && nums[maxIdx]>=num) 
                maxIdx=i;
        }
        return maxIdx;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                int j=getJustMaxIdx(nums,i+1,n,nums[i]);
                swap(nums[i],nums[j]);
                reverse(nums.begin()+i+1,nums.end());
                return ;
            }
        }
        reverse(nums.begin(),nums.end());
    }
};

int main(){

return 0;
}