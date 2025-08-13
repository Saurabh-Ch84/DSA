#include<iostream>
#include<vector>
using namespace std;

class Solution{
        public:
    int findElement(int target,vector<int> &nums){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<nums[mid]) high=mid-1;
                else low=mid+1;
            }
            else{
                if(nums[mid]<target && target<=nums[high]) low=mid+1;
                else high=mid-1;
            }
        }
        return -1;
    }

    int findPivot(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int minNum=1e8,pivotIndx=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[high]){
                if(nums[low]<minNum){
                    pivotIndx=low;
                    minNum=nums[low];
                }
                break;
            }
            else if(nums[low]<=nums[mid]){
                if(nums[low]<minNum){
                    pivotIndx=low;
                    minNum=nums[low];
                }
                low=mid+1;
            }
            else{
                if(nums[mid]<minNum){
                    pivotIndx=mid;
                    minNum=nums[mid];
                }
                high=mid-1;
            }
        }
        return pivotIndx;
    }

};


int main(){
    int num,n;
    Solution s;
    // cout<<"Enter size of the array:- ";
    // cin>>n;
    vector<int> nums={5,6,7,8,9,11,1,2,3};
    // cout<<"Enter elements of the array:- ";
    // for(int i=0;i<n;i++) cin>>nums[i];
    // cout<<"Enter key:- ";
    // num=;
    // cout<<s.findElement(num,nums);
    cout<<s.findPivot(nums);
return 0;
}