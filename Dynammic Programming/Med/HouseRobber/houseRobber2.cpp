#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int robbing(vector<int> &nums,int idx){
        int prevPrev=0, prev=0;
        int maxi=0, n=nums.size();
        for(int i=idx; i<n-(1-idx); i++){
            maxi = max(prevPrev + nums[i], prev);
            prevPrev = prev;
            prev = maxi;
        }
        return maxi;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(robbing(nums,0), robbing(nums,1));
    }
};


class Solution {
    public:
        int rob(vector<int>& nums) {
            int n=nums.size();
            if(n==1) return nums[0];
            if(n==2) return max(nums[0],nums[1]);
            vector<int> dp1(n-1,0),dp2(n-1,0);
            dp1[0]=nums[0],dp2[0]=nums[1];
            dp1[1]=max(nums[0],nums[1]);
            dp2[1]=max(nums[1],nums[2]);
            for(int i=2;i<n-1;i++)
            {
                dp1[i]=max(nums[i]+dp1[i-2],dp1[i-1]);
                dp2[i]=max(nums[i+1]+dp2[i-2],dp2[i-1]);
            }
            return max(dp1[n-2],dp2[n-2]);
        }
    };

int main(){

return 0;
}