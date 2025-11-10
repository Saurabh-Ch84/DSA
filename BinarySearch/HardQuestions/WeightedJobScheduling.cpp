#include<iostream>
#include<bits/stdc++.h>

using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using pii = pair<int, int>;
using u_mii= unordered_map<int,int> ;

class Solution1 {
    int findNextJob(int i,vvi &jobs,int n){
        int currEndTime=jobs[i][1];
        int low=i+1,high=n-1,nextValidIndex=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            int startTime=jobs[mid][0];
            if(startTime>=currEndTime){
                nextValidIndex=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return nextValidIndex;
    }
    
    int memoization(int i,int n,vvi &jobs,vi &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int notTake=memoization(i+1,n,jobs,dp);
        int nextJobIndex=findNextJob(i,jobs,n);
        int take=jobs[i][2]+memoization(nextJobIndex,n,jobs,dp);
        return dp[i]=max(notTake,take);
    }
    
  public:
    int maxProfit(vvi &jobs) {
        // code here
        int n=jobs.size();
        sort(jobs.begin(),jobs.end());
        vi dp(n,-1);
        return memoization(0,n,jobs,dp);
    }
};

class Solution2 {
    int lowerBound(int low,int high,int target,vvi &arr){
        int ansIdx=high+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid][0]>=target){
                ansIdx=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ansIdx;
    }
    int memoization(int i,int n,vvi &arr,vi &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int notTake=memoization(i+1,n,arr,dp);
        int nextIdx=lowerBound(i+1,n-1,arr[i][1],arr);
        int take=arr[i][2]+memoization(nextIdx,n,arr,dp);
        return dp[i]=max(take,notTake);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vvi arr(n);
        for(int i=0;i<n;i++){
            int st=startTime[i],et=endTime[i];
            int p=profit[i];
            arr[i]={st,et,p};
        }
        vi dp(n,-1);
        sort(arr.begin(),arr.end());
        return memoization(0,n,arr,dp);
    }
};

// Brute-force Solution.
class Solution3 {
    int recursion(int i, int n, const vvi &jobs, int endTime, u_mii &memo){
        if (i >= n) return 0;
        // Unique key based on index and endTime
        int key = (i << 15) | endTime;
        if (memo.count(key)) return memo[key];
        int notTake = recursion(i + 1, n, jobs, endTime, memo),take = 0;
        int newStartTime=jobs[i][0];
        if (newStartTime >= endTime){
            int newEndTime=jobs[i][1], profit=jobs[i][2];
            take = profit + recursion(i + 1, n, jobs, profit, memo);
        }
        return memo[key] = max(take, notTake);
    }
public:
    int maxProfit(vvi &jobs){
        int n=jobs.size();
        sort(jobs.begin(), jobs.end());
        u_mii memo;
        return recursion(0, n, jobs, 0, memo);
    }
};

int main(){

return 0;
}