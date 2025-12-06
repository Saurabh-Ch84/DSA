#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=1,high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]) 
                return nums[mid];
            if(nums[low]<=nums[mid]) low=mid+1;
            else high=mid-1;
        }
        return min(nums[0],nums[n-1]);
    }
};

class Solution2 {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int minNum=5001;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[high]){
                minNum=min(nums[low],minNum);
                break;
            }
            else if(nums[low]<=nums[mid]){
                minNum=min(nums[low],minNum);
                low=mid+1;
            }
            else{
                minNum=min(nums[mid],minNum);
                high=mid-1;
            }
        }
        return minNum;
    }
};

int main(){

return 0;
}