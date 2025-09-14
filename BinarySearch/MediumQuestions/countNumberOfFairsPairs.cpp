#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int lowerBound(vector<int> &nums,int target,int low,int high){
        int ansIdx=high+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                ansIdx=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ansIdx;
    }

    int upperBound(vector<int> &nums,int target,int low,int high){
        int ansIdx=high+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                ansIdx=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ansIdx;
    }

    long long mergeSort(vector<int>& nums,int lower,int upper,int low,int high){
        if(low>=high){
            return 0;
        }
        int mid=low+(high-low)/2;
        long long count=0;
        count+=mergeSort(nums,lower,upper,low,mid);
        count+=mergeSort(nums,lower,upper,mid+1,high);
        count+=countPairs(nums,low,high,mid,lower,upper);
        merge(nums,low,high,mid);
        return count;
    }

    long long countPairs(vector<int> &nums,int low,int high,int mid,int lower,int upper){
        long long count=0;
        for(int i=low;i<=mid;i++){
            int lb=lowerBound(nums,lower-nums[i],mid+1,high);
            int ub=upperBound(nums,upper-nums[i],mid+1,high);
            if(lb>=ub) continue;
            count+=ub-lb;
        }
        return count;
    }

    void merge(vector<int> &nums,int low,int high,int mid){
        vector<int> temp;
        int left=low,right=mid+1;
        while(left<=mid && right<=high){
            if(nums[right]<nums[left])
                temp.push_back(nums[right++]);
            else
                temp.push_back(nums[left++]);
        }

        while(left<=mid)
            temp.push_back(nums[left++]);

        while(right<=high)
            temp.push_back(nums[right++]);

        for(int i=low;i<=high;i++)
            nums[i]=temp[i-low];
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        return mergeSort(nums,lower,upper,0,n-1);
    }
};

int main(){
    Solution s;
    vector<int> nums={9,8,3,1,5,3,3,7,3,6};
    int lower=13,upper=14;
    cout<<s.countFairPairs(nums,lower,upper)<<endl;
return 0;
}