#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0,len=0,n=nums.size(),numOfZeros=0;
        //Method-1
        while(right<n)
        {
            if(nums[right]==0) numOfZeros++;
            while(numOfZeros>k) 
                if(nums[left++]==0) numOfZeros--;
            len=max(len,right-left+1);
            right++;
        }
        //method-2
        //use one at a time
        // while(right<n)
        // {
        //     if(!nums[right]) numOfZeros++;
        //     if(numOfZeros>k){
        //         if(nums[left]==0) numOfZeros--;
        //         left++;
        //     }
        //     if(numOfZeros<=k) len=max(len,right-left+1);
        //     right++;
        // }
        return len;
    }
};

int main(){

return 0;
}