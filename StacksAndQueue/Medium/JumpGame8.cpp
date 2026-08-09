#include<bits/stdc++.h>
using namespace std;

/*
            Problem Description
        
    You are given a 0-indexed integer array nums of length n. You are initially standing at index 0. 
    You can jump from index i to index j where i < j if one of the following conditions is met:

    Ascending Jump: nums[i] <= nums[j] and nums[k] < nums[i] for all indices k such that i < k < j.
    (You jump to the next element that is greater than or equal to nums[i], and all intermediate elements are strictly smaller than nums[i]).

    Descending Jump: nums[i] > nums[j] and nums[k] >= nums[i] for all indices k such that i < k < j.
    (You jump to the next element that is strictly smaller than nums[i], and all intermediate elements are greater than or equal to nums[i]).

    You are also given an integer array costs of length n where costs[i] denotes the cost of jumping to index i.

    Goal: Return the minimum cost to jump to the index n - 1.

        Constraints

    1 <= nums.length <= 10^5
    1 <= nums[i], costs[i] <= 10^9
    It is guaranteed that you can reach index n - 1 from index 0.
*/


/*
    Input: nums = [3, 2, 4, 2, 1], costs = [0, 10, 15, 20, 25]
    Output: 35
    Explanation: 
    - Jump from index 0 (val 3) to index 1 (val 2): Valid descending jump (3 > 2, no intermediates). Cost += 10.    
    - Jump from index 1 (val 2) to index 4 (val 1): Valid descending jump (2 > 1, intermediates [4, 2] are >= 2? 
    No, 4>=2 yes, 2>=2 yes). Wait, let's re-verify the path.
    
    Actually, a valid path is 0 -> 1 -> 4.
    0->1: 3 > 2, intermediates empty. Valid. Cost = 10.
    1->4: 2 > 1, intermediates [4, 2]. Are they >= 2? 4>=2 (yes), 2>=2 (yes). Valid. Cost = 10 + 25 = 35.

    Another path: 0->2 (3<=4, intermediates [2] < 3? Yes). Cost = 15.
    2->3 (4>2, intermediates empty). Cost = 15+20=35.
    3->4 (2>1, intermediates empty). Cost = 35+25=60.

    Minimum is 35.
*/


class Solution {
    vector<int> getNSE(vector<int> &nums,int n){
        stack<int> st;
        vector<int> res(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            if(!st.empty()) res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> getNGE(vector<int> &nums,int n){
        stack<int> st;
        vector<int> res(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i])
                st.pop();
            if(!st.empty()) res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    long long recursion(int i,int n,vector<int> &nums,vector<int> &nge,vector<int> &nse,vector<int> &costs,vector<long long> &dp){
        if(i==n-1) return 0; 
        if(dp[i]!=-1) return dp[i];
        long long choice1=1e15, choice2=1e15;
        if(nge[i]<n) choice1=costs[nge[i]]+recursion(nge[i],n,nums,nge,nse,costs,dp);
        if(nse[i]<n) choice2=costs[nse[i]]+recursion(nse[i],n,nums,nge,nse,costs,dp);
        return dp[i]=min(choice1,choice2);
    }
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int n=nums.size();
        vector<int> nse=getNSE(nums,n);
        vector<int> nge=getNGE(nums,n);
        vector<long long> dp(n+1,-1);
        return recursion(0,n,nums,nge,nse,costs,dp);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 4, 2, 1};
    vector<int> costs = {0, 10, 15, 20, 25};
    cout << sol.minCost(nums, costs) << endl;
    return 0;
}