#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int recursion(vector<int>&nums,int size,int currIndx,int prevIndx){
        if(currIndx>=size) return 0;
        int length=0;
        int notTake=0+recursion(nums,size,currIndx+1,prevIndx);
        int take=0;
        if(prevIndx==-1 || nums[currIndx]>nums[prevIndx])
            take=1+recursion(nums,size,currIndx+1,currIndx);
        return max(notTake,take);
    }

    int memoization(vector<int>& nums, int size, int currIndx, int prevIndx,
                    vector<vector<int>>& dp) {
        if (currIndx >= size)
            return 0;
        if (dp[currIndx][prevIndx + 1] != -1)
            return dp[currIndx][prevIndx + 1];
        int length = 0;
        int notTake = 0 + memoization(nums, size, currIndx + 1, prevIndx, dp);
        int take = 0;
        if (prevIndx == -1 || nums[currIndx] > nums[prevIndx])
            take = 1 + memoization(nums, size, currIndx + 1, currIndx, dp);
        return dp[currIndx][prevIndx + 1] = max(notTake, take);
    }

    int lb(vector<int> &v,int t){
        int left=0,right=v.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(v[mid]==t) return mid;
            else if(v[mid]>t) right=mid-1;
            else left=mid+1;
        }
        return left;
    }


public:
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        // vector<vector<int>> dp(m,vector<int>(m+1,-1));
        // return memoization(nums,m,0,-1,dp);
        // vector<vector<int>> dp(m+1,vector<int>(m+1,0));
        // for(int currIndx=m-1;currIndx>-1;currIndx--){
        //     for(int prevIndx=currIndx-1;prevIndx>=-1;prevIndx--){
        //         int notTake=dp[currIndx+1][prevIndx+1];
        //         int take=0;
        //         if(prevIndx==-1 || nums[currIndx]>nums[prevIndx])
        //             take=1+dp[currIndx+1][currIndx+1];
        //         dp[currIndx][prevIndx+1]=max(take,notTake);
        //     }
        // }
        // return dp[0][0];

        // vector<int> dp(m, 1), hash(m);
        // for (int i = 0; i < m; i++)
        //     hash[i] = i;

        // int ans = 1, idx = 0;
        // for (int i = 0; i < m; i++) {
        //     for (int prev = 0; prev < i; prev++) {
        //         if (nums[prev] < nums[i] && dp[i] < 1 + dp[prev]) {
        //             dp[i] = 1 + dp[prev];
        //             hash[i] = prev;
        //         }
        //     }
        //     if (ans < dp[i]) {
        //         ans = dp[i];
        //         idx = i;
        //     }
        // }

        // // Reconstruct LIS
        // vector<int> lis;
        // while (hash[idx] != idx) {
        //     lis.push_back(nums[idx]);
        //     idx = hash[idx];
        // }
        // lis.push_back(nums[idx]);
        // reverse(lis.begin(), lis.end());

        // // Print LIS
        // for (int num : lis)
        //     cout << num << " ";
        // cout << endl;

        // return ans;

        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<m;i++){
            if(nums[i]>temp.back())
                temp.push_back(nums[i]);
            else{
                auto itr=lower_bound(temp.begin(),temp.end(),nums[i]);
                *itr=nums[i];
            }
        }
        return temp.size();
    }
};

int main(){

return 0;
}