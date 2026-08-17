#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), left=0, right=0, k=0;
        while(right<n){
            int count=1;
            while(right+1<n && nums[right]==nums[right+1]){
                right++, count++;
            }
            int validCount=min(2,count);
            for(int i=0;i<validCount;i++){
                nums[left]=nums[right]; // copy the valid element to the left pointer
                left++;
            }
            k+=validCount; // add the valid count to k
            right++;
        }
        return k;
    }
};

int main(){

return 0;
}