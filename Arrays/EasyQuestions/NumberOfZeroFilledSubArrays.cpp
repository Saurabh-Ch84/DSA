#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int right=0,n=nums.size();
        long long totalCount=0,countZeros=0;
        while(right<n){
            if(nums[right]==0) countZeros++;
            if(nums[right]!=0 || right==n-1){
                totalCount+=1LL*(countZeros*(countZeros+1))/2;
                countZeros=0;
            }
            right++;
        }
        return totalCount;
    }
};

int main(){

return 0;
}