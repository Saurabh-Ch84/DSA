#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    int recursion(vector<int> &arr,int n,int k,int idx,vector<int> &dp){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int maxi=INT_MIN,maxe=INT_MIN;
        for(int j=idx;j<min(n,idx+k);j++)
        {
            maxe=max(maxe,arr[j]);
            int tempMaxi=maxe*(j-idx+1)+recursion(arr,n,k,j+1,dp);
            maxi=max(maxi,tempMaxi);
        }
        return dp[idx]=maxi;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k){
        int n=arr.size();
        vector<int> dp(n,-1);
        return recursion(arr,n,k,0,dp);
    }
};

int main(){

return 0;
}