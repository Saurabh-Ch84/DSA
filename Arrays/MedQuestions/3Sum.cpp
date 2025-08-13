#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int left = 0; left < n - 2; left++)
        {
            // Skip duplicates for the first element
            if (left > 0 && nums[left] == nums[left - 1]) continue;
            int mid = left + 1;
            int right = n - 1;
            while (mid < right)
            {
                int sum=nums[left] + nums[mid] + nums[right];
                if (sum==0)
                {
                    ans.push_back({nums[left], nums[mid], nums[right]});
                    mid++;
                    right--;
                    // Skip duplicates for the second element
                    while (mid < right && nums[mid] == nums[mid-1]) mid++;
                    // Skip duplicates for the third element
                    while (mid < right && nums[right] == nums[right+1]) right--;
                }
                else if (sum < 0) mid++;
                else right--;
            }
        }
        return ans;
    }
};


int main(){

return 0;
}