#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int ansIdx=nums.size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>=target)
            {
                high=mid-1;
                ansIdx=mid;
            }
            else low=mid+1;
        }
        return ansIdx;
    }
};

int main(){

return 0;
}