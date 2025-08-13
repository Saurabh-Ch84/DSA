#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        int minNum=1e8;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[low]==nums[high]){
                minNum = min(nums[low], minNum);
                low++;
                high--;
            }
            else if(nums[low]<=nums[high]){
                minNum = min(nums[low], minNum);
                break;
            }
            else if(nums[low]<=nums[mid]){
                minNum = min(nums[low], minNum);
                low = mid+1;
            }
            else{
                minNum = min(nums[mid], minNum);
                high = mid-1;
            }
        }
        return minNum;
    }
};


int main(){

return 0;
}