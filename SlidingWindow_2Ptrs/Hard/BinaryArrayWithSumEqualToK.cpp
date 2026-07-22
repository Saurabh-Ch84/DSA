#include<iostream>
#include<vector>
using namespace std;

// striver's version
class Solution {
    int helper(vector<int> &nums,int goal,int n){
        if(goal<0) return 0;
        int left=0,right=0,count=0,sum=0;
        while(right<n){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int s1=helper(nums,goal,n),s2=helper(nums,goal-1,n);
        int ans=s1-s2;
        return ans;
    }
};

int main(){

return 0;
}