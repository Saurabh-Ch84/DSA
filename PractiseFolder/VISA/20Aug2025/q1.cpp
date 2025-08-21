#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*

Problem Statement: Partition Set into Two Subsets with Frequency Constraints and Minimum Absolute Difference
You are given an array arr[] of n integers. 
Your task is to partition this array into two disjoint subsets S1 and S2 such that:

No element appears in both subsets. That is, if an element 

x is present in subset S1, it should not appear in S2, and vice versa.

The absolute difference between the sums of S1 and S2 should be minimized.

Each element in the array has to appear only once in either of the two subsets.

You need to output the minimum absolute difference achievable between the two subsets.

Input Format:

The first line contains an integer n, the size of the array.
The second line contains n space-separated integers representing the elements of the array.

Output Format:

Print a single integer representing the minimum absolute difference between the sums of subsets S1 and S2 
that satisfy the conditions.

*/

class Solution{
    bool recursion(vector<int> &nums,int target,int i){
        if(target==0) return true;
        if(i==0) return false;
        // cout<<"R";
        bool notTake=recursion(nums,target,i-1);
        bool take=false;
        if(nums[i]<=target) take=recursion(nums,target-nums[i],i-1);
        return take|notTake;
    }

    bool memoization(vector<int> &nums,int target,int i,vector<vector<int>> &dp){
        if(target==0) return true;
        if(i==0) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        // cout<<"M";
        bool notTake=memoization(nums,target,i-1,dp);
        bool take=false;
        if(nums[i]<=target) take=memoization(nums,target-nums[i],i-1,dp);
        return dp[i][target]=take|notTake;
    }

    bool memoization2(vector<int> &nums,int target,int i,vector<vector<int>> &dp,vector<int> &setA){
        if(target==0) return true;
        if(i==0) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        // cout<<"M";
        bool notTake=memoization2(nums,target,i-1,dp,setA);
        bool take=false;
        if(nums[i]<=target){
            take=memoization2(nums,target-nums[i],i-1,dp,setA);
            if(take) setA.push_back(nums[i]);
        }
        return dp[i][target]=take|notTake;
    }
        public:
    int getMinDiffBetweenSubsets(vector<int> &nums){
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];
        int halfSum=sum/2;
        vector<vector<int>> dp(n,vector<int>(halfSum+1,-1));
        for(int j=halfSum;j>=0;j--){
            if(memoization(nums,j,n-1,dp)){
                return abs(j-(sum-j));
            }
        }
        return -1;
    }
    int getMinDiffBetweenSubsetsGroupingElements(vector<int> &nums){
        int sum=0,n=nums.size(),actualSum=0;
        unordered_map<int,int> freqMap;
        vector<int> uniqueArr;
        for(int i=0;i<n;i++){
            if(freqMap.count(nums[i])){
                freqMap[nums[i]]++;
            }
            else{
                uniqueArr.push_back(nums[i]);
                freqMap[nums[i]]++;
                sum+=nums[i];
            }
            actualSum+=nums[i];
        }

        int halfSum=sum/2;
        int m=uniqueArr.size();
        vector<vector<int>> dp(m,vector<int>(halfSum+1,-1));
        for(int j=halfSum;j>=0;j--){
            vector<int> setA;
            if(memoization2(uniqueArr,j,m-1,dp,setA)){
                int sumA=0;
                for(int &num:setA)
                    sumA+=freqMap[num]*num;
                int sumB=actualSum-sumA;
                return abs(sumA-sumB);
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> arr1={9,8,3,1,5,3,3,7,3,7};
    vector<int> arr2={9,6,9,2,6};
    cout<<s.getMinDiffBetweenSubsets(arr1)<<endl;
    cout<<s.getMinDiffBetweenSubsetsGroupingElements(arr1)<<endl;
return 0;
}