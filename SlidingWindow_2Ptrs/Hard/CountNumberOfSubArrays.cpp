#include<iostream>
#include<vector>
using namespace std;

//striver's version
class Solution {
    int helper(vector<int> &nums,int k,int n){
        if(k<0) return 0;
        int left=0,right=0,count=0,sum=0;
        while(right<n){
            int num1=nums[right]%2;
            sum+=num1;
            while(sum>k){
                int num2=nums[left]%2;
                sum-=num2;
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        return helper(nums,k,n)-helper(nums,k-1,n);
    }
};

int main(){

return 0;
}