#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
    int binSearch(vector<int> &nums,int target,int low,int n){
        int high=n-1,idx=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                idx=mid;
                break;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else low=mid+1;
        }
        return idx;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ptr=0,n=numbers.size();
        int left=-1,right=-1;
        while(ptr<n){
            int number=numbers[ptr];
            int compliment=target-number;
            int compIdx=binSearch(numbers,compliment,ptr+1,n);
            if(compIdx!=-1){
                // 1-based indexing
                left=ptr+1;
                right=compIdx+1;
            }
            ptr++;
        }
        return {left,right};
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int left=0,right=n-1;

        vector<int> ans(2,-1);
        while(left<right){
            int sum=numbers[left]+numbers[right];
            if(sum==target){
                //1-based indexing
                ans[0]=left+1;
                ans[1]=right+1;
                break;
            }
            else if(sum>target){
                right--;
            }
            else left++;
        }

        return ans;
    }
};

int main(){

return 0;
}