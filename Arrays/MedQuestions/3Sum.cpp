#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++){
            if(i && nums[i]==nums[i-1]) continue;
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0) k--;
                else if(sum<0) j++;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++,k--;
                    while(j<k && nums[j-1]==nums[j]) j++;
                    while(j<k && nums[k+1]==nums[k]) k--;
                }
            }
        }
        return ans;
    }
};

class Solution2 {
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