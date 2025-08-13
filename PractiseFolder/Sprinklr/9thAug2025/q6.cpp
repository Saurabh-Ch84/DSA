#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Maximum score possible after performing given operations on an Array:-

Given an array A of size N, the task is to find the maximum score possible of this array. The score of an array is calculated by performing the following operations on the array N times: 

1. If the operation is odd-numbered, the score is incremented by the sum of all elements of the current array.
2. If the operation is even-numbered, the score is decremented by the sum of all elements of the current array. 
3. After every operation, either remove the first or the last element of the remaining array. 
*/

class Solution{
    int recursion(int left,int right,vector<int> &nums,int sum,bool isOdd=true){
        if(left>right) return 0;
        int score=0;
        if(!isOdd) score-=sum;
        else score+=sum;
        return score+max(recursion(left+1,right,nums,sum-nums[left],!isOdd),
                        recursion(left,right-1,nums,sum-nums[right],!isOdd));
    }

    int memoization(int left,int right,vector<int> &nums,vector<int> &prefixSum,
                    unordered_map<int,unordered_map<int,int>> &dp,bool isOdd=true){
        if(left>right) return 0;
        int innerKey=right*2+(isOdd?1:0);
        if(dp[left][innerKey]) return dp[left][innerKey];
        int currScore=prefixSum[right+1]-prefixSum[left];
        if(!isOdd) currScore=currScore*(-1);
        return dp[left][innerKey]=currScore+max(memoization(left+1,right,nums,prefixSum,dp,!isOdd),
                        memoization(left,right-1,nums,prefixSum,dp,!isOdd));
    }
    
        public:
    int maxScorePossible(vector<int>& nums){
        int sum=0,n=nums.size();
        vector<int> prefixSum(n+1,0);
        for(int i=0;i<n;i++){
            // sum+=nums[i];
            prefixSum[i+1]=prefixSum[i]+nums[i];
        }
        // return recursion(0,n-1,nums,sum);
        unordered_map<int,unordered_map<int,int>> dp;
        return memoization(0,n-1,nums,prefixSum,dp);
    }
};

int main(){
    Solution s;
    vector<int> arr1 = {1, 2, 3};
    int expected1 = 5;
    vector<int> arr2 = {5, -2, 3, 1};
    int expected2 = 8;
    vector<int> arr3 = {4, 2, 10};
    int expected3 = 14;
    vector<int> arr4 = {-1, -2, -3};
    int expected4 = -3;
    vector<int> arr5 = {0, 7, -3, 4};
    int expected5 = 11;
    vector<int> arr={ 1, 2, 3, 4, 2, 6 };
    int expected=13;

    cout<<s.maxScorePossible(arr)<<endl;
    cout<<s.maxScorePossible(arr1)<<endl;
    cout<<s.maxScorePossible(arr2)<<endl;
    cout<<s.maxScorePossible(arr3)<<endl;
    cout<<s.maxScorePossible(arr4)<<endl;
    cout<<s.maxScorePossible(arr5)<<endl;
return 0;
}