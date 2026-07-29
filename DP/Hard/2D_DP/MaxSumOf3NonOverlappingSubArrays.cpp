#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    void slidingWindow(int N,int k,vint &arr,vint &nums){
        int winSum=0;
        for(int i=0;i<k;i++) winSum+=nums[i];
        for(int i=0;i<N-k+1;i++){
            arr.push_back(winSum);
            winSum-=nums[i];
            winSum+=(i+k<N? nums[i+k]:0);
        }
    }
    int recursion(int i,int j,int k,int m,int n,vint &arr,vvint &dp){
        if(j==m) return 0;
        if(i>=n) return -1e6;
        if(dp[i][j]!=-1) return dp[i][j];
        int skip=recursion(i+1,j,k,m,n,arr,dp), take=-1e5;
        if(j<m) take=arr[i]+recursion(i+k,j+1,k,m,n,arr,dp);
        return dp[i][j]=max(skip,take);
    }
public:
    vector<int> maxSumOfThreeSubarrays(vint &nums, int k) {
        int N=nums.size(), m=3;
        vint arr;
        slidingWindow(N,k,arr,nums);

        int n=N-k+1;
        vvint dp(n,vint(m,-1));
        recursion(0,0,k,m,n,arr,dp);

        vint result;
        int i=0, j=0;
        while(i<n && j<m){
            int takeVal=arr[i]+recursion(i+k,j+1,k,m,n,arr,dp);
            int skipVal=recursion(i+1,j,k,m,n,arr,dp);
            if(takeVal>=skipVal){
                result.push_back(i);
                i=i+k;
                j++;
            } 
            else i++;
        }
        return result;
    }
};

int main(){

return 0;
}