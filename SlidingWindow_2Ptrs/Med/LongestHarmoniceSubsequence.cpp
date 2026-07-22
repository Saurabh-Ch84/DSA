#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int maxLen=0,left=0,right=0,n=nums.size();
        while(right<n){
            while(nums[right]-nums[left]>1)
                left++;
            if(nums[right]-nums[left]==1)
                maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};

int main(){
    Solution s;
    vector<int> nums={9,8,3,1,5,3,3,7,3,6};
    cout<<s.findLHS(nums);
return 0;
}