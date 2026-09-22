#include<bits/stdc++.h>
using namespace std;

class Solution {
    int inf=1e7;
    vector<vector<int>> dp;
    int recursion(int i,int k,int n,vector<pair<int,int>> &subarrays,vector<int> &nextIdx){
        if(!k) return 0;
        if(i==n) return inf;
        if(dp[i][k]!=-1) return dp[i][k];
        int skip=recursion(i+1,k,n,subarrays,nextIdx);
        int j=nextIdx[i];
        int take=subarrays[i].second+recursion(j,k-1,n,subarrays,nextIdx);
        return dp[i][k]=min(skip,take);
    }
    int customBinarySearch(vector<pair<int,int>> &subarrays,int low,int high,int x){
        int ans=high+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(subarrays[mid].first>x){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    int findBestAnswer(vector<pair<int,int>> &subarrays){
        int n=subarrays.size();
        vector<int> nextIdx(n,n);
        for(int i=0;i<n;i++){
            int right=subarrays[i].first+subarrays[i].second-1;
            int idx=customBinarySearch(subarrays,i+1,n-1,right);
            nextIdx[i]=idx;
        }
        dp.resize(n+1,vector<int>(2+1,-1));
        int minSumOfNonOverlappingIntervals=recursion(0,2,n,subarrays,nextIdx);
        return (minSumOfNonOverlappingIntervals>=inf? -1: minSumOfNonOverlappingIntervals);
    }
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size(), left=0, right=0, sum=0;
        vector<pair<int,int>> subarrays;
        while(right<n){
            sum=sum+arr[right];
            while(sum>target && left<right){
                sum-=arr[left];
                left++;
            }
            if(sum==target){
                int sz=right-left+1;
                subarrays.push_back({left,sz});
            }
            right++;
        }
        sort(subarrays.begin(),subarrays.end());
        return findBestAnswer(subarrays);
    }
};

int main(){

return 0;
}