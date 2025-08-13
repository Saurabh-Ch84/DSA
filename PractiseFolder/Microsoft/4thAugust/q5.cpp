#include<iostream>
#include<vector>
#include<map>
using namespace std;

//Find the smallest subset that gives the maximum OR value

class Solution{
    int recursion(vector<int> &nums,int maxOr,int i,int n,int currOr){
        if(currOr==maxOr) return 0;
        if(i>=n) return 1e6;
        int notTake=recursion(nums,maxOr,i+1,n,currOr);
        int take=1+recursion(nums,maxOr,i+1,n,currOr|nums[i]);
        return min(take,notTake);
    }
    int memoization(vector<int> &nums,int maxOr,int i,int n,int currOr,map<pair<int,int>,int> &dp){
        if(currOr==maxOr) return 0;
        if(i>=n) return 1e6;
        if(dp.count({i,currOr})) return dp[{i,currOr}];
        int notTake=memoization(nums,maxOr,i+1,n,currOr,dp);
        int take=1+memoization(nums,maxOr,i+1,n,currOr|nums[i],dp);
        return dp[{i,currOr}]=min(take,notTake);
    }
        public:
    int findSmallestSubSetWithMaxOR(vector<int> &nums){
        int maxORVal=0;
        for(int &num:nums) maxORVal|=num;
        // return recursion(nums,maxORVal,0,nums.size(),0);
        map<pair<int,int>,int> dp;
        return memoization(nums,maxORVal,0,nums.size(),0,dp);
    }
};

int main(){
    Solution s;                     //3        1           2         4          1
    vector<vector<int>> testcase={{1, 2, 4},{1, 2, 3},{5, 2, 5},{8, 1, 2, 4},{7, 1, 2}};
    cout<<s.findSmallestSubSetWithMaxOR(testcase[2]);

return 0;
}